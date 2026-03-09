#include "utils.h"

class Node{
    public:
    Email data;
    Node* next;

    Node(Email e): data(e), next(nullptr) {}
};

void deleteNodes(Node* head)
{
    for(Node* t = head; t != nullptr;)
    {
        Node* x;
        x = t->next;
        delete t;
        t = x;
    }
}

// Insert Email e as the third node in the list starting at head. If list contains less than two nodes, simply insert at the end of the list.
void insertThird(Node* &head, Email e)
{

}

// delete the fourth node in the list. If list contains less than four nodes, do not delete anything
void deleteFourth(Node* &head)
{

}