#include <stdio.h>
#include <stdlib.h>
void Insert_Beg();
void Insert_End();
void Insert_after_Node();
void Delete_Beg();
void Delete_End();
void Delete_Node();
void Display();
struct node
{
    int data;
    struct node * prev;
    struct node * next;
};
struct node * start = NULL;
int main()
{   int ch;
    do{
        printf("\nDOUBLY LINKED LIST OPERATION:");
        printf("\n1. Insertion at beginning");
        printf("\n2. Insertion at end");
        printf("\n3. Insertion after a given node");
        printf("\n4. Deletion at beginning");
        printf("\n5. Deletion at end");
        printf("\n6. Deletion of a given node");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                Insert_Beg();
                break;
            case 2:
                Insert_End();
                break;
            case 3:
                Insert_after_Node();
                break;
            case 4:
                Delete_Beg();
                break;
            case 5:
                Delete_End();
                break;
            case 6:
                Delete_Node();
                break;
            case 7:
                break;
            default:
                printf("\nWrong choice...");
        }
    }while (ch != 7);
    return 0;
}
void Insert_Beg()
{  struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {   ptr->prev = NULL;
        ptr->next = NULL;
        int ele;
        printf("\nEnter element to be inserted: ");
        scanf("%d", &ele);
        ptr->data = ele;
        if(start != NULL)
           { ptr->next = start;
             start->prev = ptr;
             start = ptr;
           }
        start = ptr;
    }
    Display();
}
void Insert_End()
{   struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {   ptr->prev = NULL;
        ptr->next = NULL;
        int ele;
        printf("\nEnter element to be inserted: ");
        scanf("%d", &ele);
        ptr->data = ele;
        if (start == NULL)
        {
            start = ptr;
        }
        else
        {
            struct node* temp;
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
        }
    }
    Display();
}
void Insert_after_Node()
{   struct node* ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nOverflow\n");
        return;
    }
    else if(start == NULL)
    {
        printf("\nNo nodes");
    }
    else
    {   ptr->prev = NULL;
        ptr->next = NULL;
        int ele, item;
        printf("\nEnter element to be inserted: ");
        scanf("%d", &ele);
        printf("\nEnter item after which element is to be inserted: ");
        scanf("%d", &item);
        ptr->data = ele;
        struct node *temp;
        temp = start;
        while (temp->data != item && temp != NULL)
        {
            temp = temp->next;
        }
        ptr->prev = temp;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        temp->next = ptr;
    }
    Display();
}
void Delete_Beg()
{
    if(start == NULL)
    {
        printf("\nUnderflow...\n");
        return;
    }
    else
    {
        int ele = start->data;
        if(start->next == NULL)
            start = NULL;
        else
           { start = start->next;
             start->prev = NULL;
           }
        printf("\n%d was deleted", ele);
    }
    Display();
}

void Delete_End()
{
    if(start == NULL)
    {
        printf("\nUnderflow...\n");
        return;
    }
    else
    {  int ele;
        struct node* temp = start;
        if(start->next==NULL)
        { ele=start->data;
          start=NULL;
        }
        else
        { while(temp->next->next != NULL)
            {
               temp = temp->next;
            }
          ele = temp->next->data;
          temp->next = NULL;
        }
        printf("\n%d was deleted", ele);
    }
    Display();
}

void Delete_Node()
{
    if(start == NULL)
    {
        printf("\nUnderflow...\n");
        return;
    }
    else
    {
        int ele;
        printf("\nInsert element to be deleted: ");
        scanf("%d", &ele);
        struct node* temp = start;
        if(start->data==ele )
        { ele=start->data;
          start=start->next;
        }
        else {
        while(temp->next->data != ele)
        {
            temp = temp->next;
        }
        ele = temp->next->data;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        }
        printf("\n%d was deleted", ele);
    }
    Display();
}
void Display()
{   struct node* temp = start;
    printf("\nNow the list is:\n");
    if(start==NULL)
        printf("Empty\n");
    else
      { printf("! <--> ");
          while(temp != NULL)
          {
            printf("%d <--> ", temp->data);
            temp = temp->next;
          }
        printf("!\n");
      }
}
