#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *lower(char string[]){
   int i;
   for (i=0; i<strlen(string); i++){
      string[i]=tolower(string[i]);
    }
   return string;
}
int main(){
    int i=0,num_w=0;
    char article[100],word_arr[100][100],*L;
    scanf("%[^\n]",article);
    lower(article);
    L=strtok(article," ");
    while (L!=NULL){//句子拆解成單字放到word_arr
        strcpy(word_arr[i],L);
        num_w++;
        i++;
        L=strtok(NULL," ");
    }
    int j=0,num_n[100]={0};//num_n對映num_c的[]
    char num_c[100][100]={0};//不重複的單字表
    int num_nr=0;//不重複單字的數量
    for(i=0;i<num_w;i++){  //算所有單字的出現次數
        //printf("one\n");
        for(j=0;;j++){
            //printf("two\n");
            if(strcmp(word_arr[i],num_c[j])==0){ //如果這個單字已經出現過了
                num_n[j]++;
                //printf("three\n");
                break;
            }
            if(j==num_nr){//單字沒出現過要建表
                strcpy(num_c[num_nr],word_arr[i]);
                num_n[num_nr]++;
                num_nr++;
                //printf("four\n");
                break;
            }
        }
    }

    for(i=0;i<num_nr;i++) printf("%s %d\n",num_c[i],num_n[i]);
    //for(i=0;i<num_w;i++) printf("%s \n",word_arr[i]);
    return 0;
}
