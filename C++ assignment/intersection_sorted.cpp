#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* intersection(Node* a, Node* b){
    Node* result = NULL;
    Node* tail = NULL;

    while(a && b){
        if(a->data == b->data){
            Node* temp = new Node{a->data, NULL};
            if(result == NULL) result = tail = temp;
            else{ tail->next = temp; tail = temp; }
            a = a->next;
            b = b->next;
        }
        else if(a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return result;
}
