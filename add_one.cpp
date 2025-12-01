#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node* addOne(Node* head){
    head = reverse(head);

    Node* temp = head;
    int carry = 1;

    while(temp){
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if(!temp->next && carry){
            temp->next = new Node{carry, NULL};
            break;
        }
        temp = temp->next;
    }

    return reverse(head);
}

int main(){
    Node* head = new Node{9, new Node{9, new Node{9, NULL}}};
    head = addOne(head);

    while(head){
        cout << head->data;
        head = head->next;
    }
}
