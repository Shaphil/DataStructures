#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
struct _node
{
    int data;
    Node *next;
};

Node* init(int data);
Node* append(Node *head, int data);
Node* prepend(Node *head, int data);
Node* insert(Node *head, int data, int position);
Node* update(Node *head, int data, int position);
Node* reverse(Node *head);
Node* remove_first(Node *head);
Node* remove_last(Node *head);
Node* remove_from(Node *head, int position);
Node* merge(Node *first, Node *second);
int find(Node *head, int value);
int length(Node *head);
void print(Node *head);
void print_reverse(Node *head);
Node* free_head(Node *head);

// test functions
void _log(char *name);
void hr();
Node* append_n_nodes(Node *head, int count);
Node* prepend_n_nodes(Node *head, int count);
Node* append_n_nodes_and_print(Node *head, int count, int print_length);
Node* prepend_n_nodes_and_print(Node *head, int count, int print_length);
void print_list(Node *head, char *name, int print_length);
void append_test(Node *head);
void reverse_list_test(Node *head);
void insert_test(Node *head);
void prepend_test(Node *head);
void update_test(Node *head);
void remove_first_test(Node *head);
void remove_last_test(Node *head);
void remove_from_test(Node *head);
void find_test(Node *head);
void find_helper(Node *head, int value);
void merge_test();


// TODO: Break this into smaller files.

int main()
{
    Node *head = NULL;

    append_test(head);
    reverse_list_test(head);
    insert_test(head);
    prepend_test(head);
    update_test(head);
    remove_first_test(head);
    remove_last_test(head);
    remove_from_test(head);
    find_test(head);
    merge_test();

    return 0;
}

// Begin Tests

void _log(char *name)
{
    printf("\t\t%s Test\n", name);
    for (int i = 0; i < 48; i++)
        printf("-");
    printf("\n");
}

void hr()
{
    for (int i = 0; i < 48; i++)
        printf("-");
    printf("\n\n");
}

Node* append_n_nodes(Node *head, int count)
{
    for (int i = 0; i < count; i++)
        head = append(head, i + 1);
    return head;
}

Node* prepend_n_nodes(Node *head, int count)
{
    for (int i = 0; i < count; i++)
        head = prepend(head, i + 1);
    return head;
}

Node* append_n_nodes_and_print(Node *head, int count, int print_length)
{
    head = append_n_nodes(head, count);
    print_list(head, "original", print_length);

    return head;
}

Node* prepend_n_nodes_and_print(Node *head, int count, int print_length)
{
    head = prepend_n_nodes(head, count);
    print_list(head, "original", print_length);

    return head;
}

void print_list(Node *head, char *name, int print_length)
{
    if (print_length)
        printf("length: %d\n", length(head));

    printf("%s list: ", name);
    print(head);
}

void append_test(Node *head)
{
    _log("Append");

    head = append_n_nodes_and_print(head, 10, 0);
    printf("print reverse: ");
    print_reverse(head);
    hr();
}

void reverse_list_test(Node *head)
{
    _log("Reverse List");

    head = append_n_nodes_and_print(head, 10, 0);

    Node *reversed = reverse(head);
    print_list(reversed, "reversed", 0);
    print_list(reversed, "original", 0);
    hr();
}

void insert_test(Node *head)
{
    _log("Insert");

    head = append_n_nodes_and_print(head, 10, 1);

    head = insert(head, 2147483647, 7);
    print_list(head, "updated", 1);
    hr();
}

void prepend_test(Node *head)
{
    _log("Prepend");

    head = prepend_n_nodes_and_print(head, 10, 1);
    hr();
}

void update_test(Node *head)
{
    _log("Update");

    head = append_n_nodes_and_print(head, 10, 1);
    head = update(head, 2147483647, 8);
    print_list(head, "updated", 1);
    hr();
}

void remove_first_test(Node *head)
{
    _log("Remove First");

    head = append_n_nodes_and_print(head, 10, 0);
    printf("\nRemove all nodes from the beginning\n");
    while (head) {
        head = remove_first(head);
        print(head);
    }
    hr();
}

void remove_last_test(Node *head)
{
    _log("Remove Last");

    head = append_n_nodes_and_print(head, 10, 0);
    printf("\nRemove all nodes from the end\n");
    while (head) {
        head = remove_last(head);
        print(head);
    }
    hr();
}

void remove_from_test(Node *head)
{
    _log("Remove From");

    head = append_n_nodes_and_print(head, 10, 0);
    printf("\nRemove all nodes from the 3rd position\n");
    for (int i = 0; i < 10; i++) {
        head = remove_from(head, 3);
        print(head);
    }
    hr();
}

void find_test(Node *head)
{
    _log("Find");

    head = append_n_nodes_and_print(head, 10, 0);
    find_helper(head, 20);
    find_helper(head, 10);
    hr();
}

void find_helper(Node *head, int value)
{
    if (find(head, value))
        printf("%d found\n", value);
    else
        printf("%d not found\n", value);
}

void merge_test()
{
    _log("Merge");

    Node *first, *second, *merged;
    first = second = NULL;

    merged = merge(first, second);
    print_list(first, "First", 0);
    print_list(second, "Second", 0);
    print_list(merged, "Merged", 1);
    hr();

    second = append_n_nodes(second, 5);
    print_list(first, "First", 0);
    print_list(second, "Second", 0);
    merged = merge(first, second);
    print_list(merged, "Merged", 1);
    hr();

    second = NULL;
    first = append_n_nodes(first, 2);
    print_list(first, "First", 0);
    print_list(second, "Second", 0);
    merged = merge(first, second);
    print_list(merged, "Merged", 1);
    hr();

    second = append_n_nodes(second, 7);
    print_list(first, "First", 0);
    print_list(second, "Second", 0);
    merged = merge(first, second);
    print_list(merged, "Merged", 1);

    hr();
}

// End Tests

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

    if (position == len)
        head = append(head, data);
    else if (position == 0)
        head = prepend(head, data);
    else if (position > 0 && position < len) {
        len = 0;
        Node *current = head;

        while (len < position - 1) {
            current = current->next;
            len++;
        }

        Node *node = init(data);
        node->next = current->next;
        current->next = node;
    }
    return head;
}

Node* update(Node *head, int data, int position)
{
    int len = length(head);

    if (position > 0 && position <= len) {
        len = 0;
        Node *current = head;

        while(len < position - 1) {
            current = current->next;
            len++;
        }

        // update existing data
        current->data = data;
    }
    // return a possibly updated list
    return head;
}

Node* reverse(Node *head)
{
    Node *current = head;
    Node *reversed = NULL;

    // we create a new list and prepend each node of the current list to it
    // in that way we build a reversed list of the current list
    while (current) {
        reversed = prepend(reversed, current->data);
        current = current->next;
    }

    // and then simply return the reversed list
    return reversed;
}

// remove_first: remove a node from the top/beginning
Node* remove_first(Node *head)
{
    if (head)
        head = head->next;
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

// remove_last: removes the last node of the list
Node* remove_last(Node *head)
{
    int len = length(head);

    // there is only one node in the list
    if (len == 1)
        head = head->next;
    else if (len > 1) {
        Node *current = head;

        // we want the node before the last node
        while (current->next->next)
            current = current->next;

        current->next = NULL;
    }
    return head;
}

// remove_from(head, pos)
// remove a node from the specified position if possible
Node* remove_from(Node *head, int position)
{
    int len = length(head);

    if (position == 0)
        return remove_first(head);
    else if (position == len)
        return remove_last(head);
    else if (position > 0 && position < len) {
        int count = 1;
        Node *current = head;
        while (count < position) {
            current = current->next;
            count++;
        }
        current->next = current->next->next;
    }
    return head;
}

Node* merge(Node *first, Node *second)
{
    if (!first && !second)
        return NULL;
    else if (!first)
        return second;
    else if (!second)
        return first;
    else {
        Node *linker = first;
        while (linker->next)
            linker = linker->next;

        linker->next = second;
        return first;
    }
}

// find(head, value)
//      stops at the first match of value in head and returns 1
//      return 0 if value is not found
int find(Node *head, int value)
{
    if (head) {
        Node *current = head;
        while (current) {
            // found
            if (current->data == value)
                return 1;
            current = current->next;
        }
    }
    return 0;
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
