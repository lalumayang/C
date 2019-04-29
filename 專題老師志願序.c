//專題
#include<stdio.h>
void confirmed(int tarr [10][10], int arr[10],int n){
    int i,j;
    for(i=0;i<10;i++){
        arr[i]=-1;
        for(j=0;j<10;j++){
            if(tarr[i][j]==n) tarr[i][j]=-1;
        }
    }
    arr[0]=n;
}
int writearr(int arr[10][10]){
    int i,j,n=10;
    char in,ch=' ';
    for(i=0;i<n;i++){
        ch=' ';
        for(j=0;j<n;j++){
            scanf("%c%c",&in,&ch);
            arr[i][j]=in-65;
            if(ch!=',') break;
        }
        n=j+1;
    }
    return n;
}
int priority(int stu, int tea[10]){
    int i;
    for(i=0;i<10;i++){
        if(tea[i]==stu+22) return 10-i;
    }
}
int comp(int stu[10][10], int tea[10][10], int n){
    int i,j,k,re=0,max;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            max=i;
            if(stu[i][k]==-1) continue;
            for(j=i+1;j<n;j++){
                if(stu[i][k]==stu[j][k]){
                    if(priority(max,tea[stu[i][k]])<priority(j,tea[stu[i][k]])) max=j;
                }
            }
            confirmed(stu,stu[max],stu[i][k]);
        }
    }
}
void main(){
    int stu[10][10]={0},tea[10][10]={0},i,n;
    n=writearr(stu);
    writearr(tea);
    comp(stu,tea,n);
    for(i=0;i<n;i++){
        printf("%c->%c\n",91-n+i,stu[i][0]+65);
    }
}
