#include<stdio.h>
#include<string.h>

typedef struct s{
	int x;
	int y;
	struct s *next;
}sn;

void walk(sn *top,char d){
	sn *t=NULL,*count=top;
	while(count->next!=NULL){
		sn *tt=top;
		while(tt->next->next!=t)tt=tt->next;
		tt->next->x=tt->x;tt->next->y=tt->y;
		t=tt->next;
		count=count->next;
	}
	t=top;
	switch(d){
		case 'l':t->x-=1;break;
		case 'r':t->x+=1;break;
		case 'u':t->y-=1;break;
		case 'd':t->y+=1;break;
	}
}

int r(int k,int a,int b){return (k>=a && k<=b?0:1);}

int find(sn *top,int x,int y){
	sn *t=top;
	while(t!=NULL){if(t->x==x && t->y==y)break;t=t->next;}
	return (t==NULL?1:0);
}

int willvalid(sn *top,char d){
	int x=top->x,y=top->y;
	switch(d){
		case 'l':return find(top,x-1,y);
		case 'r':return find(top,x+1,y);
		case 'u':return find(top,x,y-1);
		case 'd':return find(top,x,y+1);
	}
}

int valid(sn *top){
	sn *a=top,*b;
	while(a->next!=NULL){
		b=a->next;
		while(b!=NULL){
			if((a->x==b->x && a->y==b->y) || r(a->x,0,9) || r(a->y,0,9) || r(b->x,0,9) || r(b->y,0,9))return 0;
			b=b->next;
		}a=a->next;
	}return 1;
}

void push(sn **top,int x,int y){
	sn *temp=(sn*)malloc(sizeof(sn)),*t=*top;
	temp->x=x;temp->y=y;
	if(t==NULL){*top=temp;return;}
	while(t->next!=NULL)t=t->next;
	t->next=temp;
}

void print(sn *top){
	sn *t=top;
	while(t!=NULL){
		printf("%d, %d\n",t->x,t->y);
		t=t->next;
	}printf("\n");
}

int main(){
	int i;
	char str[100];
	sn *top=NULL;
	for(i=4;i>=0;i--)push(&top,i,0);i=1;
	while(i){
		gets(str);
		int x=atoi(strtok(str," "));
		int y=atoi(strtok(NULL," "));
		int fx,fy,tri=0;
		strcpy(str,strtok(NULL,"\0"));
		char *temp=str;
		for(;*temp!='\0';temp++){
			if(willvalid(top,*temp)==0){i=0;break;}
			walk(top,*temp);
			if(top->x==x && top->y==y){push(&top,fx,fy);tri=1;}
			if(i==1 && valid(top)==0)i=0;
		    sn *tt=top;
		    while(tt->next!=NULL)tt=tt->next;
		    fx=tt->x;fy=tt->y;
		}if(i==0)break;
		else if(tri) printf("Success\n");
		else  printf("Fail\n");
	}printf("Game Over");
}
