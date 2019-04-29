#include <stdio.h>
void main() {
    int m1,n1,m2,n2;
    int i,j,k;
    int A[10][10],B[10][10],C[10][10];
    //printf("input：\n");
    scanf("%d %d",&m1,&n1);
    for(i=1;i<=m1;i++) {
        for(j=1;j<=n1;j++) {
            scanf("%d",&A[i][j]);
        }
    }
    scanf("%d %d",&m2,&n2);
    for(i=1;i<=m2;i++) {
        for(j=1;j<=n2;j++) {
            scanf("%d",&B[i][j]);
        }
    }
    //printf("output：\n");
    //相加
    if(m1==m2&&n1==n2){
        for(i=1;i<=m2;i++) {
            for(j=1;j<=n2;j++) {
                C[i][j]=A[i][j]+B[i][j];
            }
        }
        for(i=1;i<=m2;i++) {
            for(j=1;j<=n2;j++) {
                printf("%d ",C[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else printf("ERROR\n");
    //相減
    if(m1==m2&&n1==n2){
        for(i=1;i<=m2;i++) {
            for(j=1;j<=n2;j++) {
                C[i][j]=A[i][j]-B[i][j];
            }
        }
        for(i=1;i<=m2;i++) {
            for(j=1;j<=n2;j++) {
                printf("%d ",C[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else printf("ERROR\n");
    //相乘
    if(m1==n2&&n1==m2){
        for (i=1; i<=m1; i++) {
            for (j=1; j<=n2; j++) {
                C[i][j]=0;
                for(k = 1; k <= n1; k++) {
                    C[i][j] = C[i][j] +A[i][k] * B[k][j];
                }
                printf("%d ", C[i][j]);
            }
            printf("\n");
        }
    }
    else printf("ERROR\n");
    return 0;
}
