#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// top === HEAD
struct node *top;

struct node *getnode(int val)
{
    struct node *temp = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\n[+] Cannot allocate memory");
        exit(0);
    }
    else
    {
        temp->data = val;
        temp->next = NULL;
        return temp;
    }
}

void init()
{
    top = getnode(0);
    printf("\n[+] Stack initialized");
}

void freeNode(struct node *p)
{
    free(p);
}

void push(int val)
{
    struct node *temp = NULL;

    temp = getnode(val);
    temp->next = top->next;
    top->next = temp;
    top->data++;
}

int pop()
{
    struct node *temp = NULL;
    struct node *p = NULL;
    int val;

    temp = top->next->next;
    p = top->next;
    val = p->data;
    top->next = temp;
    freeNode(p);
    top->data--;

    return val;
}

int peek()
{
    return top->next->data;
}

void display()
{
    struct node *temp = top;

    // if list is empty
    if (temp->next == NULL)
    {
        printf("\n[+] Stack Underflow");
        return;
    }

    // to skip header count
    temp = temp->next;

    printf("\n------------------------------------------------\n");
    while (temp != NULL)
    {
        printf("%d|", temp->data);
        temp = temp->next;
    }
    printf("\n------------------------------------------------\n");
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