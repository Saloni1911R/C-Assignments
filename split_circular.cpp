#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void splitCircular(Node* head, Node** head1, Node** head2){
    if(!head) return;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }

    *head1 = head;
    if(head->next != head)
        *head2 = slow->next;

    fast->next = slow->next;
    slow->next = head;
}
