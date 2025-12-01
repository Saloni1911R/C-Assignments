#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d):data(d), next(NULL){}
};

// delete first occurrence of key
Node* deleteNode(Node* head, int key){
    if(!head) return NULL;

    // single node
    if(head->next == head){
        if(head->data == key){ delete head; return NULL; }
        return head;
    }

    Node *curr = head, *prev = NULL;
    // find node to delete
    do{
        if(curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while(curr != head);

    if(curr->data != key) return head; // not found

    if(curr == head){
        // find tail to update its next
        Node* tail = head;
        while(tail->next != head) tail = tail->next;
        tail->next = head->next;
        head = head->next;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
    return head;
}

int main(){
    // build circular: 1->2->3->1
    Node* h = new Node(1);
    h->next = new Node(2);
    h->next->next = new Node(3);
    h->next->next->next = h;

    h = deleteNode(h, 2); // delete node with value 2

    if(h){
        Node* t = h;
        do{
            cout << t->data << " ";
            t = t->next;
        } while(t != h);
    }
    return 0;
}
