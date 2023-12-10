// 1. Write a program that implements a circular doubly linked list, and allows the user to insert
// and delete elements from the list. The program should have the following functionality:
// (a) Insert an element at the beginning of the list.
// (b) Insert an element at the end of the list.
// (c) Insert an element at a specified position in the list.
// (d) Delete an element from the beginning of the list.
// (e) Delete an element from the end of the list.
// (f) Delete an element from a specified position in the list.
// (g) Print the contents of the list in forward and backward order.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtEnd(struct Node **head, int data)
{
    if (*head == NULL)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        struct Node *newNode = createNode(data);
        newNode->prev = (*head)->prev;
        newNode->next = *head;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void insertAtPosition(struct Node **head, int data, int position)
{
    if (position <= 0)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        struct Node *currentNode = *head;
        for (int i = 0; i < position - 1 && currentNode->next != *head; ++i)
        {
            currentNode = currentNode->next;
        }
        struct Node *newNode = createNode(data);
        newNode->prev = currentNode;
        newNode->next = currentNode->next;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;
    }
}

void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = (*head)->prev;
        (*head)->prev = temp->prev;
        temp->prev->next = *head;
        free(temp);
    }
}

void deleteFromPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (position <= 0)
    {
        deleteFromBeginning(head);
    }
    else
    {
        struct Node *currentNode = *head;
        for (int i = 0; i < position && currentNode->next != *head; ++i)
        {
            currentNode = currentNode->next;
        }
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        free(currentNode);
    }
}

void printForward(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *currentNode = head;
    do
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("\n");
}

void printBackward(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *currentNode = head->prev;
    do
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->prev;
    } while (currentNode != head->prev);
    printf("\n");
}
void displayMenu();
int main()
{
    struct Node *head = NULL, *temp, *newNode;
    int ch, data, position;

    while (1)
    {
        printf("\n Enter \n 1 Insert an element at the beginning of the list: \n 2 Insert an element at the end of the list: \n 3 Insert an element at a specified position in the list: \n 4 Delete an element from the beginning of the list: \n 5 Delete an element from the end of the list: \n 6 Delete an element from a specified position in the list: \n 7 Print the contents of the list in forward: \n 8 Print the contents of the list in backward order: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        // case 1:
        //     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        //     printf("Enter an data: ");
        //     scanf("%d", &newNode);
        //     newNode->next = NULL;
        //     newNode->prev = NULL;
        //     if (head == NULL)
        //     {
        //         head = temp = newNode;
        //     }
        //     temp->prev = newNode;
        //     newNode->next = temp;
        //     temp = newNode;
        //     break;
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert at: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
            break;
        case 4:
            deleteFromBeginning(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter position to delete from: ");
            scanf("%d", &position);
            deleteFromPosition(&head, position);
            break;
        case 7:
            printf("List in forward order: ");
            printForward(head);
            break;
        case 8:
            printf("List in backward order: ");
            printBackward(head);
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
