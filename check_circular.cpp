#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

bool isCircular(Node* head){
    if(!head) return true;

    Node* temp = head->next;
    while(temp && temp != head)
        temp = temp->next;

    return (temp == head);
}
