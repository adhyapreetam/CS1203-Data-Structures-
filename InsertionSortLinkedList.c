#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* start = NULL;


struct node* last = NULL;
struct node* temp;

struct node* createNode(int x)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addLast(int y)
{
    struct node* hodor = createNode(y);
    if(start == NULL)
    {
        start = hodor;
        last = hodor;
    }
    else
    {
        last->next = hodor;
        last = hodor;
    }
}

void printLinked()
{
    temp = start;
    while(temp->next != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void init(int size)
{
    int i, number;
    for( i = 0; i < size; i++ )
    {
        number = rand()%10000;
        addLast(number);
    }
}

void InsertionLinked()
{
    struct node* key;
    key = start;

    while(key != NULL)
    {
        temp = key->next;
        while(temp != NULL)
        {
            if(key->data > temp->data)
            {
                swapNode(key, temp);
            }
            temp = temp->next;
        }
        key = key->next;
    }
}

void swapNode(struct node *x, struct node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main()
{
    int choice;
    while( 1 == 1)
    {
        printf("\n How many numbers do you want to create ... ");
        scanf("%d", &choice);
        init(choice);
        InsertionLinked();
        printLinked();
    }

