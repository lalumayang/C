#include <stdio.h>
#include <string.h>
#include <math.h>
//#pragma warning ( disable:4996)
typedef struct Student_Grade_Data{
    char id[10];
    char name[10];
    int grade1;
    int grade2;
    int grade3;
    int grade_total;
};
int main(){
    int n=0;
    int i=0,j=0;
    double grade1_t=0,grade2_t=0,grade3_t=0,total=0, total_avg = 0;
    scanf("%d",&n);
    struct Student_Grade_Data stu[100];
    for(i=0;i<n;i++){
        printf("",i+1);
        //fflush(stdin);
        scanf("%s",stu[i].id);
        scanf("%s",stu[i].name);
        scanf("%d",&stu[i].grade1);
        scanf("%d",&stu[i].grade2);
        scanf("%d",&stu[i].grade3);
        stu[i].grade_total=stu[i].grade1+stu[i].grade2+stu[i].grade3;
    }
    printf("\n");
    //bubble sort
    struct Student_Grade_Data temp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(stu[j].grade_total<stu[j+1].grade_total){
            temp=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=temp;
            }
        }
    }

    //printf("output\n");
    double mid=0,maxt=0,mint=0,max=0,min=0,var=0,std=0;

    for(i=0;i<n;i++){
        printf("%s %s %d %d %d %d %d\n",stu[i].id,stu[i].name,stu[i].grade1,stu[i].grade2,stu[i].grade3,stu[i].grade_total,i+1);
        grade1_t+=stu[i].grade1;
        grade2_t+=stu[i].grade2;
        grade3_t+=stu[i].grade3;
        total+=stu[i].grade_total;
    }
	total_avg = total / n;

    if(n%2==0){//偶數
        mid=(double)(stu[(n/2)-1].grade_total+stu[(n/2)].grade_total)/2;
        for(i=(n/2);i<n;i++)
        {
            maxt=maxt+stu[i].grade1+stu[i].grade2+stu[i].grade3;
        }
        for(i=0;i<n/2;i++){
            mint=mint+stu[i].grade1+stu[i].grade2+stu[i].grade3;
        }
        max=maxt/(n/2);
        min=mint/(n/2);
    }
    else if(n%2==1){//奇數
        mid=stu[n/2].grade_total;
        for(i=(n/2)+1;i<n;i++)
        {
            maxt=maxt+stu[i].grade1+stu[i].grade2+stu[i].grade3;
        }
        for(i=0;i<n/2;i++){
            mint=mint+stu[i].grade1+stu[i].grade2+stu[i].grade3;
        }
        max=maxt/(n/2);
        min=mint/(n/2);

    }
	for (i = 0; i < n; i++) {
		var += pow(stu[i].grade_total - total_avg ,2);
		//printf("%.2lf",var);
	}
	std = sqrt(var/n);
    printf("%.2lf\n",grade1_t/n);
    printf("%.2lf\n",grade2_t/n);
    printf("%.2lf\n",grade3_t/n);
    printf("%.2lf\n",total_avg);
    printf("%.2lf\n",mid);
	printf("%.2lf\n",var/n);
	printf("%.2lf\n",std);
    printf("%.2lf\n",min);
    printf("%.2lf\n",max);





    return 0;
}


