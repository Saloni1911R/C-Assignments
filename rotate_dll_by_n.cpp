#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int d):data(d),prev(NULL),next(NULL){} };

// rotate left by n (move first n nodes to end)
DNode* rotateByN(DNode* head, int n){
    if(!head || n==0) return head;

    // find length and tail
    int len = 1;
    DNode* tail = head;
    while(tail->next){ tail = tail->next; len++; }

    n = n % len;
    if(n==0) return head;

    DNode* cut = head;
    for(int i=1;i<n;i++) cut = cut->next;

    DNode* newHead = cut->next;
    newHead->prev = NULL;
    cut->next = NULL;

    tail->next = head;
    head->prev = tail;

    return newHead;
}

int main(){
    // 1<->2<->3<->4<->5 rotate by 2 -> 3 4 5 1 2
    DNode* h = new DNode(1);
    h->next = new DNode(2); h->next->prev = h;
    h->next->next = new DNode(3); h->next->next->prev = h->next;
    h->next->next->next = new DNode(4); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(5); h->next->next->next->next->prev = h->next->next->next;

    h = rotateByN(h, 2);
    DNode* t=h;
    while(t){ cout<<t->data<<" "; t=t->next; }
    return 0;
}
