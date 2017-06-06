#include <iostream>
#include "memorylog.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void* thread_function(void* arg)
{
    arg = arg;
    int *pint = (int *)arg;
    char name[64];
    sprintf(name, "pthread %d", *pint);
//    string name("pthread " + (int)*arg);
    int i = 0;
    while(1){
        pushlogbyname(name, "i am comming!!:%d", i++);
#ifdef __WIN32_
        Sleep(2000);
#else

#endif
        showmlogbyname(name);
    }
    return NULL;
}


int main()
{
    mloghelp();
    cout << "Hello World!" << endl;
    char buf[4];
    memset(buf, 0xFE, sizeof(buf));
    pushmsgbyname("msg", buf, sizeof(buf), "test one buf memory log");
    pushmsgbyname("msgsdfdfdsfdsfdfd", buf, sizeof(buf), "test one buf memory log");
    char buf2[5];
    pushmsgbyname("msg2", buf2, sizeof(buf2), "test one buf memory log2");
    char buf3[6];
    pushmsgbyname("msg3", buf3, sizeof(buf3), "test one buf memory log3");
    char buf4[7];
    pushmsgbyname("msg4", buf4, sizeof(buf4), "test one buf memory log4");
    char buf5[8];
    pushmsgbyname("msg5", buf5, sizeof(buf5), "test one buf memory log5");
    char buf6[9];
    pushmsgbyname("msg6", buf6, sizeof(buf6), "test one buf memory log6");
    char buf7[90];
    pushmsgbyname("msg7", buf7, sizeof(buf7), "test one buf memory log7");
    char buf8[900];
    pushmsgbyname("msg8", buf8, sizeof(buf8), "test one buf memory log8");
    char buf9[9000];
    pushmsgbyname("msg9", buf9, sizeof(buf9), "test one buf memory log9");
    char buf10[90000];
    pushmsgbyname("msg10", buf10, sizeof(buf10), "test one buf memory log10");
    char buf11[900000];
    pushmsgbyname("msg11", buf11, sizeof(buf11), "test one buf memory log11");
    char *buf12 = new char[9000000];
    pushmsgbyname("msg12", buf12, 9000000, "test one buf memory log12");
    pushmsgbyname("msg12", buf12, 9000000, "test one buf memory log12");
    pushmsgbyname("msg12", buf12, 9000000, "test one buf memory log12");
    pushmsgbyname("msg12", buf12, 9000000, "test one buf memory log12");
    delete [] buf12;
    savemlog2fileall("agent.mlog");
#ifdef __WIN32__
    savemlog2fileall("./tmp/agent.mlog");
    savemlog2filebyname("msg5", "./tmp/msg5.mlog");
#else
    savemlog2fileall("/tmp/agent.mlog");
    savemlog2filebyname("msg5", "/tmp/msg5.mlog");
#endif
    showmlogkeys();

    return 1;

    pushlogbyname("init", "haha");
    showmlogbyname("init");
    showmlogall();

    set_mlogmaxsize(3000);

    pushlogbyname("error", "index:%d", 1);
    pushlogbyname("error", "index:%d", 2);
    pushlogbyname("error", "index:%d", 3);
    showmlogbyname("error");


    int i = 0;
    for( i = 0 ; i < 1000000; i++ )
    {
        pushlogbyname("sums", "sum is:%d", i * 1000 );

    }

    showmlogall();
    showmlogkeys();
    savemlog2filebyname("error", "/tmp/error.mlog");
    savemlog2fileall("errorinfo.mlog");
    savemlog2filekeys();

    showmlogall();
    clearmlogbyname("error");
    showmlogall();
    clearmlogall();
    clearmlogbyname("init");
    showmlogall();
    showmlogall();

    return 1;

    pthread_t thread_id;
    pthread_t thread_id2;
    pthread_attr_t attr;
    pthread_attr_t attr2;
    pthread_attr_init(&attr);
    pthread_attr_init(&attr2);
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    int seq = 1;
    pthread_create(&thread_id,&attr,&thread_function,&seq);
    int seq2 = 2;
    pthread_create(&thread_id2,&attr2,&thread_function,&seq2);
    pthread_attr_destroy(&attr);
    pthread_attr_destroy(&attr2);

    while(1){

	#ifdef __WIN32__
        Sleep(1000);
	#else

	#endif
	}

    return 0;
}
