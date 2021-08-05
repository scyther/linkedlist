#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start;

void main()
{
    int option;
    void create();
    void traverse();
    void insertbeg();
    void insertEnd();
    void insertMid();
    void delete();
    while (1)
    {
        printf("\n\t\tMENU\n");
        printf("1: Create a Linked List\n");
        printf("2: Traverse Linked List\n");
        printf("3: Insert node in beginning \n");
        printf("4: Insert node in End \n");
        printf("5: Insert node in Mid \n");
        printf("6: Delete node \n");
        printf("\nEnter your option : ");
        scanf(" %d", &option);

        switch (option)
        {
        case 1:
            create();
            break;

        case 2:
            traverse();
            break;

        case 3:
            insertbeg();
            break;

        case 4:
            insertEnd();
            break;

        case 5:
            insertMid();
            break;
        
        case 6:
            delete();
            break;

        default:
            printf("Wrong Input");
        }
    }
}

void create()
{
    char choice;
    struct node *ptr, *nptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    start = ptr;
    printf("\nEnter the data : ");
    scanf("%d", &ptr->data);

    printf("Do you want to enter more nodes?  Y/N ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y')
    {
        nptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data = ");
        scanf("%d", &nptr->data);
        ptr->next = nptr;
        ptr = nptr;
        printf("Do you want to enter more nodes? Y/N ");
        scanf(" %c", &choice);
    }

    ptr->next = NULL;
}

void traverse()
{
    int i = 1;
    struct node *ptr;
    ptr = start;
    printf("\n");
    while (ptr != NULL)
    {
        printf("Element %d : %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

void insertbeg()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data to add: ");
    scanf("%d", &newNode->data);
    printf("here");
    newNode->next = start;
    start = newNode;
}

void insertEnd()
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Data to add: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    struct node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertMid(){
    int position;
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter Data to add: ");
    scanf("%d",&newNode->data);
    printf("\n Enter position to add: ");
    scanf("%d",&position);
    struct node *temp=start;
    for(int i=2 ; i < position ; i++){
        if(temp->next!=NULL){
            temp=temp->next;
        }
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void delete(){
    int position;
    struct node * temp=start;
    printf("Enter the position to delete: ");
    scanf("%d",&position);
    switch (position)
    {
    case 1:
        temp=temp->next;
        start=temp;
        break;
    
    default:
        for (int i = 2; i < position;  i++)
        {
            if (temp ->next!=NULL)
            {
                struct node* temp2;
                temp2=temp->next;
                
                
            }
            
        }
        
        break;
    }
}