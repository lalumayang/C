#include <stdio.h>
#include <string.h>
#include <math.h>
#pragma warning ( disable:4996)
typedef struct Grade {
	char course[20];
	int credit;
	int grade;
};
typedef struct Student{
    int id;
    char name[10];
	int have;
	struct Grade g[100];
	int pass_credit;
	float avg;
};
int getCredit(int have,struct Student stu){
    int i=0,credit=0,grade=0;
    for(i=0;i<have;i++){
        grade=stu.g[i].grade;
        if(grade>=60) credit+=(stu.g[i].credit);
    }
    return credit;
}
int main(){
    int x = 0;
    int i = 0,j=0,k=0;
    scanf("%d", &x);
    struct Student stu[100];
    struct Student temp;
    for (i = 0; i < x; i++) {
        printf("", i + 1);
        scanf("%d", &stu[i].id);
        scanf("%s", stu[i].name);
        scanf("%d", &stu[i].have);
        for (j = 0; j < stu[i].have;j++) {
            printf("", j + 1);
            scanf("%s", stu[i].g[j].course);
            scanf("%d", &stu[i].g[j].credit);
            scanf("%d", &stu[i].g[j].grade);
        }
    }
    //printf("search\n");
    int search;
    int sea[100]={0};
    int s = 0;
    while (1){
        scanf("%d",&search);
        if(search==0) break;
        sea[s]=search;
        s++;
    }
    printf("\n");
    //pass_credit
    for(j=0;j<x;++j){
        stu[j].pass_credit=getCredit((stu[j].have),stu[j]);
    }
    //avg
    for(j=0;j<x;++j){
        int i=0,creditNum=0,sum=0;
        float avg=0.0;
        for(i=0;i<stu[j].have;++i){
            sum+=((stu[j].g[i].grade)*(stu[j].g[i].credit));
        }
        //printf("%d\n",sum);
        for(i=0;i<stu[j].have;++i){
            creditNum+=(stu[j].g[i].credit);
        }
        //printf("%d\n",creditNum);
        stu[j].avg=(float)sum/creditNum;
    }

    //swap
    for(i=0;i<x;i++){
        for(j=0;j<i;j++){
            if(stu[j].avg<stu[i].avg){
                temp=stu[j];
                stu[j]=stu[i];
                stu[i]=temp;
            }
        }
    }

    int a=0,b=0;
    //all rank output
    /*for(a=0;a<x;++a){
        printf("%d %s\n",stu[a].id,stu[a].name);
        for(b=0;b<stu[a].have;++b){
            printf("%s %d %d\n",stu[a].g[b].course,stu[a].g[b].grade,stu[a].g[b].credit);
        }
    }*/

    int error=0;
    for(j=0;j<s;++j){
        for(k=0;k<x;++k){
            if(sea[j]==stu[k].id){
                printf("%d %s\n",stu[k].id,stu[k].name);
                for(b=0;b<stu[k].have;++b){
                    printf("%s %d %d\n",stu[k].g[b].course,stu[k].g[b].credit,stu[k].g[b].grade);
                }
                printf("%d\n",stu[k].pass_credit);
                printf("%.2f\n",stu[k].avg);
                printf("%d\n",k+1);
                error=0;
                break;
            }
            else error=1;
        }
        if(error==1)printf("ERROR\n");
    }


	return 0;
}


