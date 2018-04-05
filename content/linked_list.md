# Linked List

As the name suggests it's a linked data structure. What it means is that data in this data structure are linked to each other. It is a list where each data memeber has a link pointing to the next member in the list. The last member points to `NULL` indicating the end of the list.

## Video Presentation
You can watch this video from HackerRank. Author Gayle McDowell explains a bit and then demonstrates an implementation in Java.
<iframe width="800" height="450" src="https://www.youtube.com/embed/njTh_OwMljA?rel=0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

## Basic Data member
The basic data member in a linked list is called a node. Each node contains some data and a pointer for pointing to the next node.

In C a node that holds integer type data might look like this
```c
typedef struct node Node;
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

## Creating the list - Adding node
The linked list is a collection of nodes that are linked to each other. The links don't appear magically, you have to create them yourself. But don't worry, once you understand what you need to do in order to create a list, it will be a piece of cake for you.

You always keep a pointer to a node called the head. It is called the head because that is what it really is. Its job is to point to the first node in the list. No matter what, never lose your head (even in real life). Because that is how you keep track of the list. In the beginning the head points to nothing or `null` to be precise. The very first time you add to your list, you consider that node as the head or in other words, you make your head pointer point to that node. In subsequent additions you add after the node you just added. Usually the only thing you know about the last node is that it points to `null`. There is no other way to know who the last node in the list is as you keep track of the head only. Therefore you have to loop through the list to find out the last node and add after it. Now how exactly do you add node after node? Every node contains a pointer remember? You just tell the last node to point to the new node you brought to the list. Easy right?

Here's the code to add a node
```c
// C code to add node
```
