#include<stdio.h>
void main(){
    int p[10],bt[10],n;
    float atat=0,awt=0;
    printf("Enter the total number of processes:");
    scanf("%d",&n);
    printf("Enter the process id of each process:");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time of each process:");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    int tat[10];
    int wt[10];
     tat[-1]=0;
     for(int i=0;i<n;i++){
        tat[i]=tat[i-1]+bt[i];
     }
     for(int i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
     }
    printf("Process ID\tBurst Time\tTAT\t\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],tat[i],wt[i]);
    }

     for(int i=0;i<n;i++){
        atat=atat+tat[i];
        awt=awt+wt[i];
     }
     printf("The average Turn Around Time is:%f\n",atat/n);
     printf("The average Waiting Time is %f:",awt/n);
}