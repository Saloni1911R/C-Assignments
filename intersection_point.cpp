#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int getLength(Node* head){
    int c = 0;
    while(head){ c++; head = head->next; }
    return c;
}

Node* getIntersection(Node* a, Node* b){
    int l1 = getLength(a);
    int l2 = getLength(b);

    int diff = abs(l1 - l2);

    if(l1 > l2)
        while(diff--) a = a->next;
    else
        while(diff--) b = b->next;

    while(a && b){
        if(a == b) return a;
        a = a->next;
        b = b->next;
    }

    return NULL;
}
