/* Test suite for the tracker indexer */

#include <unistd.h>

#include "tracker-indexer.h"
#include "tracker-utils.h"

Tracker	*tracker;

static char *words[] = {"word1", "word2", "word3", "word4", "word5", "word6", NULL};
static char *words_123[] = {"word1", "word2", "word3", NULL};
static char *words_12[] = {"word1", "word2", NULL};
static char *words_56[] = {"word5", "word6", NULL};

static char *words1[] = {"word1", NULL};
static char *words2[] = {"word2", NULL};
static char *words3[] = {"word3", NULL};
static char *words4[] = {"word4", NULL};
static char *words5[] = {"word5", NULL};
static char *words6[] = {"word6", NULL};

static Indexer *file_indexer;
static int fail_count;
static GTimeVal *tv;

static GSList *
do_search (char** wordarray, int offset, int limit)
{
	GSList *list;
	int i;

	char *st = g_strjoinv (", ", wordarray); 

	g_message ("CHECKING: search for %s with offset %d and limit %d", st, offset, limit);

	tv = tracker_timer_start ();
	list = tracker_indexer_get_hits (file_indexer, wordarray, 0, 5, offset, limit, TRUE, &i);
	tracker_timer_end (tv, "word search took ");

	g_message ("%d search results returned from %d ", g_slist_length (list), i);	

	GSList *l;
	for (l=list; l; l=l->next) {
		SearchHit *hit = l->data;
		g_message ("hit for %d with score %d", hit->service_id, hit->score);
		
	}


	return list;
}


static void
check_list (GSList *list, int pos, int sid, int score)
{
	GSList *l;

	if (pos > -1) {
		l = g_slist_nth (list, pos);

		if (!l) {
			fail_count++;
			g_message ("FAIL : list position %d is not available", pos);
			return;
		}

		SearchHit *hit = l->data;

		if (sid > 0 && sid != hit->service_id) {
			fail_count++;
			g_message ("FAIL : expected service id %d not found at position %d (%d was found instead)", sid, pos, hit->service_id);
			return;
		}

		if (score > 0 && score != hit->score) {
			fail_count++;
			g_message ("FAIL : expected score %d for service id %d is the worng value (%d was found instead)", score, sid, hit->score);
			return;
		}
	} else {
		
		for (l=list; l; l=l->next) {
			SearchHit *hit = l->data;
	
			if (hit->service_id == sid ) {
				g_message ("FAIL : service id %d was not expected in list", sid);	
			}
		}

		
		

	}

	g_message ("SUCESS : expected value %d found in correct place %d in list with score %d", sid, pos, score);
	

}

static void
check_count (GSList *list, int count)
{
	int c = g_slist_length (list);

	if (c != count) {
		fail_count++;
		g_message ("FAIL : expected list count of %d is different from actual count of %d", count,c);
		return;
	}

	g_message ("PASS : count check okay on result");

}

static void
load_data ()
{
	int a;

	for (a = 1; a<11; a++) {

		if (!tracker_indexer_append_word (file_indexer, "word1", a, 1, a)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word1", a+10, 1, a+10)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word1", a+20, 2, a+20)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word1", a+30, 3, a+30)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word1", a+40, 4, a+40)) g_message ("ERROR - could not add word") ;

		if (!tracker_indexer_append_word (file_indexer, "word2", a, 1, a+30)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word2", a+10, 1, a+200)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word2", a+20, 2, a+10)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word2", a+30, 3, a)) g_message ("ERROR - could not add word") ;

		if (!tracker_indexer_append_word (file_indexer, "word3", a, 1, 4)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word3", a+10, 1, 200)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word3", a+30, 3, 1)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word3", a+40, 4, 5)) g_message ("ERROR - could not add word") ;

		if (!tracker_indexer_append_word (file_indexer, "word4", a, 1, 12)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word4", a+10, 1, 200)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word4", a+20, 2, 10)) g_message ("ERROR - could not add word") ;
		if (!tracker_indexer_append_word (file_indexer, "word4", a+40, 4, 5)) g_message ("ERROR - could not add word") ;

		
	}

	for (a = 1; a<10000; a++) {
		if (!tracker_indexer_append_word (file_indexer, "word5", a, 1, 11)) g_message ("ERROR - could not add word") ;
	}

	for (a = 1; a<10000; a++) {
		if (!tracker_indexer_append_word (file_indexer, "word6", a, 1, 1)) g_message ("ERROR - could not add word") ;
	}

	
}



static void
do_updates_check ()
{
	g_message ("\n\nStarting update checks\n\n");

	GSList *l;

	l = do_search (words1,  0, 10);

	/* check and manipulate a value in the middle of the list */

	g_message ("\n\nUPDATING: middle value 5's score by +100");
	tracker_indexer_update_word (file_indexer, "word1", 5, 1,  100, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, 0, 5, 105);

	g_message ("\n\nUPDATING: middle value 5's score by -100");
	tracker_indexer_update_word (file_indexer, "word1", 5, 1, -100, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, 5, 5, 5);

	g_message ("\n\nUPDATING: middle value 5's score by -5 ");
	tracker_indexer_update_word (file_indexer, "word1", 5, 1, -5, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, -1, 5, 0);

	g_message ("\n\nUPDATING: middle value 5's score by 5 ");
	tracker_indexer_update_word (file_indexer, "word1", 5, 1, 5, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, 5, 5, 5);


	/* check and manipulate the first value in the list */
	g_message ("\n\nUPDATING: first value 1's score by +100");
	tracker_indexer_update_word (file_indexer, "word1", 1, 1, 100, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, 0, 1, 101);

	g_message ("\n\nUPDATING: first value 1's score by -100");
	tracker_indexer_update_word (file_indexer, "word1", 1,  1, -100, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, 9, 1, 1);

	g_message ("\n\nUPDATING: first value 1's score by -1 ");
	tracker_indexer_update_word (file_indexer, "word1", 1, 1, -1, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, -1, 1, 0);
	
	g_message ("\n\nUPDATING: first value 1's score by +1");
	tracker_indexer_update_word (file_indexer, "word1", 1, 1, +1, FALSE);
	l = do_search (words1,  40, 10);
	check_list (l, 9, 1, 1);



	/* check and manipulate the last value in the list */
	g_message ("\n\nUPDATING: last value 50's score by +100");
	tracker_indexer_update_word (file_indexer, "word1", 50, 1, 100, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, 0, 50, 150);

	g_message ("\n\nUPDATING: last value 50's score by -100");
	tracker_indexer_update_word (file_indexer, "word1", 50,  1, -100, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, 0, 50, 50);

	g_message ("\n\nUPDATING: last value 50's score by -1 ");
	tracker_indexer_update_word (file_indexer, "word1", 50, 1, -50, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, -1, 50, 0);
	
	g_message ("\n\nUPDATING: last value 50's score by +1");
	tracker_indexer_update_word (file_indexer, "word1", 50, 1, +50, FALSE);
	l = do_search (words1,  0, 10);
	check_list (l, 0, 50, 50);


	/* test explicit word removal */
	g_message ("\n\nRemoving first value");
	tracker_indexer_update_word (file_indexer, "word1", 1,  1, 1, TRUE);
	l = do_search (words1,  40, 10);
	check_list (l, -1, 1, 1);

	g_message ("\n\nRemoving 5 value");
	tracker_indexer_update_word (file_indexer, "word1", 5,  1, -1, TRUE);
	l = do_search (words1,  40, 10);
	check_list (l, -1, 5, 2);

	g_message ("\n\nRemoving last value");
	tracker_indexer_update_word (file_indexer, "word1", 50,  1, 0, TRUE);
	l = do_search (words1,  0, 10);
	check_list (l, -1, 50, 3);

}


static void
do_search_checks ()
{
	g_message ("\n\nStarting search checks\n\n");

	GSList *l;

	l = do_search (words1,  0, 100);
	check_count (l, 50);
	l = do_search (words1,  0, 10);
	check_count (l, 10);
	l = do_search (words1, 10, 10);
	check_count (l, 10);
	l = do_search (words1, 20, 10);
	check_count (l, 10);
	l = do_search (words1, 45, 10);
	check_count (l, 5);
	l = do_search (words1, 49, 10);
	check_count (l, 1);
	l = do_search (words1, 50, 10);
	check_count (l, 0);
	l = do_search (words1, 51, 10);
	check_count (l, 0);

	g_message ("\n\nTesting multiple word retrievals...\n\n");

	l = do_search (words_12, 0, 100);
	check_count (l, 40);
	l = do_search (words_123, 0, 100);
	check_count (l, 30);
	l = do_search (words_56, 0, 100);
	check_count (l, 100);
	l = do_search (words, 0, 100);
	check_count (l, 20);

	/* testing offset and limit */
	l = do_search (words, 0, 5);
	check_count (l, 5);
	l = do_search (words, 5, 5);
	check_count (l, 5);
	l = do_search (words, 10, 5);
	check_count (l, 5);
	l = do_search (words, 15, 5);
	check_count (l, 5);
	l = do_search (words, 20, 5);
	check_count (l, 0);
	l = do_search (words, 19, 1);
	check_count (l, 1);
	l = do_search (words, 21, 5);
	check_count (l, 0);






}





int
main (int argc, char **argv)
{
	int a;
	char *test_db;

	tracker = g_new (Tracker, 1);

	tracker->verbosity = -1;

	if (!g_thread_supported ()) {
		g_thread_init (NULL);
	}

	test_db = g_build_filename (g_get_home_dir(), ".Tracker", "databases", "test", NULL);


	tracker_remove_dirs (test_db);

	file_indexer = tracker_indexer_open ("test");

	fail_count = 0;
	
	/* do update/delete test */

	load_data ();

	do_updates_check ();

	tracker_indexer_close (file_indexer);	

	
	tracker_remove_dirs (test_db);

	file_indexer = tracker_indexer_open ("test");

	load_data ();

	//do_search_checks ();

	tracker_indexer_close (file_indexer);	

	
	tracker_remove_dirs (test_db);
		
	g_free(test_db);
	g_free(tracker);

	if (fail_count == 0) {
		g_message ("\n\n\nSUCESS : Test passed all results :))))");
	} else {
		g_message ("\n\n\nFAILURE : test failed %d times", fail_count);
		return EXIT_FAILURE;

	}

	return EXIT_SUCCESS;
}
