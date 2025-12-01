#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d):data(d), next(NULL){}
};

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* cur = head;
    while(cur){
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(!head || !head->next) return true;

    // find middle
    Node *slow = head, *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    Node* second = reverseList(slow->next);
    Node* p1 = head, *p2 = second;
    bool ok = true;
    while(p2){
        if(p1->data != p2->data){ ok = false; break; }
        p1 = p1->next;
        p2 = p2->next;
    }

    // restore (optional)
    slow->next = reverseList(second);
    return ok;
}

int main(){
    // create list 1->2->3->2->1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    return 0;
}
