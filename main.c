#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
}*head,*temp,*head1,*head2,*temp1,*temp2,*head3;

struct node* add_node(struct node* head,int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    
    newnode->next = head;
    head = newnode;
    return head;
}

void display(struct node* head){
    temp = head;
    
    if(head == NULL){
        printf("empty \n");
    }
    
    else {
        
        while(temp->next != NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("%d",temp->data);
    }
       
    
}

struct node* create(struct node* head,int a){
    while(a != 0){
        head = add_node(head, a%10);
        a = a/10;
    }
    return head;
}

struct node* reverse(struct node* head){
    struct node* current = NULL;
    struct node* ptr = head->next;
    head->next = NULL;
    
    while(ptr != NULL){
        current = ptr;
        ptr = ptr->next;
        current->next = head;
        head = current;
    }
    return head;
}

struct node* add(struct node* head1,struct node* head2){
    if(head1->data == 0){
        return head2;
    }
    if(head2->data == 0){
        return head1;
    }
    
    temp1 = head1;
    temp2 = head2;
    head3 = NULL;
    
    int carry=0,sum;
    
    while(temp1 || temp2){
        sum = 0;
        if(temp1)
            sum = sum + temp1->data;
        if(temp2)
            sum = sum + temp2->data;
        
        sum = sum + carry;
        carry = sum/10;
        sum = sum%10;
    }
    
}

int main(void){
    head1 = NULL;
    head2 = NULL;
   

    int n1,n2;
    printf("enter a number 1 :\n");
    scanf("%d",&n1);
    
    
    head1 = create(head1,n1);
    printf("original number :\n");
    display(head1);
    printf("reversed number :\n");
    head1 = reverse(head1);
    display(head1);
    

    printf("enter a number 2 :\n");
    scanf("%d",&n2);
    
    
    head2 = create(head2,n2);
    display(head2);
    
    
}



