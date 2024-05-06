
#include<stdio.h>
struct p{
    int pid;
    int psize;
    int blk_no;
}a[10];
struct b{
    int b_no;
    int b_size;
    int allc;
}b[10];
void main(){
    int n,m;
    int c[10];
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the process id and the size of process:");
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].pid,&a[i].psize);
        a[i].blk_no=-1;
    }
    printf("Enter the number of blocks:");
    scanf("%d",&m);
    printf("Enter the block id and the size of the block:");
    for(int i=0;i<m;i++){
        scanf("%d%d",&b[i].b_no,&b[i].b_size);
        b[i].allc=-1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[j].allc==-1 && a[i].psize<=b[j].b_size){
                a[i].blk_no=b[j].b_no;
                c[i]=b[j].b_size-a[i].psize;
                b[j].allc=1;
                break;
            }
        }
    }

    printf("Process_No\tBlock_No\tFragment\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",a[i].pid,a[i].blk_no,c[i]);
    }
}*/
#include<stdio.h>
struct p
{
    int pid,psize,pblo;
}a[10];
struct block
{
    int bid,bsize,balloc;
}b[10];
void main()
{
    int n,m;
   int frag[10];
     printf("enter the no of pros");
    scanf("%d",&n);
     printf("enter the no of blocks");
    scanf("%d",&m);
    printf("enter pid and psize of pros");
    for(int i=0;i<n;i++)
    {
        scanf("%d\t%d",&a[i].pid,&a[i].psize);
        a[i].pblo=-1;
    }
     printf("enter bid and bsize of block");
    for(int i=0;i<m;i++)
    {
        scanf("%d\t%d",&b[i].bid,&b[i].bsize);
        b[i].balloc=-1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].psize<=b[j].bsize&&b[j].balloc==-1)
            {
                a[i].pblo=b[j].bid;
                b[j].balloc=1;
                frag[i]=b[j].bsize-a[i].psize;
                break;
            }
        }
    }
    printf("pid\tpblock\tfrag\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\n",a[i].pid,a[i].pblo,frag[i]);
    }
}