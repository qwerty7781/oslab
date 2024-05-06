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
    struct b temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<m-i-1;j++){
            if(b[j].b_size<b[j+1].b_size){
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
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
}
