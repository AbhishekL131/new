#include <stdio.h>
#include <stdlib.h>
struct element{
    int val;
    int row;
    int col;
    struct element* next;
}*head,*temp;
void insert(int v,int r,int c){
    struct element* newnode=(struct element*) malloc (sizeof(struct element));
    newnode->val=v;
    newnode->row=r;
    newnode->col=c;
    newnode->next=NULL;
    if(v==0) return;
    else{
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return;
    }
}
void print(int r,int c){
    temp=head;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(temp->row ==i && temp->col==j && temp->val!=0){
                printf("%d ",temp->val);
                temp=temp->next;
            }
            else printf("0 ");
        }
        printf("\n");
    }
    return;
}

int main(void){
    head=NULL;
    int m,n;
    printf("Enter the no of rows:\n ");
    scanf("%d",&m);
    printf("Enter the no of columns:\n ");
    scanf("%d",&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int p;
            printf("Enter the element:\n");
            scanf("%d",&p);
            insert(p,i,j);
        }
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
    print(m,n);
    
}
