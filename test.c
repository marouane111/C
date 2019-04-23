#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct liste{
	int data;
	struct liste *next;
};
typedef struct liste liste;
liste *creation(liste *l,int val){
	liste *new;
	new=(liste*)malloc(sizeof(liste));
	if(new == NULL){
		printf("erreur d'allocation \n");
		return 0;
	}
	new->data=val;
	new->next=l;
	l=new;
	return new;
}
void fin(liste **l,int val){
	liste *new;
	new=(liste*)malloc(sizeof(liste));
	new->next=NULL;
	new->data=val;
	liste *tmp=*l;
	while(tmp != NULL){
		tmp=tmp->next;
	}
	tmp->next=new;
}
void show(liste *l){
	liste *tmp;
	tmp=l;
	while(tmp != NULL){
		printf("  %d   ",tmp->data );
		tmp=tmp->next;
	}
}
int chercher(liste *l,int x){
	liste *tmp;
	tmp=l;
	while(tmp != NULL ){
		if(tmp->data == x) return 1;
		 tmp=tmp->next;
	}
	return 0;
}
int supprimer(liste **l){
	liste *tmp;
	int min;
	liste *precedent=NULL;
	liste *positionmin=NULL;
	tmp=*l;
	if(*l == NULL) return 0;
	else if((*l)->next==NULL){
		*l=NULL;
		free(tmp);
		return 1;
	}
	min=tmp->data;
	while(tmp->next->next != NULL){
		if(tmp->next->data < min ){
			min=tmp->next->data;
			positionmin=tmp->next;
			precedent=tmp;
		}
		tmp=tmp->next;
	}
	if(tmp->next->data < min){
		min=tmp->next->data;
		positionmin=tmp->next;
		precedent=tmp;
	}
	precedent->next=positionmin->next;
	free(positionmin);
	return 1;

}
liste *fusion(liste *a,liste *b){
	liste *c;
	if(a==NULL) return b;
	else if(b==NULL) return a;
	liste *p1=a;
	liste *p2=b;
	while (p1 && p2){
		fin(&c,p1->data);
		fin(&c,p2->data);
		p1=p1->next;
		p2=p2->next;
	}
	while(p1){
		fin(&c,p1->data);
		p1=p1->next;
	}
	while(p2){
		fin(&c,p2->data);
		p2=p2->next;
	}
	return c;
}
int main(){
	liste *l=NULL;
	int x;
	srand(time(NULL));
	int i;
	/*for(i=0;i<5;i++){
		int n=rand()%10;
		l=creation(l,n);
	}
	show(l);
	printf("\ndonner la valeur a chercher : ");
	scanf("%d",&x);
	if(chercher(l,x)==1) printf("il existe\n");
	else printf("ca n'existe pas\n");
	supprimer(&l);
	printf("apres : \n");
	show(l);*/
	liste *a=NULL;
	liste *b=NULL;
	for(i=0;i<5;i++){
		int n=rand()%10;
		a=creation(a,n);
	}
	for(i=0;i<5;i++){
		int n=rand()%10;
		b=creation(b,n);
	}
	show(a);
	printf("\n");
	show(b);

	printf("\n");
	show(fusion(a,b));
}
