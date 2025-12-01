#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d):data(d), prev(NULL), next(NULL){}
};

// assumes DLL is sorted ascending
void findPairs(DNode* head, int target){
    if(!head) return;
    DNode* left = head;
    DNode* right = head;
    while(right->next) right = right->next;

    bool found = false;
    while(left != right && right->next != left){
        int sum = left->data + right->data;
        if(sum == target){
            cout << "("<< left->data << "," << right->data << ") ";
            found = true;
            left = left->next;
            right = right->prev;
        } else if(sum < target) left = left->next;
        else right = right->prev;
    }
    if(!found) cout << "No pairs";
}

int main(){
    // sorted DLL: 1<->2<->3<->4<->5
    DNode* h = new DNode(1);
    h->next = new DNode(2); h->next->prev = h;
    h->next->next = new DNode(3); h->next->next->prev = h->next;
    h->next->next->next = new DNode(4); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(5); h->next->next->next->next->prev = h->next->next->next;

    findPairs(h, 6);
    return 0;
}
