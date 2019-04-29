#include<stdio.h>
int main(){
    int i=0,j=0;
    int chessboard[10][10]={0};
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            scanf("%d",&chessboard[i][j]);
        }
    }
    printf("\n");
    int k=0;
    int count=0,temp=0;
    //¥ª¥k
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            for (k = 0; k < 5; k++) {
                if(j+k<10&&chessboard[i][j + k]==1) count++;
                else temp=k;
            }
            if(count>=4&&j+temp<10&&chessboard[i][j+temp]==0){
                chessboard[i][j+temp]=8;
            }
            count=0;
            temp=0;
        }
    }
    //¤W¤U
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){

            for (k = 0; k < 5; k++) {
                if(i+k<10&&chessboard[i+ k][j]==1) count++;
                else temp=k;
            }
            if(count>=4&&i+temp<10&&chessboard[i+temp][j]==0){
                chessboard[i+temp][j]=8;
            }
            count=0;
            temp=0;
        }
    }
    //¥k±×
    for(i=0;i<6;i++){
        for(j=9;j>=0;j--){
            for (k = 0; k < 5; k++) {
                if(i+k<10&&j-k>=0&&chessboard[i+k][j-k]==1) count++;
                else temp=k;
            }
            if(count>=4&&i+temp<10&&j-temp>=0&&chessboard[i+temp][j-temp]==0){
                chessboard[i+temp][j-temp]=8;
            }
            count=0;
            temp=0;

        }
    }
    //¥ª±×
     for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            for (k = 0; k < 5; k++) {
                if(i+k<10&&j+k<10&&chessboard[i+k][j+k]==1) count++;
                else temp=k;
            }

            if(count>=4&&i+temp<10&&j+temp<10&&chessboard[i+temp][j+temp]==0){
                chessboard[i+temp][j+temp]=8;
            }
            count=0;
            temp=0;
        }
    }

    /*for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%d ",chessboard[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/

    //output
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(chessboard[i][j]==8){
                printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}

