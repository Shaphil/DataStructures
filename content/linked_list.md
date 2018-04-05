# Linked List

As the name suggests it's a linked data structure. What it means is that data in this data structure are linked to each other. It is a list where each data memeber has a link pointing to the next member in the list. The last member points to `NULL` indicating the end of the list.

## Video Presentation
You can watch this video from HackerRank. Author Gayle McDowell explains a bit and then demonstrates an implementation in Java.
<iframe width="560" height="315" src="https://www.youtube.com/embed/njTh_OwMljA?rel=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

## Basic Data member
The basic data member in a linked list is called a node. Each node contains some data and a pointer for pointing to the next node.

In C a node that holds integer type data might look like this
```c
struct node
{
    int data;
    Node *next;
    Node *back;
};
```

Or like this in C++ which will give you the advantage of holding any type of data
```c++
template <class T>
struct Node
{
    T data;
    Node *next;
    Node *prev;

    Node()
    {
        next = prev = nullptr;
    }

    Node(T data) : Node()
    {
        this->data = data;
    }
};
```

Please note that the nodes presented here are suited for a type of list called Doubly Linked List. They have some added benefits over their other counter part Singly Linked Lists. More on that later.

(To be completed later...)