#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void moveLastToFront(Node** head){
    if (*head == NULL || (*head)->next == NULL) return;

    Node* secondLast = NULL;
    Node* last = *head;

    while (last->next != NULL){
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->next = *head;
    *head = last;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, new Node{4, NULL}}}};
    moveLastToFront(&head);

    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
