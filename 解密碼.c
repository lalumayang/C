#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char str1_IN[200],str2_IN[200],str1_inverse[200],answer_map[200][2]={0};
    gets(str1_IN);
    int i=0,length1=0,num=0,answer=0,s=0;
    length1=strlen(str1_IN);
    for (i=0;i<length1;i++){  //反轉
        str1_inverse[i]=str1_IN[length1-1-i];  //lentg1 的位置是'\0' 所以至少要減1
    }
    for (i=0;i<length1;i++){  //解出第一句的答案
        if(str1_inverse[i]<48||str1_inverse[i]>57){//字母 num=0
            num=0;
            continue;
        }//還能跑到這  代表有看到數字了
        //printf("%c",str1_inverse[i]);
        num=num*10+str1_inverse[i]-48;//error

        if(num>10000){//大於四位數  就取四位數
            num/=10;
        }
        if(str1_inverse[i+1]<48||str1_inverse[i+1]>57){ //如果下一個字元不是數字  就要結算了
            answer+=num;
        }
    }


    gets(str2_IN);
    int j=0,seq=0,i_temp=0,k=0;
    int length2=strlen(str2_IN);
    int str2_num=0;
    num=0;
    for (i=0;i<length2;i++){  //計算每個字元出現的次數 並建立答案表
        for (j=0;;j++){
            if(str2_IN[i]!=' '){//空白不算
                if(str2_IN[i]>47&&str2_IN[i]<58){//判斷是數字
                    if(j==num){// 代表沒出現過  要建表給他
                        num++;//這裡的num 是不重複的  有出現過的字元  的數量
                        answer_map[j][1]=str2_IN[i]-'0';
                        answer_map[j][0]=str2_IN[i]-'0';
                        break;
                    }
                }
                else {//判斷是字母
                    if(str2_IN[i]==answer_map[j][1]){   //[x][1] 是出現字元    [x][0]是出現次數
                        answer_map[j][0]++;
                        break;
                    }
                    if(j==num){// 代表沒出現過  要建表給他
                        num++;//這裡的num 是不重複的  有出現過的字元  的數量
                        answer_map[j][1]=str2_IN[i];
                        answer_map[j][0]++;
                        break;
                    }
                }
            }
            else break;
        }
    }
    printf("\n");
    //printf ("%d",answer);
    if(answer>=0&&answer<=9){
         printf ("000%d",answer);
    }
    else if(answer>=10&&answer<=99){
         printf ("00%d",answer);
    }
    else if(answer>=100&&answer<=999){
         printf ("0%d",answer);
    }
    else if(answer>=1000&&answer<=9999) printf("%d",answer);
    else printf("%d",answer-10000);


    for (i=0;i<num;i++){//大於等於10排除
         if(answer_map[i][0]<=10) {
            printf("%d",answer_map[i][0]);
        }
    }
    return 0;
}
