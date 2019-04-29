#include <stdio.h>
#include <string.h>
int main(){
    char a[100],b[100],*ret;
    int i=0,j=0;
    scanf("%s[^\n]",a);
    scanf("%s[^\n]",b);

    char longstr[100]={0},shortstr[100]={0},comstr[100];
    //a<b
    if(strlen(a)<strlen(b)){
        strcpy(longstr,b);
        strcpy(shortstr,a);
    }
    //a>b
    else if(strlen(a)>strlen(b)){
        strcpy(longstr,a);
        strcpy(shortstr,b);
    }
    //a=b b=short
    else{
        strcpy(longstr,b);
        strcpy(shortstr,a);
    }



    int L=0,num=0,comL=0,k=0;
    char *find;
    L=strlen(shortstr);//短字串長度
    for(i=L;i>0;i--){
        for(j=0;i+j<=L;j++){
            memcpy(comstr,shortstr+j,i+1);//shortstr+j=shortstr[j]之後的字元
            //puts(comstr);
            //printf("===");
            find=strstr(longstr,comstr);
            if(find!=NULL){
                //printf("ans ");
                printf("%s",comstr);
                //memset(comstr,'/0',strlen(comstr));
                return 0;
            }
        }

    }


    return 0;
}
