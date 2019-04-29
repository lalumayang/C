#include <stdio.h>
int set[20];
int data[10000][10000];
int num_com;//幾個組合
int total[10000];//總時數
int act_total[10000]={0};//活動總數
int max_num;
int max_act;
typedef struct activity{
    int act_num;
    int act_start;
    int act_end;
}act;
void PowerSet(int i,int N){
    int j=0,num=0;
    if(i>N){
        for(j=1;j<=N;j++){
            if(set[j]==1){
                //printf("%d ",j);
                //printf("num=%d",num);
                data[num_com][num]=j;
                num++;
            }
        }
        //printf("\n");
        num_com++;
        //printf("num_com=%d\n",num_com);
    }
    else{
        set[i]=1;
        PowerSet(i+1,N);
        set[i]=0;
        PowerSet(i+1,N);
    }
}
int position(int N,int p,struct activity act[10000]){
    int i=0;
    for(i=0;i<N;i++){
        if(p==act[i].act_num) return i;
    }
}
void time(struct activity act[10000],int N,int room){
    int i,j,k,l;
    int tot_time[24]={0};
    for(i=0;i<num_com-1;i++){
        for(j=0;j<N;j++){//使用時數
            for(k=act[position(N,data[i][j],act)].act_start;k<act[position(N,data[i][j],act)].act_end;k++) {
                tot_time[k]+=1;
                //printf("tot[%d]=%d\n",k,tot_time[k]);
            }
        }
        for(j=0;j<24;j++){//超過會議中心間數
            if(tot_time[j]>room){
                //printf("t[%d]=%d\n",j,tot_time[j]);
                for(k=0;k<N;k++){
                    data[i][k]=0;
                    //printf("data[%d][%d]=%d\n",i,k,data[i][k]);
                }
            }
        }
        //printf("%d ",i);
        for(j=0;j<N;j++){//總數
            if(data[i][j]!=0){
                if(data[i][j]==act[position(N,data[i][j],act)].act_num){
                    total[i]+=(act[position(N,data[i][j],act)].act_end)-(act[position(N,data[i][j],act)].act_start);
                    //printf("end[%d]=%d\n",k,act[k].act_end);
                    //printf("start=%d\n",act[k].act_start);
                    //printf("total[%d]=%d\n",i,total[i]);
                    //printf("a ");
                }
            }
        }
        for(j=0;j<N;j++){//活動數
            if(data[i][j]!=0){
                act_total[i]+=1;
            }
        }
        //printf("\n");
        //printf("total[%d]=%d\n",i,total[i]);//總數
        //printf("act_total[%d]=%d\n",i,act_total[i]);//活動數
        for(l=0;l<24;l++){//清空
            tot_time[l]=0;
        }
    }
}
int priority(int max){//總數
    int i,j;
    for(i=0;i<num_com-1;i++){
        //printf("total[%d]=%d\n",i,total[i]);//活動數
        max=total[i];
        max_num=i;
        //printf("%d\n",max_num);
        //printf("i[%d]=%d\n",i,max);
        for(j=i+1;j<num_com-1;j++){
            //printf("%d %d\n",j,total[j]) ;
            if(max<total[j]){
                max=total[j];
                max_num=j;
                //printf("j[%d]=%d\n",j,max);
            }
        }
        //printf("%d\n",max_num);
        return max;
    }
}
int act_priority(int max){//活動數
    int i,j;
    for(i=0;i<num_com-1;i++){
        //printf("act_total[%d]=%d\n",i,act_total[i]);//活動數
        max=act_total[i];
        max_act=i;
        //printf("%d\n",max_num);
        //printf("i[%d]=%d\n",i,max);
        for(j=i+1;j<num_com-1;j++){
            //printf("%d %d\n",j,act_total[j]) ;
            if(max<act_total[j]){
                max=act_total[j];
                max_act=j;
                //printf("j[%d]=%d\n",j,max);
            }
        }
        //printf("%d\n",max_num);
        return max;
    }
}
/*int find_num_act(int n,int N){
    int i,j;
    for(i=0;i<num_com-1;i++){
        //printf("i=%d\n",i);
        if(i==max_num){
            //printf("mi=%d\n",i);
            //printf("mm=%d\n",max_num);
            for(j=0;j<N;j++){
                if(data[i][j]!=0){
                    n++;
                }
            }
        }
    }
    return n;
}*/
int main(){
    struct activity act[10000];
    int room=0,N=0,i=0,j=0,n=0,max=0,act_max=0;
    scanf("%d",&room);
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d ",&act[i].act_num);
        scanf("%d ",&act[i].act_start);
        scanf("%d",&act[i].act_end);
    }
    //組合
    for(i=0;i<N;i++){
        set[i]=0;
    }
    PowerSet(1,N);
    //print 組合
    /*for(i=0;i<num_com-1;i++){
        for(j=0;j<N;j++){
            printf("%d ",data[i][j]);
        }
        printf("\n");
    }*/

    time(act,N,room);

    int aaa=0;
    aaa=priority(max);
    printf("%d\n",aaa);
    int bbb=0;
    bbb=act_priority(act_max);
    printf("%d",bbb);
    /*for(i=0;i<num_com-1;i++){
        printf("total[%d]=%d\n",i,total[i]);
    }*/
    return 0;
}

