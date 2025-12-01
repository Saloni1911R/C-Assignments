#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d):data(d), prev(NULL), next(NULL){}
};

DNode* reverseDoubly(DNode* head){
    DNode* cur = head;
    DNode* temp = NULL;
    while(cur){
        // swap next and prev
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev; // because prev and next swapped
    }
    if(temp) head = temp->prev; // new head
    return head;
}

int main(){
    // build DLL 1<->2<->3
    DNode* head = new DNode(1);
    head->next = new DNode(2);
    head->next->prev = head;
    head->next->next = new DNode(3);
    head->next->next->prev = head->next;

    head = reverseDoubly(head);

    // print forward
    DNode* t = head;
    while(t){ cout << t->data << " "; t = t->next; }
    return 0;
}
