#include<stdio.h>
int data[100][100]={0};
int recursion(int x,int y,int n){
    if(x==n-2&&y==n-2){
        data[x][y]=2;
        return 1;
    }
    else if(data[x][y]==1)  return -1;
    else if(data[x][y]==2)  return -1;
    else{
        data[x][y]=2;
        if(recursion(x+1,y,n)==1)return 1;
        else if(recursion(x-1,y,n)==1)return 1;
        else if(recursion(x,y-1,n)==1)return 1;
        else  if(recursion(x,y+1,n)==1)  return 1;
        else   data[x][y]=3;
    }
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&data[i][j]);
        }
    }
    i=1;
    j=1;
    recursion(i,j,n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(data[i][j]==2){
                printf("# ");
            }
            else if(data[i][j]==3){
                printf("* ");
            }
            else{
                printf("%d ",data[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
