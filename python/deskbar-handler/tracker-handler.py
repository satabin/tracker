# -*- coding: utf-8 -*-
#    This handler was originaly created by Mikkel Kamstrup (c) 2006 and updated by Eugenio Cutolo (eulin)
#
#    This program can be distributed under the terms of the GNU GPL version 2 or later.
#    See the file COPYING.
#

# Notes on URL escaping and quoting:
#  * Fields displayed in the deskbar applet should be escaped
#  * There _MUST_ be an unescaped 'uri' field in order to open it
#    (see also 'escqped_uri' - this URI however should urllib quoted
#                 - Marcus Fritzsch, fritschy@googlemail.com, 2007-08-13

import re
import cgi
import sys
import os.path
import time
import urllib
import gnome
import gobject

import gettext
gettext.install('tracker')

import deskbar, deskbar.Utils, deskbar.gnomedesktop
import deskbar.Handler
import deskbar.Match

# For now description param it's not used
TYPES = {
	'Applications': {
		'description': (_('Launch %s (%s)') % ('<b>%(name)s</b>', '%(app_name)s')),
		'category': 'actions',
		#'icon': 'stock_run',
	},

	'GaimConversations': {
		'description': (_('See %s conversation\n%s %s\nfrom %s') % ('<b>%(proto)s</b>', '%(channel)s', '<b>%(conv_to)s</b>', '<i>%(time)s</i>')),
		'category': 'conversations',
		'icon': 'stock_people',
	},

	'Emails': {
		'description': (_('Email from %s') % '<i>%(publisher)s</i>' ) + '\n<b>%(title)s</b>',
		'category': 'emails',
		'action': 'evolution %(uri)s',
		'icon': 'stock_mail',
	},

	'Music': {
		'description': _('Listen to music %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'music',
		#'icon': 'audio',
	},

	'Documents': {
		'description': _('See document %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'documents',
		#'icon': 'file',
	},

	'Development': {
		'description': _('Open file %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'develop',
		#'icon': 'file',
	},

	'Images': {
		'description': _('View image %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'images',
		'icon': 'image',
	},

	'Videos': {
		'description': _('Watch video  %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'videos',
		'icon': 'video',
	},

	'Files': {
		'description': _('Open file %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>'),
		'category': 'files',
		#'icon': 'file',
	},

	'Folders': {
		'description': _('Open folder %s\n%s') % ('<b>%(name)s</b>', '<i>%(dir)s/%(name)s</i>'),
		'category': 'places',
		'icon': 'stock_folder',
	},

	'Extra': {
		'description': _('Search for %s with Tracker Search Tool') % ('<b>%(name)s</b>'),
	},
}




class TrackerSearchToolMatch (deskbar.Match.Match):

	def __init__(self, backend, **args):
		deskbar.Match.Match.__init__(self, backend, **args)
		self._icon = deskbar.Utils.load_icon ('tracker')

	def action(self, text=None):
		gobject.spawn_async(['tracker-search-tool', self.name], flags=gobject.SPAWN_SEARCH_PATH)

	def get_verb(self):
		return TYPES['Extra']['description'] % { 'name': self.name }

	def get_category (self):
		return 'actions'

	def get_hash (self, text=None):
		return 'tst-more-hits-action-'+self.name




class TrackerSearchToolHandler(deskbar.Handler.Handler):

	def __init__(self):
		deskbar.Handler.Handler.__init__(self, 'tracker')

	def query(self, query):
		return [TrackerSearchToolMatch(self, name=query)]

	@staticmethod
	def requirements ():
		if deskbar.Utils.is_program_in_path ('tracker-search-tool'):
			return (deskbar.Handler.HANDLER_IS_HAPPY, None, None)
		return (deskbar.Handler.HANDLER_IS_NOT_APPLICABLE, 'tracker-search-tool not found', None)




class TrackerLiveSearchMatch (deskbar.Match.Match):

	def __init__(self, handler,result=None, **args):
		deskbar.Match.Match.__init__ (self, handler,name=result['name'], **args)
		self.result = result
		self.init_names(result['escaped_uri'])

		# Set the match icon
		try:
			self._icon = deskbar.Utils.load_icon(TYPES[result['type']]['icon'])
		except:
			if self.result.has_key ('icon'):
				self._icon = deskbar.Utils.load_icon_for_desktop_icon (result ['icon'])
			else:
				self._icon = deskbar.Utils.load_icon_for_file(result['uri'])

	def get_name(self, text=None):
		return self.result

	def get_verb(self):
		try:
			return TYPES[self.result['type']]['description']
		except:
			return _('Open file %s\nin %s')	% ('<b>%(base)s</b>', '<i>%(dir)s</i>')

	def get_hash(self, text=None):
		if self.result ['type'] == 'Applications':
			# return a name that matches the one returned by the Program handler of deskbar
			return 'generic_' + self.result ['app_basename']
		return self.result['uri']

	def action(self, text=None):
		if TYPES[self.result['type']].has_key('action'):
			cmd = TYPES[self.result['type']]['action']
			cmd = map(lambda arg : arg % self.result, cmd.split()) # we need this to handle spaces correctly

			print 'Opening Tracker hit with command:', cmd
			try:
				# deskbar >= 2.17
				deskbar.Utils.spawn_async(cmd)
			except AttributeError:
				# deskbar <= 2.16
				gobject.spawn_async(args, flags=gobject.SPAWN_SEARCH_PATH)
		else:
			if self.result.has_key ('desktop'):
				self.result['desktop'].launch([])
			else:
				try: # catch errors on gnome.url_show()
					try:
						# deskbar >= 2.17
						deskbar.Utils.url_show ('file://'+self.result['uri'])
					except AttributeError:
						gnome.url_show('file://'+self.result['uri'])
					print 'Opening Tracker hit:', self.result['uri']
				except:
					print >> sys.stderr, '*** Could not open URL %s: %s' % (self.result['uri'], sys.exc_info ()[1])

	def get_category (self):
		try:
			return TYPES[self.result['type']]['category']
		except:
			return 'files'

	def init_names (self, fullpath):
		dirname, filename = os.path.split(fullpath)
		if filename == '': #We had a trailing slash
			dirname, filename = os.path.split(dirname)

		#Reverse-tilde-expansion
		home = os.path.normpath(os.path.expanduser('~'))
		regexp = re.compile(r'^%s(/|$)' % re.escape(home))
		dirname = re.sub(regexp, r'~\1', dirname)

		self.result['base'] = filename
		self.result['dir'] = dirname




class TrackerLiveSearchHandler(deskbar.Handler.SignallingHandler):

	def __init__(self):
		deskbar.Handler.SignallingHandler.__init__(self, 'tracker')
		# initing on search request, see self.query
		self.tracker = self.search_iface = self.keywords_iface = self.files_iface = None
		self.set_delay (500)
		self.conv_re = re.compile (r'^.*?/logs/([^/]+)/([^/]+)/([^/]+)/(.+?)\.(:?txt|html)$') # all, proto, account, to-whom, time
		self.have_tst = deskbar.Utils.is_program_in_path ('tracker-search-tool')

	def handle_email_hits (self, info, output):
		output['title'] = cgi.escape(info[3])
		output['publisher'] = cgi.escape(info[4])

	def handle_conversation_hits (self, info, output):
		m = self.conv_re.match (output['escaped_uri'])
		output['channel']=_('with')
		output['proto']=output['conv_from']=output['conv_to']=output['time']='' # XXX, never happened during tests
		if m:
			output['proto'] = cgi.escape (m.group (1))
			output['conv_from'] = urllib.unquote (cgi.escape (m.group (2)))
			output['conv_to'] = urllib.unquote (cgi.escape (m.group (3)))
			output['time'] = cgi.escape (time_from_purple_log (m.group (4)))
		if output['conv_to'].endswith ('.chat'):
			output['channel'] = _('in channel')
			output['conv_to'] = output['conv_to'].replace ('.chat','')
		if output['proto'] == 'irc':
			nick_server = output['conv_from'].split ('@')
			if len (nick_server) > 1:
				output['conv_to'] = '%s on %s' % (output['conv_to'], nick_server[1])

	def handle_application_hits (self, info, output):
		# print info
		#   dbus.Array(
		#   [
		#     dbus.String(u'/usr/share/applications/gksu.desktop'), # TrackerUri  0
		#     dbus.String(u'Applications'),                         # TrackerType 1
		#     dbus.String(u'Application'),                          # DesktopType 2
		#     dbus.String(u'Root Terminal'),                        # DesktopName 3
		#     dbus.String(u'gksu /usr/bin/x-terminal-emulator'),    # DesktopExec 4
		#     dbus.String(u'gksu-root-terminal')                    # DesktopIcon 5
		#   ],
		#   signature=dbus.Signature('s'))
		# Strip %U or whatever arguments in Exec field
		output['app_name'] = re.sub(r'%\w+', '', info [4]).strip ()
		output['app_basename'] = cgi.escape (os.path.basename (output['app_name']))
		output['app_name'] = cgi.escape (output['app_name'])
		if output['app_basename'] == '': # strange // in app_name, e.g. nautilus burn:///
			output['app_basename'] = output['app_name']
		output['name'] = cgi.escape (info [3])
		output['icon'] = info [5] # no escaping, as it is not displayed as a string

		desktop = parse_desktop_file (output['uri'])
		if not desktop:
			print >> sys.stderr, '*** Could not read .desktop file: %s' % info[0]
		else:
			output['desktop'] = desktop

	def receive_hits (self, qstring, hits, max):
		matches = []

		for info in hits:
			output = {}

			info = [str (i) for i in info]

			output['escaped_uri'] = cgi.escape (info[0])
			output['uri'] = urllib.quote (info[0])
			output['name'] = os.path.basename(output['escaped_uri'])
			output['type'] = info[1]

			if not TYPES.has_key(output['type']):
				output['type'] = 'Files'

			if output['type'] == 'Emails':
				self.handle_email_hits (info, output)

			elif output['type'] in ('GaimConversations', 'Conversations'):
				self.handle_conversation_hits (info, output)

			elif output['type'] == 'Applications':
				self.handle_application_hits (info, output)

			# applications are launched by .desktop file, if not readable: exclude
			if output['type'] != 'Applications' or output.has_key ('desktop'):
				matches.append(TrackerLiveSearchMatch (self, output))

		if len (matches):
			self.emit_query_ready(qstring, matches)
			print 'Tracker response for query "%s" (service %s); %s hits returned, %s shown' % (qstring, hits[0][1], len(hits), len(matches))

	def recieve_error (self, error):
		print >> sys.stderr, '*** Tracker dbus error:', error

	def query (self, qstring, max):
		if self.tracker:
			try: self.tracker.GetStatus ()
			except: self.tracker = None # reconnect
		if not self.tracker:
			try:
				print "Connecting to Tracker (first search or trackerd restarted)"
				import dbus
				bus = dbus.SessionBus()
				self.tracker = bus.get_object('org.freedesktop.Tracker','/org/freedesktop/tracker')
				self.search_iface = dbus.Interface(self.tracker, 'org.freedesktop.Tracker.Search')
				self.keywords_iface = dbus.Interface(self.tracker, 'org.freedesktop.Tracker.Keywords')
				self.files_iface = dbus.Interface(self.tracker, 'org.freedesktop.Tracker.Files')
			except:
				print >> sys.stderr, '*** DBus connection to tracker failed, check your settings.'
				return
		for service in [key for key in TYPES.iterkeys () if key != 'Extra']:
			self.search_iface.TextDetailed (-1, service, qstring, 0, max, \
					reply_handler = lambda hits: self.receive_hits (qstring, hits, max), \
					error_handler = self.recieve_error)
		print 'Tracker query:', qstring
		if self.have_tst:
			# explicitly add one hit to search with t-s-t
			self.emit_query_ready (qstring, [TrackerSearchToolMatch (self, name=qstring)])

	@staticmethod
	def requirements ():
		try:
			import dbus
			try :
				if getattr(dbus, 'version', (0,0,0)) >= (0,41,0):
					import dbus.glib

				# Check that Tracker can be started via dbus activation, we will have trouble if it's not
				bus = dbus.SessionBus()
				proxy_obj = bus.get_object('org.freedesktop.DBus', '/org/freedesktop/DBus')
				dbus_iface = dbus.Interface(proxy_obj, 'org.freedesktop.DBus')
				activatables = dbus_iface.ListActivatableNames()
				if not 'org.freedesktop.Tracker' in activatables:
					return (deskbar.Handler.HANDLER_IS_NOT_APPLICABLE, 'Tracker is not activatable via dbus', None)
			except:
				return (deskbar.Handler.HANDLER_IS_NOT_APPLICABLE, 'Python dbus.glib bindings not found.', None)
			return (deskbar.Handler.HANDLER_IS_HAPPY, None, None)
		except:
			return (deskbar.Handler.HANDLER_IS_NOT_APPLICABLE, 'Python dbus bindings not found.', None)




# this code is stolen from the programs handler of deskbar
def parse_desktop_file(desktop, only_if_visible=False):
	try:
		desktop = deskbar.gnomedesktop.item_new_from_file(desktop, deskbar.gnomedesktop.LOAD_ONLY_IF_EXISTS)
	except Exception, e:
		print 'Couldn\'t read desktop file:%s:%s' % (desktop, e)
		return None
	if desktop == None or desktop.get_entry_type() != deskbar.gnomedesktop.TYPE_APPLICATION:
		return None
	if only_if_visible and desktop.get_boolean(deskbar.gnomedesktop.KEY_NO_DISPLAY):
		return None
	return desktop




def time_from_purple_log (instr):
	try:
		if instr.find ('+') != -1: # new kind of log timestamp...
			return time.strftime ('%c', time.strptime (re.sub (r'\+\d{4}', '', instr), '%Y-%m-%d.%H%M%S%Z'))
		else: # ...from ancient times
			return time.strftime ('%c', time.strptime (instr, '%Y-%m-%d.%H%M%S'))
	except:
		print >> sys.stderr, '*** time parsing for purple chat log failed: %s' % sys.exc_info ()[1]
	return instr




HANDLERS = {
	'TrackerSearchToolHandler': {
		'name': 'Search for files using Tracker Search Tool',
		'description': _('Search all of your documents with Tracker Search Tool'),
		#'requirements': TrackerSearchToolHandler.requirements, # XXX makes deskbar 2.18.1 not load the handler!!
	},

	'TrackerLiveSearchHandler': {
		'name': 'Search for files using Tracker',
		'description': _('Search all of your documents, <b>as you type</b>'),
		'requirements': TrackerLiveSearchHandler.requirements,
		'categories': {
			'develop': {
				'name': _('Development Files'),
			},
			'music': {
				'name': _('Music'),
			},
			'images': {
				'name': _('Images'),
			},
			'videos': {
				'name': _('Videos'),
			},
		},
	},
}