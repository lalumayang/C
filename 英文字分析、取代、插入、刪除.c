#include<stdio.h>
#include<string.h>
int getwords(char art[100], char *words[30]){
    int i=0;
    words[0]=strtok(art," ");
    while(words[i] != NULL)
        words[++i]=strtok(NULL," ");
    return i;
}
/*void pop(char *a[30],int n){
    int i;
    for(i = n;i < 29;i ++){
        a[i]=a[i+1];
    }
}
void getcount(char *words[30], int count[30],int *n){
    int i=0,j;
    for(i = 0;i < *n-1;i ++){
        for(j = i+1;j < *n;j ++){
            if(strcmp(words[i],words[j])==0){
                pop(words,j);
                count[i]++;
                (*n)--;
            }
        }
    }
}*/
void f1(char *words[30], char p[10], char q[10]){
    int i;
    for(i = 0;words[i] != NULL;i ++){
        if(strcmp(words[i],p)==0){
            printf("%s ",q);
            printf("%d\n",i);
        }
        else
            printf("%s ",words[i]);
    }
    printf("\n");
}/*
void f2(char *words[30], char p[10], char q[10]){
    int i;
    for(i = 0;words[i] != NULL;i ++){
        if(strcmp(words[i],p)==0)
            printf("%s ",q);
        printf("%s ",words[i]);
    }
    printf("\n");
}/*
void f3(char *words[30], char p[10], char q[10]){
    int i;
    for(i = 0;words[i] != NULL;i ++){
        if(strcmp(words[i],p)!=0)
            printf("%s ",words[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swappt(char **a, char **b){
    char *c=*a;
    *a=*b;
    *b=c;
}
void selection_sort(int arr1[30], char *arr2[30], int n){
	int i, j, max;
	for (i = 0; i < n-1; i++) {
		max = i;
		for (j = i + 1; j < n; j++)
			if (arr1[max] < arr1[j]||arr1[max]==arr1[j]&&strcmp(arr2[max],arr2[j])>0)
				max = j;
	   	swap(arr1+max,arr1+i);
	   	swappt(arr2+max,arr2+i);
	}
}*/
void main(){
    char art[100]="\0",p[10]="\0",q[10]="\0",*words[30];
    int n,i,count[30]={0};
    scanf("%[^\n] ",art);
    scanf("%s %s",p,q);
    n=getwords(art,words);
    f1(words,p,q);
    /*f2(words,p,q);
    f3(words,p,q);
    getcount(words,count,&n);
    selection_sort(count,words,n);
    for(i=0;i<n;i++) printf("%s %d\n",words[i],count[i]+1);*/
}
