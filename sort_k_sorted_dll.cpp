#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int d):data(d),prev(NULL),next(NULL){} };

// Simple insertion sort on doubly linked list
// For k-sorted list insertion sort runs in O(n*k)
DNode* sortKSorted(DNode* head){
    if(!head) return head;
    DNode* curr = head->next;
    while(curr){
        DNode* next = curr->next;
        DNode* pos = curr->prev;

        // detach curr
        while(pos && pos->data > curr->data) pos = pos->prev;

        // place curr after pos
        if(curr->prev && curr->prev->next == curr) curr->prev->next = curr->next;
        if(curr->next) curr->next->prev = curr->prev;

        if(!pos){
            // insert at head
            curr->next = head;
            curr->prev = NULL;
            head->prev = curr;
            head = curr;
        } else {
            curr->next = pos->next;
            curr->prev = pos;
            pos->next = curr;
            if(curr->next) curr->next->prev = curr;
        }
        curr = next;
    }
    return head;
}

int main(){
    // example k-sorted DLL: 3, 6, 2, 12, 56, 8  (k small)
    DNode* h = new DNode(3);
    h->next = new DNode(6); h->next->prev = h;
    h->next->next = new DNode(2); h->next->next->prev = h->next;
    h->next->next->next = new DNode(12); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(56); h->next->next->next->next->prev = h->next->next->next;
    h->next->next->next->next->next = new DNode(8); h->next->next->next->next->next->prev = h->next->next->next->next;

    h = sortKSorted(h);

    DNode* t=h;
    while(t){ cout<<t->data<<" "; t=t->next; }
    return 0;
}
