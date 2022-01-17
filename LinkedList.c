/*
SYITA145
Implement any database using a doubly-linked list with the following options a) Insert a record b) delete a record c) modify a record d) Display list forward Display list backward
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void Create(struct Node *head){
    printf("\nEnter data at start : ");
    scanf("%d",&head->data);
    head->next = NULL;
    head->prev = NULL;
}

struct Node* Insert_Node(struct Node *head)
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("\nEnter data you want to Insert : ");
    scanf("%d",&data);
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
    return head;
}

void Insert_end(struct Node *head){
    struct Node *p;
    p = (struct Node*)malloc(sizeof(struct Node));
    int n;
    p = head;

    printf("\nHow many entries do you want to insert : ");
    scanf("%d",&n);

    for(int i=0 ; i<n ;i++){
        struct Node *temp;
        temp = (struct Node *)malloc(sizeof(struct Node));
        int input;

        printf("\nEnter data to be stored : ");
        scanf("%d",&input);

        while(p->next != NULL){
            p = p->next;
        }
        temp->prev = p;
        p->next = temp;
        temp->next = NULL;
    }
}

void Insert_Mid(struct Node *head){
    struct Node *p,*q,*temp;
    int pr,data;
    p = (struct Node *)malloc(sizeof(struct Node));
    q = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));

    printf("\nBefore which data do you want to insert : ");
    scanf("%d",&pr);

    while(q->next != pr){
        p = p->next;
        q = q->next;
    }

    printf("\nEnter data to be added : ");
    scanf("%d",&data);
    temp->data = data;
    p->next = temp;
    temp->prev = p;
    temp->next = q;
    q->prev = temp;
}

struct Node *delete_start(struct Node *head){
    struct Node *p;
    p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

void Delete_end(struct Node *head){
    struct Node *p,*q;
    p = head;
    q = head->next;

    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void Delete_mid(struct Node *head){
    struct Node *p,*q;
    p = head;
    q = head->next;
    int ch;

    printf("\nEnter data to be deleted : ");
    scanf("%d",&ch);

    while(q->data != ch){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
}

void Display(struct Node *head){
    struct Node *p;
    p = head;
    while(p!=NULL){
        printf("\n%d",p->data);
        p = p->next;
    }
}

struct Node* Reverse(struct Node *head){
    struct Node *p,*temp;
    p = head;

    while(p->next != NULL){
        p = p->next;
    }
    head = p;

    while(temp!=NULL){
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p = temp;
    }

    return head;
}

int main(){
    int menucheck=1 , menucontrol;
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    Create(head);

    while(menucheck == 1){
        printf("\nEnter : \n1) To Insert at start");
        printf("\n2) To Insert at End");
        printf("\n3) To Insert in Middle");
        printf("\n4) To Delete at Start");
        printf("\n5) To Delete at End");
        printf("\n6) To Delete at Middle");
        printf("\n7) To Reverse");
        printf("\n8) To Exit");

        printf("\n\nEnter your choice : ");
        scanf("%d",&menucontrol);

        switch (menucontrol)
        {
        case 1: head = Insert_Node(head);
                printf("\n");
                Display(head);
                break;

        case 2: Insert_end(head);
                printf("\n");
                Display(head);
                break;

        case 3: Insert_Mid(head);
                printf("\n");
                Display(head);
                break;
        
        case 4: head = delete_start(head);
                printf("\n");
                Display(head);
                break;

        case 5: Delete_end(head);
                printf("\n");
                Display(head);
                break;
    
        case 6: Delete_mid(head);
                printf("\n");
                Display(head);
                break;
        
        case 7: head = Reverse(head);
                printf("\n");
                Display(head);
                break;
        
        case 8: menucheck = 0;
                printf("\n Executed Successfully!");
                break;
        
        default: printf("\nYou have entered an Invalid choice");       
                 break;
        }
    }
    return 0;
}