#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int d):data(d),prev(NULL),next(NULL){} };

// reverse k nodes starting from head, returns new head
DNode* reverseK(DNode* head, int k){
    DNode* cur = head;
    DNode* newHead = NULL;
    int cnt = 0;
    while(cur && cnt < k){
        DNode* nxt = cur->next;
        cur->next = newHead;
        if(newHead) newHead->prev = cur;
        cur->prev = NULL;
        newHead = cur;
        cur = nxt;
        cnt++;
    }
    // connect original head (now tail of group) to remaining
    head->next = cur;
    if(cur) cur->prev = head;
    return newHead;
}

DNode* rotateInGroups(DNode* head, int k){
    if(!head || k <= 1) return head;

    DNode* cur = head;
    DNode* newHead = NULL;
    DNode* prevTail = NULL;

    while(cur){
        // check count
        int cnt = 0;
        DNode* temp = cur;
        while(temp && cnt < k){ temp = temp->next; cnt++; }
        if(cnt < k){
            // less than k left — leave them as is
            if(!newHead) newHead = head;
            break;
        }
        // reverse this group
        DNode* nextGroup = cur;
        for(int i=0;i<k;i++) nextGroup = nextGroup->next;

        // reverse k nodes manually (like reverseK but preserving connections)
        DNode* subHead = NULL;
        DNode* subTail = cur;
        int c = 0;
        while(cur && c < k){
            DNode* nxt = cur->next;
            cur->next = subHead;
            if(subHead) subHead->prev = cur;
            cur->prev = NULL;
            subHead = cur;
            cur = nxt;
            c++;
        }

        // attach to result
        if(!newHead) newHead = subHead;
        if(prevTail){
            prevTail->next = subHead;
            subHead->prev = prevTail;
        }
        prevTail = subTail;
        cur = nextGroup;
    }

    return newHead;
}

int main(){
    // 1 2 3 4 5 6, k=3 => 3 2 1 6 5 4
    DNode* h = new DNode(1);
    h->next = new DNode(2); h->next->prev = h;
    h->next->next = new DNode(3); h->next->next->prev = h->next;
    h->next->next->next = new DNode(4); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(5); h->next->next->next->next->prev = h->next->next->next;
    h->next->next->next->next->next = new DNode(6); h->next->next->next->next->next->prev = h->next->next->next->next;

    h = rotateInGroups(h, 3);
    DNode* t = h;
    while(t){ cout<<t->data<<" "; t=t->next; }
    return 0;
}
