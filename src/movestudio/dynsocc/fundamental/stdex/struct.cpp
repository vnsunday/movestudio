#include <stdlib.h>
#include <string>
#include <vector>
#include "struct.hpp"


using namespace dynsocc;
using namespace std;
int  test_dvqueue::test()
{
    printf("Test dvqueue:\r\n");
    int test_data = 0;
    int n_test_idx = 0;
    int n_test_exe = 0;
    int arr_test_count[10];
    int arr_test_pass[10];

    /*
     * Case1. Enqueue & dequeue
     * Case2. Enqueue & dequeue many times (=5*max_queue)
     * Case3. (Boundary case) Dequeue the empty
     * Case4. (Boundary case) Enqueue more than max_queue
     */
	const int MAX_QUEUE = 1000;
    struct dvqueue<int> mq(MAX_QUEUE);

    // Case 1
    int arr_test[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i=0;i<10;++i)
    {
        mq.enqueue(arr_test[i]);
    }

    // Test record
    n_test_idx=0;
    arr_test_count[n_test_idx] = 0;
    arr_test_pass[n_test_idx] = 0;
    for (int i=0;i<10;++i)
    {
        int na;
        int res = mq.dequeue(na);

        arr_test_count[n_test_idx]++;

        // expected
        if (res == 0 && na==arr_test[i])
        {
            arr_test_pass[n_test_idx]++;
        }
    }

    // Case 2
    mq.clear_queue();

    n_test_idx++;
    int nRes = 0;
    int nPart1_5 = MAX_QUEUE/5;
    int nPart4_5 = MAX_QUEUE - nPart1_5;
    int nVal;

    arr_test_count[n_test_idx] = 0;
    arr_test_pass[n_test_idx] = 0;

    for (int i=0;i<MAX_QUEUE;++i)
    {
        nRes = mq.enqueue(1);
        arr_test_count[n_test_idx]++;
        if (nRes==0)
        {
            arr_test_pass[n_test_idx]++;
        }
    }

    for (int i=1;i<=4;++i)
    {
        for (int j=0;j<nPart4_5;++j)
        {
            nRes = mq.dequeue(nVal);
            arr_test_count[n_test_idx]++;
            if (nRes==0)    // Success
            {
                arr_test_pass[n_test_idx]++;
            }
        }

        for (int j=0;j<nPart4_5;++j)
        {
            nRes = mq.enqueue(1);

            arr_test_count[n_test_idx]++;
            if (nRes==0)
            {
                arr_test_pass[n_test_idx]++;
            }
        }
    }
    // This queue is full now, Try to add more
    nRes = mq.enqueue(1);
    arr_test_count[n_test_idx]++;
    if (nRes != 0) // Got error -> Ok
    {
        arr_test_pass[n_test_idx]++;
    }

    // Case 3
    mq.clear_queue();
    n_test_idx++;
    nRes = mq.dequeue(nVal);
    arr_test_count[n_test_idx] = 0;
    arr_test_pass[n_test_idx] = 0;
    arr_test_count[n_test_idx]++;
    if (nRes != 0)
    {
        // Return Error => OK
        arr_test_pass[n_test_idx]++;
    }

    // Case 4
    mq.clear_queue();
    n_test_idx++;

    arr_test_count[n_test_idx] = 0;
    arr_test_pass[n_test_idx] = 0;

    for (int i=0;i<MAX_QUEUE;++i)
    {
        arr_test_count[n_test_idx]++;
        nRes = mq.enqueue(1);

        if (nRes == 0)
        {
            arr_test_pass[n_test_idx]++;
        }
    }
    // The queue is full now, try to add more
    nRes = mq.enqueue(1);   

    arr_test_count[n_test_idx]++;
    if (nRes != 0)
    {
        // Ok to show an error
        arr_test_pass[n_test_idx]++;
    }

    // Summary 
    for (int i=0;i<=n_test_idx;++i)
    {
        bool bCompleteSuccess = arr_test_count[i] == arr_test_pass[i];
        string str_success = bCompleteSuccess? "Success" : "HasError";

        printf("Test Case %d: %s Pass/Total=%d/%d\r\n", (i+1), str_success.c_str(), arr_test_pass[i], arr_test_count[i]);
    }

    printf("Finish\r\n");
    return 0;
}