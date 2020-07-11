#include<pthread.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#define NUMCPUS 2

typedef struct counter_t {
    int global;
    pthread_mutex_t glock;

    int local[NUMCPUS];
    pthread_mutex_t llock[NUMCPUS];
    int threshold;
}counter_t;

typedef struct myargs_t{
    int threadID;
    int counter;
}myargs_t;

counter_t c;

void init(counter_t *c,int threshold){//初始化
    c->threshold=threshold;
    c->global=0;
    pthread_mutex_init(&c->glock,NULL);

    int i;
    for(i=0;i<NUMCPUS;++i){
        c->local[NUMCPUS]=0;
        pthread_mutex_init(&c->llock[i],NULL);
    }
}

void destroy(counter_t *c){
    pthread_mutex_destroy(&c->glock);
    int i=0;
    for(;i<NUMCPUS;++i)
        pthread_mutex_destroy(&c->llock[i]);
}

void update(counter_t*c,int threadID,int amt){//更新局部计数器
    pthread_mutex_lock(&c->llock[threadID]);
    c->local[threadID]+=amt;
    if(c->local[threadID]>=c->threshold){
        pthread_mutex_lock(&c->glock);
        c->global+=c->local[threadID];
        pthread_mutex_unlock(&c->glock);
        c->local[threadID]=0;
    }
    pthread_mutex_unlock(&c->llock[threadID]);
}

int get(counter_t*c){
   	pthread_mutex_lock(&c->glock);
	int rc=c->global;
	pthread_mutex_unlock(&c->glock);
	return rc;
}

void *mythread(void*args){
    myargs_t* p=(myargs_t*)args;
    int i=0;
    for(;i<p->counter;++i){
        update(&c,p->threadID,1);
	//	printf("thread %d:now counter==%d\n",p->threadID,get(&c));
    }
    return NULL;
}

int main(int argc,char**argv)
{
    if(argc!=3){
        printf("Usage:program_name [counter] [threshold]\n");
        return 0;
    }
    init(&c,atoi(argv[2]));
    pthread_t p1,p2;
    myargs_t p1_args,p2_args;
    p1_args.counter=p2_args.counter=atoi(argv[1]);
    p1_args.threadID=0;
    p2_args.threadID=1;

    pthread_create(&p1,NULL,mythread,(void*)&p1_args);
    pthread_create(&p2,NULL,mythread,(void*)&p2_args);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("result:%d\n",get(&c));

    destroy(&c);
    return 0;
}
