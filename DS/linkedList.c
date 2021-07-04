#include <stdio.h>
#include <stdlib.h>

struct node *HEAD = NULL;

struct node
{
    int data;
    struct node *next;
};

struct node *getNode(int value)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void init()
{
    // creating a header node
    HEAD = getNode(0);
    HEAD->next = NULL;
}

void append(int value)
{
    struct node *temp = HEAD;

    // if list is empty
    if (temp->next == NULL)
    {
        temp->next = getNode(value);
        HEAD->data++;
        return;
    }

    // traverse to the end
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = getNode(value);
    HEAD->data++;
}

void insert(int n, int value)
{
    struct node *p = HEAD;
    struct node *q = p->next;
    struct node *temp = NULL;

    // check position
    if (n > p->data || n <= 0)
    {
        printf("\n[+] Invalid position passed to Insert function!");
        return;
    }

    // traverse to the required pos
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    temp = getNode(value);
    temp->next = q;
    p->next = temp;
    HEAD->data++;
}

void freeNode(struct node *p)
{
    free(p);
}

void delete (int n)
{
    struct node *p = HEAD;
    struct node *q = p->next;
    struct node *temp = NULL;

    // check position
    if (n > p->data || n <= 0)
    {
        printf("\n[+] Invalid position passed to Delete function!");
        return;
    }

    // traverse to the required pos
    for (int i = 1; i < n; i++)
    {
        p = p->next;
        q = q->next;
    }
    temp = q;
    p->next = q->next;
    freeNode(temp);
    HEAD->data--;
}

void display()
{
    struct node *temp = HEAD;

    // if list is empty
    if (temp->next == NULL)
    {
        printf("\n[+] The list is empty");
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
    printf("\n[+] 1. Display\n[+] 2. Append\n[+] 3. Insert\n[+] 4.Delete\n[+] 5. Exit\n");
    printf("\n[+] Select an option: ");
}

int main()
{
    int n;
    int value;
    int pos;

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
            printf("\n[+] Enter the value to append: ");
            scanf("%d", &value);
            append(value);
            display();
            break;

        case 3:
            printf("\n[+] Enter the position followed by value: ");
            scanf("%d %d", &pos, &value);
            insert(pos, value);
            display();
            break;

        case 4:
            printf("\n[+] Enter the position to delete: ");
            scanf("%d", &pos);
            delete (pos);
            display();
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