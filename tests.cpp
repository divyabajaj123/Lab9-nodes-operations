#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "NodeOperations.h"

Email makeEmail(string sender, string receiver, string message)
{
    DateTime d = DateTime(3, 9, 2026, 10, 30, 0);
    return Email(sender, receiver, d, message);
}

int listLength(Node* head)
{
    int count = 0;
    for (Node* t = head; t != nullptr; t = t->next)
        count++;
    return count;
}

Node* getNodeAt(Node* head, int pos)
{
    Node* t = head;
    for(int i = 1; t!=nullptr && i < pos; i++, t=t->next);

    return t;

}

Node* getLastNode(Node* head)
{
    if (head == nullptr) return nullptr;

    Node* t = head;
    while (t->next != nullptr)
    {
        t = t->next;
    }
    return t;
}

bool emailEquals(Email e1, Email e2)
{
    return (e1.getSender() == e2.getSender()) && (e1.getReceiver() == e2.getReceiver()) && (e1.getMessage() == e2.getMessage());
}

// ---------- Tests for insertThird ----------
TEST_CASE("insertThird inserts as third node in a list with at least two nodes")
{
    Node* head = nullptr;

    Email e1 = makeEmail("a1@x.com", "b1@x.com", "msg1");
    Email e2 = makeEmail("a2@x.com", "b2@x.com", "msg2");
    Email e3 = makeEmail("a3@x.com", "b3@x.com", "msg3");
    Email e4 = makeEmail("a4@x.com", "b4@x.com", "msg4");

    Node* n1 = new Node(e1);
    Node* n2 = new Node(e2);
    Node* n3 = new Node(e3);
    Node* n4 = new Node(e4);

    n1->next=n2; n2->next=n3; n3->next=n4; n4->next=nullptr;
    head = n1;

    Email inserted = makeEmail("new@x.com", "dest@x.com", "inserted");
    insertThird(head, inserted);

    REQUIRE(listLength(head) == 5);

    Node* third = getNodeAt(head, 3);
    Node* fourth = getNodeAt(head, 4);
    Node* last = getLastNode(head);

    REQUIRE(third != nullptr);
    REQUIRE(fourth != nullptr);
    REQUIRE(last != nullptr);

    // Check email in third node after insert
    REQUIRE(emailEquals(third->data, inserted));

    // Check email in fourth node after insert
    REQUIRE(emailEquals(fourth->data, e3));

    // Check last node always points to nullptr
    REQUIRE(last->next == nullptr);

    deleteNodes(head);
}

TEST_CASE("insertThird appends at end when list has exactly one node")
{
    Node* head = nullptr;

    Email e1 = makeEmail("a1@x.com", "b1@x.com", "msg1");

    Node* n1 = new Node(e1);
    n1->next = nullptr;
    head = n1;

    Email inserted = makeEmail("new@x.com", "dest@x.com", "inserted");
    insertThird(head, inserted);

    REQUIRE(listLength(head) == 2);

    Node* first = getNodeAt(head, 1);
    Node* second = getNodeAt(head, 2);
    Node* last = getLastNode(head);

    REQUIRE(first != nullptr);
    REQUIRE(second != nullptr);
    REQUIRE(last != nullptr);

    REQUIRE(emailEquals(first->data, e1));
    REQUIRE(emailEquals(second->data, inserted));
    REQUIRE(last->next == nullptr);

    deleteNodes(head);
}

TEST_CASE("insertThird works when list is empty")
{
    Node* head = nullptr;

    Email inserted = makeEmail("new@x.com", "dest@x.com", "inserted");
    insertThird(head, inserted);

    REQUIRE(listLength(head) == 1);

    Node* first = getNodeAt(head, 1);
    Node* last = getLastNode(head);

    REQUIRE(first != nullptr);
    REQUIRE(last != nullptr);

    REQUIRE(emailEquals(first->data, inserted));
    REQUIRE(last->next == nullptr);

    deleteNodes(head);
}

// ---------- Tests for deleteFourth ----------

TEST_CASE("deleteFourth removes the fourth node when it exists")
{
    Node* head = nullptr;

    Email e1 = makeEmail("a1@x.com", "b1@x.com", "msg1");
    Email e2 = makeEmail("a2@x.com", "b2@x.com", "msg2");
    Email e3 = makeEmail("a3@x.com", "b3@x.com", "msg3");
    Email e4 = makeEmail("a4@x.com", "b4@x.com", "msg4");
    Email e5 = makeEmail("a5@x.com", "b5@x.com", "msg5");

    Node* n1 = new Node(e1);
    Node* n2 = new Node(e2);
    Node* n3 = new Node(e3);
    Node* n4 = new Node(e4);
    Node* n5 = new Node(e5);

    n1->next=n2; n2->next=n3; n3->next=n4; n4->next=n5; n5->next=nullptr;
    head = n1;

    deleteFourth(head);

    REQUIRE(listLength(head) == 4);

    Node* first = getNodeAt(head, 1);
    Node* second = getNodeAt(head, 2);
    Node* third = getNodeAt(head, 3);
    Node* fourth = getNodeAt(head, 4);
    Node* last = getLastNode(head);

    REQUIRE(first != nullptr);
    REQUIRE(second != nullptr);
    REQUIRE(third != nullptr);
    REQUIRE(fourth != nullptr);
    REQUIRE(last != nullptr);

    REQUIRE(emailEquals(first->data, e1));
    REQUIRE(emailEquals(second->data, e2));
    REQUIRE(emailEquals(third->data, e3));
    REQUIRE(emailEquals(fourth->data, e5));
    REQUIRE(last->next == nullptr);

    deleteNodes(head);
}

TEST_CASE("deleteFourth does nothing when list has fewer than four nodes")
{
    Node* head = nullptr;

    Email e1 = makeEmail("a1@x.com", "b1@x.com", "msg1");
    Email e2 = makeEmail("a2@x.com", "b2@x.com", "msg2");
    Email e3 = makeEmail("a3@x.com", "b3@x.com", "msg3");

    Node* n1 = new Node(e1);
    Node* n2 = new Node(e2);
    Node* n3 = new Node(e3);

    n1->next=n2; n2->next=n3; n3->next=nullptr;
    head = n1;

    deleteFourth(head);

    REQUIRE(listLength(head) == 3);

    Node* first = getNodeAt(head, 1);
    Node* second = getNodeAt(head, 2);
    Node* third = getNodeAt(head, 3);
    Node* last = getLastNode(head);

    REQUIRE(first != nullptr);
    REQUIRE(second != nullptr);
    REQUIRE(third != nullptr);
    REQUIRE(last != nullptr);

    REQUIRE(emailEquals(first->data, e1));
    REQUIRE(emailEquals(second->data, e2));
    REQUIRE(emailEquals(third->data, e3));
    REQUIRE(last->next == nullptr);

    deleteNodes(head);
}


