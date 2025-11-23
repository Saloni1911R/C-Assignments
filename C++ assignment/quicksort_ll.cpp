#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd){
    Node* pivot = end;
    Node* prev = NULL;
    Node* curr = head;
    Node* tail = pivot;

    while(curr != pivot){
        if(curr->data < pivot->data){
            if(*newHead == NULL) *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if(prev) prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if(*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end){
    if(!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if(newHead != pivot){
        Node* temp = newHead;
        while(temp->next != pivot) temp = temp->next;
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = newHead;
        while(temp->next) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

Node* quickSort(Node* head){
    Node* end = head;
    while(end->next) end = end->next;
    return quickSortRecur(head, end);
}
