#include <iostream>
using namespace std;

struct DNode { int data; DNode* prev; DNode* next; DNode(int d):data(d),prev(NULL),next(NULL){} };

// count triplets in sorted DLL with sum == X
int countTriplets(DNode* head, int X){
    if(!head) return 0;
    int count = 0;

    // get tail
    DNode* tail = head;
    while(tail->next) tail = tail->next;

    for(DNode* first = head; first; first = first->next){
        DNode* left = first->next;
        DNode* right = tail;
        while(left && right && left != right && right->next != left){
            int sum = first->data + left->data + right->data;
            if(sum == X){
                count++;
                left = left->next;
                right = right->prev;
            } else if(sum < X) left = left->next;
            else right = right->prev;
        }
    }
    return count;
}

int main(){
    // sorted DLL: 1<->2<->4<->5<->6
    DNode* h = new DNode(1);
    h->next = new DNode(2); h->next->prev = h;
    h->next->next = new DNode(4); h->next->next->prev = h->next;
    h->next->next->next = new DNode(5); h->next->next->next->prev = h->next->next;
    h->next->next->next->next = new DNode(6); h->next->next->next->next->prev = h->next->next->next;

    cout << countTriplets(h, 10); // example
    return 0;
}
