#include <stdio.h>
#include <stdlib.h>


typedef struct _node Node;
struct _node
{
    int data;
    Node *next;
    Node *prev;
};

typedef struct _list LinkedList;
struct _list
{
    Node *head;
    Node *last;
};

// functions related to Nodes
Node* new_node(int data);

// functions related to Linked List
void init_list(LinkedList **list);
void append(LinkedList **list, int data);

// Test functions
void _log(const char *message);
LinkedList* get_initialized_list();
void append_test();
void hr(int size, int newline);



int main()
{
    append_test();

    return 0;
}


// ---------------- Begin Tests ----------------

void _log(const char *message)
{
    printf("\t\t%s\n", message);
    hr(48, 1);
}

LinkedList* get_initialized_list()
{
    LinkedList *list = NULL;
    init_list(&list);
    return list;
}

void append_test()
{
    _log("Append Test");

    LinkedList *list = get_initialized_list();

    for (int i = 0; i < 10; i++)
        append(&list, 2 * i + 2);

    printf("in order: ");
    print(&list);
    printf("reversed: ");
    print_reverse(&list);
    hr(48, 1);
}

void hr(int size, int newline)
{
    for (int i = 0; i < size; i++)
        printf("-");

    if (newline)
        printf("\n");
}

// ---------------- End Tests   ----------------




// ---------------- Linked list ----------------

// create a new node with given data
Node* new_node(int data)
{
    Node *node = malloc(sizeof(*node));
    node->data = data;
    node->next = node->prev = NULL;

    return node;
}

// allocate memory for our list
void init_list(LinkedList **list)
{
    *list = malloc(sizeof(**list));
    (*list)->head = (*list)->last = NULL;
}

void append(LinkedList **list, int data)
{
    if (*list) {
        Node *node = new_node(data);

        // if list is empty
        if (!(*list)->head)
            (*list)->head = (*list)->last = node;
        else {
            (*list)->last->next = node;
            node->prev = (*list)->last;
            (*list)->last = node;
        }
    }
}

void print(LinkedList **list)
{
    Node *it = (*list)->head;
    while (it) {
        printf("%d ", it->data);
        it = it->next;
    }
    printf("\n");
}

void print_reverse(LinkedList **list)
{
    Node *it = (*list)->last;
    while (it) {
        printf("%d ", it->data);
        it = it->prev;
    }
    printf("\n");
}
