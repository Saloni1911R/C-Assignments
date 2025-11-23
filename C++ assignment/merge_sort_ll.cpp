#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* mergeLists(Node* a, Node* b){
    if(!a) return b;
    if(!b) return a;

    if(a->data < b->data){
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* mergeSort(Node* head){
    if(!head || !head->next) return head;

    Node* mid = findMid(head);
    Node* second = mid->next;
    mid->next = NULL;

    return mergeLists(mergeSort(head), mergeSort(second));
}
