#include <stdio.h>
int powi(int x,int n){
	if(n==0)  return 1;
	else  return x*powi(x,n-1);
}
int bin2dec(char* b,int pown){
	if(pown==0)  return (*b)-48;
	else  return ((*b)-48)*powi(2,pown)+bin2dec(b+1,pown-1);  //二進制 由左而右 變成10進制
}
void dec2bin2print(int d,int limit){
	if(limit==0)  return;
	dec2bin2print(d/2,limit-1);  //印出之前先把值更動成下一個值 才會開始印出
	printf("%d",d%2);  //由最高次方 印到0次方為止
}
int c(int m,int* count){
	(*count)++;  //在判斷前就+1  所以最後會多1
	if(m<=1)  return m;
	else if(m%2==0)  return c(m/2,count);
	else  return c((m+1)/2,count);
}
int main(){
	char n[9];
	int m,counter=0,sum=0;
	scanf("%s",n);
	m=bin2dec(n,7); //m是10進制的n
	while(1){
		if(n[0]=='0'&&n[1]=='\0')  continue;
		if(n[0]=='-')   break;
		counter=0;      //重置
		c(m,&counter);
		counter--;      //減回來
		m--;
		sum+=counter;
		if(m==-1){  //結果要算到0   所以m=-1才停
            dec2bin2print(sum,11);
            printf("\n");
            do{
                scanf("%s",n);
            }while(n[0]=='0'&&n[1]=='\0');
            if(n[0]=='-')   break;
            m=bin2dec(n,7); //m是10進制的n
            sum=0;
		}
	}
	return 0;
}
