//城市走訪
#include <stdio.h>
int main(){
    int N,M,distance[10][10]={0},I,J,K,sum=0,min=9999,next_p=1,N_temp=0;   //N城市數 M道路數  I城市 J城市  K距離   sum總距離
    scanf ("%d,%d",&N,&M);
    while(M!=0){  //輸入所有的路徑距離   沒路徑的依然維持0
        scanf ("%d,%d,%d",&I,&J,&K);
        distance[I][J]=K;
        distance[J][I]=K;
        M--;
    }//在這之下 全部都是以 "列"的方式  選大於0的最小值   橫向(I)出發點     直向(J)是目的地
    I=1;//一定從城市1出發
    N_temp=N;
    while(N_temp>1){//假設有3座城鎮   一開始從1出發  也只需要經過2個城鎮 就走完了  所以計算總路徑 是城鎮數減1
        for (J=2;J<=N;J++){  //以"列"的方式 從第2個城市到最後一個城市當中找大於0的最小值   J代表行
            if (distance[I][J]>0&&min>distance[I][J]){//這時的I 代表現在所在的城市
                min=distance[I][J];
                next_p=J;  //最後一次進if的J  代表即將要前往的下一個城鎮
            }//注意這個J一定要透過next_p之後在22行轉接給I  不然上面那個if的distance[I]  會偏掉
        }  //到下一座 最近的城鎮了  接下來就把剛才走到的新的城鎮 整行改成-1
        sum+=min;
        I=next_p;  //出發點不再是1了  而是剛才找到的城鎮
        for (J=1;J<=N;J++){  //把現在走到的地方  整行排除掉  這是排除 "直的"  避免以後再走到這裡
            distance[J][next_p]=-1;  //這個J  跟任何地方無關  只是沒用到拿來用而已
        }
        N_temp--;
        min=9999;   //很重要  不然min會一直是1
    }
    printf ("%d",sum);
    return 0;
}
