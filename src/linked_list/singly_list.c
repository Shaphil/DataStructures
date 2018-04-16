#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
struct _node
{
    int data;
    Node *next;
};

Node* init(int data)
{
    Node *node = malloc(sizeof(*node));
    node->data = data;
    node->next = NULL;

    return node;
}

Node* append(Node *head, int data)
{
    // create a new node with given data
    Node *node = init(data);

    // if head is empty, make the head point to the new node
    if (!head)
        head = node;
    else {
        // there is one or more node(s) in the list
        // iterate till the last node is found and
        // then add after it.
        Node *current = head;

        // this loop will break if current->next is NULL
        while (current->next)
            current = current->next;

        current->next = node;
    }

    // return updated list
    return head;
}

Node* prepend(Node *head, int data)
{
    Node *node = init(data);

    // add this new node to the beginning of the list
    // by making the current head of the list its next node
    node->next = head;

    // update the head and bring it back to its glory
    head = node;

    // return updated list
    return head;
}

Node* insert(Node *head, int data, int position)
{
    int len = length(head);

    if (position < len) {
        len = 0;
        Node *current = head;

        while (len < position) {
            current = current->next;
            len++;
        }

        Node *node = init(data);
        node->next = current->next;
        current->next = node;
    }
    return head;
}

int length(Node *head)
{
    int len = 0;
    while (head) {
        head = head->next;
        len++;
    }
    return len;
}

void print(Node *head)
{
    Node *current = head;
    // you go beyond the last node because you need to print its data
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_reverse(Node *head)
{
    Node *current = head;
    Node *reversed = NULL;

    // we create a new list and prepend each node of the current list to it
    // in that way we build a reversed list of the current list
    while (current) {
        reversed = prepend(reversed, current->data);
        current = current->next;
    }

    // and then simply print the reversed list
    print(reversed);
}

Node* free_head(Node *head)
{
    free(head);
    return NULL;
}

int main()
{
    Node *head = NULL;

    for (int i = 0; i < 10; i++)
        head = append(head, i + 1);

    printf("length: %d\n", length(head));
    print(head);

    head = insert(head, 2147483647, 5);
    printf("length: %d\n", length(head));
    print_reverse(head);

    head = free_head(head);

    for (int i = 0; i < 10; i++)
        head = prepend(head, i + 1);

    print(head);
    head = free_head(head);

    return 0;
}
