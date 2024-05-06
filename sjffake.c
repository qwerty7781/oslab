#include<stdio.h>
struct p{
    int pid;
    int bt;
    int wt;
    int tat;
};
void main(){
    struct p a[10];
    int n;
    float atat=0,awt=0;
    printf("Enter the total number of processes:");
    scanf("%d",&n);
    printf("Enter the pid:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].pid);
    }
    printf("Enter the bt of each process:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].bt);
    }
    struct p temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].bt>a[j+1].bt){
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
    printf("Process ID\tBurst Time\tTAT\t\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",a[i].pid,a[i].bt,a[i].tat,a[i].wt);
    }

     for(int i=0;i<n;i++){
        atat=atat+a[i].tat;
        awt=awt+a[i].wt;
     }
     printf("The average Turn Around Time is:%f\n",atat/n);
     printf("The average Waiting Time is:%f",awt/n);
}

