#include <iostream>
using namespace std;

struct Node {
    string songName;
    Node *link;
};

Node *createNode(string data) {
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    return newNode;
}

void traverse(Node *head) {
    Node *temp = head;
    cout << "My Playlist:" << endl;
    while (temp != NULL) {
        cout << temp->songName << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

Node *insertAtEnd(string data, Node *head) {
    if (head == NULL) {
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end\n";
        return head;
    }
    
    Node *temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end\n";
    return head;
}

Node *insertAtBeginning(string data, Node *head) {
    Node *newNode = createNode(data);
    newNode->link = head;
    head = newNode;
    
    cout << "A new node has been inserted at the beginning\n";
    return head;
}

Node *insertAfter(string after, string data, Node *head) {
    Node *temp = head;
    
    while (temp != NULL && temp->songName != after) {
        temp = temp->link;
    }
    
    if (temp == NULL) {
        cout << "No such song exists, please try again later.\n";
        return head;
    }
    
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    cout << "A new node has been added after " << after << "\n";
    return head;
}

int main() {
    Node *head = NULL;

    head = insertAtEnd("Circle by Post Malone", head);
    head = insertAtEnd("Is There Someone Else by The Weeknd", head);
    head = insertAtEnd("Blinding Lights by The Weeknd", head);
    head = insertAtBeginning("All the Stars by SZA", head);
    head = insertAtBeginning("Saturn by SZA", head);
    head = insertAtBeginning("Luther by Kendrick Lamar & SZA", head);
    head = insertAtBeginning("30 FOR 30 by Kendrick Lamar & SZA", head);
    head = insertAfter("Tadhana by Up Dharma", "All the Stars by SZA", head);
    head = insertAfter("Buwan by Juan Karlos", "Saturn by SZA", head);
    head = insertAfter("Kathang Isip by Ben&Ben", "Luther by Kendrick Lamar & SZA", head);

    traverse(head);

    return 0;
}