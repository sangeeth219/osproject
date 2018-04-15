#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
struct process
{
    int pid;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int tat;
}pro[20];
int prime;
void arrivalTimeSort(int n)
{    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(pro[j].arrivalTime<pro[i].arrivalTime)
            {
                int temp = pro[j].arrivalTime;
                pro[j].arrivalTime = pro[i].arrivalTime;
                pro[i].arrivalTime = temp;
                
                temp = pro[j].burstTime;
                pro[j].burstTime = pro[i].burstTime;
                pro[i].burstTime = temp;
                
                temp = pro[j].pid;
                pro[j].pid = pro[i].pid;
                pro[i].pid = temp;
            }
        }
    }
}
int maxBurst(int n)
{     int max=0,i,j;
    for(i=0;i<n;i++)
        {
                for(j=0;j<n;j++)
                    {
                            if(pro[j].burstTime>pro[i].burstTime)
                            max=pro[j].burstTime;
                    }
        }
        return max;
}
int completionTime(int n)
{
    int t=0,i;
    for(i=0;i<n;i++)
        t=t+pro[i].burstTime;
    return t;
}
void performScheduling(int n)
{
    int maxBurstTime=0;
    int k[3],i,j;
    k[0]=3;
    k[1]=6;
    printf("\nGantt Chart:---------\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<n;j++)
        {   maxBurstTime=maxBurst(n);
            int TimeReq=completionTime(n);
            if(i==2)
            k[i]=maxBurstTime;
            if(TimeReq>0)
            {
                if(pro[j].burstTime>0)
                {
                    pro[j].burstTime=pro[j].burstTime-k[i];
                }
                else
                {
                    pro[j].burstTime=0;
                }
            }
            printf("P[%d]-->", pro[j].pid);
        }
    }
    
}
void primefun()
{
    int i, j;
    for (i=2;i<=prime;i++){
        for (j=2;j<=i;j++){
            if (i%j==0){
                break;
            }
        }
        if (i==j)
            printf("\n%d",j);
    }
}
int main()
{
    int n,i;
    printf("No of processes:");
    scanf("%d", &n);
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the arrival time for p[%d]", i+1);
        scanf("%d", &pro[i].arrivalTime);
        printf("\nEnter the burst time for p[%d]", i+1);
        scanf("%d", &pro[i].burstTime);
        pro[i].pid = i+1;
    }
    
    arrivalTimeSort(n);
    performScheduling(n);
    
    printf("________________________________________________________________");
    printf("PRIME NUMBERS:");
    pthread_t t1;
    printf("ENter the number:");
    scanf("%d", &prime);
    pthread_create(&t1, NULL, primefun, NULL);
    pthread_join(t1, NULL);

}

