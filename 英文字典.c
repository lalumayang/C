#include <stdio.h>
#include <string.h>
int isCompareString(char* a,char* b){
    int i,len;
    len=(strlen(a)>strlen(b))?strlen(b):strlen(a);
    for(i=0;i<len;i++){
        if(a[i]!=b[i]){
            int as=a[i]='0';
            int bs=b[i]='0';
            if(as>bs) return 1;
            return -1;
        }
        if(strlen(a)>strlen(b)) return 1;
        else if(strlen(a)<strlen(b)) return -1;
        return 0;
    }
}
int main(){

    char input[100],in[100][20],find[100];
    int i=0,j=0,num=0,n=0,position=0;//num有幾個字串
    scanf("%s[\n]",find);
    while(input[0]!='-'){
        scanf("%s[\n]",input);
        strcpy(in[num],input);
        num++;
    }
    //printf("\n");
    //輸出全部字串
    /*printf("------all string\n");
    for(i=0;i<num-1;i++){
        printf("%s\n",&in[i]);
    }*/
    //printf("%d",num);

    //printf("------all A-B string\n");
    int p=0;

    for(i=0;i<num-1;i++){
        if(strstr(in[i],find)!=NULL){
            position=strlen(in[i])-strlen(strstr(in[i],find));
            p=position+strlen(find);
            while(in[i][position]!='\0'&&position<p){
                position++;
            }
            while((in[i][position-(strlen(find))]=in[i][position])!='\0'){
                position++;
            }
            //printf("%s\n",in[i]);
        }
        //else printf("%s\n",in[i]);
    }

    /*for(i=0;i<num-1;i++){
        if(isCompareString(in[i],in[i]+1)==1) printf("a>b");
        else if(isCompareString(in[i],in[i]+1==-1)) printf("a<b");
        else printf("a=b");

    }*/
    //printf("\n---------sort\n");
    char temp[100];
    for(i=0;i<num-1;i++){
        for(j=0;j<=i-1;j++){
            if((strcmp(in[i],in[j]))<0){
                memcpy(temp,in[j],strlen(in[j])+1);
                memcpy(in[j],in[i],strlen(in[i])+1);
                memcpy(in[i],temp,strlen(temp)+1);
                //printf("a<b\n");
            }
        }
    }
    for(i=0;i<num-1;i++){
        printf("%s\n",&in[i]);
    }

    /*//bubble sort
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(stu[j].grade_total<stu[j+1].grade_total){
            temp=stu[j];
            stu[j]=stu[j+1];
            stu[j+1]=temp;
            }
        }
    }*/


    return 0;

}
