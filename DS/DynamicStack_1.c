// Stack using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *TOP = NULL;

struct node *getnode(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n[+] Cannot allocate memory");
        exit(0);
    }

    temp->data = val;
    temp->next = NULL;

    return temp;
}

void init()
{
    TOP = getnode(0);
}

void push(int val)
{
    struct node *temp = getnode(val);

    if (TOP->data == 0)
    {
        TOP->next = temp;
    }
    else
    {

        temp->next = TOP->next;
        TOP->next = temp;
    }
    TOP->data++;
}

void freeNode(struct node *f)
{
    free(f);
}

int pop()
{
    int out;
    struct node *temp = TOP->next;
    TOP->next = temp->next;
    out = temp->data;
    freeNode(temp);
    TOP->data--;

    return out;
}

int peek()
{
    return TOP->next->data;
}

void display()
{
    struct node *temp = TOP->next;

    printf("\n");
    while (temp != NULL)
    {
        printf("%d|", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayMenu()
{
    printf("\n------------------------------------------------");
    printf("\n[+] 1. Display\n[+] 2. Push\n[+] 3. Pop\n[+] 4. Peek\n[+] 5. Exit\n");
    printf("\n[+] Select an option: ");
}

int main()
{
    int n;
    int value;

    init();

    do
    {
        displayMenu();
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            display();
            break;

        case 2:
            printf("\n[+] Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            display();
            break;

        case 3:
            value = pop();
            printf("\n[+] Popped value is: %d", value);
            // display();
            break;

        case 4:
            printf("\n[+] Value on top of the stack is: %d", peek());
            // display();
            break;

        case 5:
            printf("\n[+] Ciao!");
            exit(0);

        default:
            printf("\n[+] Invalid option!");
        }
    } while (n != 5);

    return 0;
}