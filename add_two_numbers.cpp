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

Node* addTwoLists(Node* l1, Node* l2){
    l1 = reverse(l1);
    l2 = reverse(l2);

    int carry = 0;
    Node* res = NULL;

    while(l1 || l2 || carry){
        int sum = carry;
        if(l1){ sum += l1->data; l1 = l1->next; }
        if(l2){ sum += l2->data; l2 = l2->next; }

        carry = sum / 10;
        Node* node = new Node{sum % 10, res};
        res = node;
    }

    return res;
}

int main(){
    Node* a = new Node{3, new Node{4, new Node{5, NULL}}};
    Node* b = new Node{4, new Node{6, NULL}};
    Node* c = addTwoLists(a, b);

    while(c){
        cout << c->data;
        c = c->next;
    }
}
