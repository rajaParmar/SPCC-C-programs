#include<stdio.h>
#include<string.h>
typedef struct{
char options[10][10];
char name;
int nop;
char first[10][10];
}production;
production p[10];	int n;
int epsilon_obt=0;
void display_production(production p){
	printf("%c->",p.name);
	int i;
	for(i=0;i<p.nop;i++){
		printf("%s | ",p.options[i]);
	}
}
int get_production(char name_to_get){
	int i;
	for(i=0;i<n;i++){
		if(p[i].name==name_to_get){
			return i;
		}
	}
}
void add_to_result(char *result,char val){
	int i=0;
	while(result[i]!='\0'){
		i++;
	}
	result[i]=val;
	i++;
	result[i]='\0';
}
void get_first(char *result,char name,int *epsilon){
	int index=get_production(name);
	int i=0;
	for(i=0;i<p[index].nop;i++){
		int current_item=0;
		//rintf("%c",p[index].options[i][current_item]);
		while(isupper(p[index].options[i][current_item])){
			//printf("Entered here for index :%d",index);
			char name_of_cur_prod=p[index].options[i][current_item];
			get_first(result,name_of_cur_prod,epsilon);
			if(*epsilon==1){
				current_item++;
				if(islower(p[index].options[i][current_item])==1){
					char small=p[index].options[i][current_item];
					add_to_result(result,small);
					break;
				}	
				*epsilon=0;
			}
			else break;
		}
		if(p[index].options[i][current_item]=='$'){
			*epsilon=1;
			add_to_result(result,'$');
			//printf("%c",p[index].options[i][current_item]);
			return;
		}
		if(islower(p[index].options[i][current_item])){
			add_to_result(result,p[index].options[i][current_item]);
			//printf("%c",p[index].options[i][current_item]);
		}

	}
}
void format(char *result,char *new_result){
	int i,epsilon=0;int j=0;
	for(i=0;i<strlen(result);i++){
		if(result[i]=='$')
			epsilon=1;
		if(epsilon==0)
			new_result[j++]=result[i];
	}
}
void main(){
	printf("Enter number of productions:");
	scanf("%d",&n);
	//printf("Enter productions\n");
	//fflush(stdin);
	getchar();
	int i;int j;
	for(i=0;i<n;i++){
		int nof;
		printf("Enter Name of production:");
		scanf("%c",&p[i].name);
		//p[i].name='B';
		printf("Enter no of options for production %c",p[i].name);
		scanf("%d",&p[i].nop);
		getchar();
		//sp[i].nop=2;
		for(j=0;j<p[i].nop;j++){
			printf("Enter option %d",j+1);
			scanf("%s",p[i].options[j]);
			getchar();
		}
		//display_production(p[i]);
	}
	char result[10]={};
	int epsilon=0;
	get_first(result,'S',&epsilon);
	char new_result[10]={};
	//format(result,new_result);
	printf("%s\n,",result);
	
}