#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, NULL}}}};
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    cout << slow->data;
}
