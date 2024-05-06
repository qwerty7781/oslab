#include<stdio.h>
struct p
{
    int pid;
    int bt;
    int tat;
    int wt;
    int pri;
};

void main(){
    struct p a[10];
    int n;
    float atat,awt;
    printf("Enter the total number of processes:");
    scanf("%d",&n);
    printf("Enter the process id:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].pid);
    }
    printf("Enter the burst time of each process:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].bt);
    }
    printf("Enter the priority of each process:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].pri);
    }
    struct p temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].pri>a[j+1].pri){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int ct=0;
    for(int i=0;i<n;i++){
        a[i].tat=ct+a[i].bt;
        ct=a[i].tat;
    }
     
    for(int i=0;i<n;i++){
        a[i].wt=a[i].tat-a[i].bt;
     }
    printf("Process ID\tBurst Time\tPriority\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t%d\n",a[i].pid,a[i].bt,a[i].pri,a[i].tat,a[i].wt);
    }

     for(int i=0;i<n;i++){
        atat=atat+a[i].tat;
        awt=awt+a[i].wt;
     }
     printf("The average Turn Around Time is:%f\n",atat/n);
     printf("The average Waiting Time is:%f",awt/n);
}

