#include<pthread.h>
#include<stdio.h>
 int balance = 1000;

 void *reader(void *p)
 {
    int id = *(int*)p;
    printf("The Reader%d Balance=%d\n",id,balance);
 }

 void *credit(void *p)
 {
    int id = *(int*)p;
    balance = balance + 10;
    printf("The Writer%d Balance=%d\n",id,balance);   
 }

 void *debit (void *p)
 {
    int id = *(int*)p;
    balance = balance - 10;
    printf("The Writer%d Balance=%d\n",id,balance);
 }

 int main()
 {
    int r_index[5] = {1,2,3,4,5};
    pthread_t rt[5],wt[5];

    for(int i=0;i<5;i++)
    {
        pthread_create(&rt[i],NULL,reader,(void*)&r_index[i]);
    }

    for(int i=0;i<5;i++)
    {
        if(i%2 == 0)
        {
            pthread_create(&wt[i],NULL,credit,(void*)&r_index[i]);
        }
        else
        {
            pthread_create(&wt[i],NULL,debit,(void*)&r_index[i]);
        }
    }
    printf("\n");
    for(int i=0;i<5;i++)
    {
        pthread_join(rt[i],NULL);
    }
    for(int i=0;i<5;i++)
    {
        pthread_join(wt[i],NULL);
    }
    printf("\nIn Main,Balance = %d",balance);
    return 0;
 }