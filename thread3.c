#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

int balance = 1000;
sem_t s1,s2;
int count =0;

void *reader(void *p)
{
    int id = *(int*)p;
    sem_wait(&s1);
    count++;
    if(count ==1)
    {
        sem_wait(&s2);
    }
    sem_post(&s1);
    printf("the reader%d balance=%d\n",id,balance);
    sem_wait(&s1);
    count--;
    if(count ==0)
    {
        sem_post(&s2);
    }
    sem_post(&s1);
}

void *credit(void *p)
{
    int id = *(int*)p;
    sem_wait(&s2);
    balance = balance + 10;
    printf("the writer %d balance=%d\n",id,balance);
    sem_post(&s2);
}

void *debit(void *p)
{
    int id = *(int*)p;
    sem_wait(&s2);
    balance = balance - 10;
    printf("the writer %d balance=%d\n",id,balance);
    sem_post(&s2);
}

int main()
{
    sem_init(&s1,0,1);
    sem_init(&s2,0,1);

    int r_index[5] = {1,2,3,4,5};
    pthread_t rt[5],wt[5];

    for(int i=0;i<5;i++)
    {
        pthread_create(&rt[i],NULL,reader,(void*)&r_index[i]);
    }

    for(int i=0;i<5;i++)
    {
        if(i%2==0)
        {
            pthread_create(&wt[i],NULL,credit,(void*)&r_index[i]);
        }
        else{
            pthread_create(&wt[i],NULL,debit,(void*)&r_index[i]);
        }
    }

    for(int i=0;i<5;i++)
    {
        pthread_join(rt[i],NULL);
    }

    for(int i=0;i<5;i++)
    {
        pthread_join(wt[i],NULL);
    }
    sem_destroy(&s1);
    sem_destroy(&s2);
    printf("In main, Balance= %d\n",balance);
    return 0;

}