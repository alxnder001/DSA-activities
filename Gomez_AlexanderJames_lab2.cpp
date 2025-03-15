#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    string artist;
    Node* next;
};

Node* createNode(const string &song, const string &artist) {
    Node* newNode = new Node;
    newNode->song = song;
    newNode->artist = artist;
    newNode->next = NULL;
    return newNode;
}

void traverse(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->song << " by " << current->artist << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void traverseCircular(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    do {
        cout << current->song << " by " << current->artist << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(back to head)" << endl;
}

void insertAtEnd(Node* &head, const string &song, const string &artist) {
    Node* newNode = createNode(song, artist);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtBeginning(Node* &head, const string &song, const string &artist) {
    Node* newNode = createNode(song, artist);
    newNode->next = head;
    head = newNode;
}

void insertAfter(Node* prevNode, const string &song, const string &artist) {
    if (prevNode == NULL) {
        cout << "Previous node cannot be NULL." << endl;
        return;
    }
    Node* newNode = createNode(song, artist);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

Node* findNode(Node* head, const string &song) {
    Node* current = head;
    while (current != NULL) {
        if (current->song == song)
            return current;
        current = current->next;
    }
    return NULL;
}

void deleteFromEnd(Node* &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteFromBeginning(Node* &head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteGivenNode(Node* &head, const string &song) {
    if (head == NULL) return;
    if (head->song == song) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->song != song)
        temp = temp->next;
    if (temp->next == NULL) {
        cout << "Song not found: " << song << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void convertToCircular(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head;
}

int main() {
    Node* head = NULL;
    insertAtEnd(head, "Circles", "Post Malone");
    insertAtEnd(head, "Is There Someone Else?", "The Weeknd");
    insertAtEnd(head, "Blinding Lights", "The Weeknd");
    insertAtBeginning(head, "Sunflower", "Post Malone");
    insertAtBeginning(head, "Luther", "Kendrick Lamar and SZA");
    insertAtBeginning(head, "All the Stars", "Kendrick Lamar and SZA");
    insertAtBeginning(head, "30 for 30", "Kendrick Lamar and SZA");
    
    Node* favTail = findNode(head, "Sunflower");
    if (favTail != NULL) {
        insertAfter(favTail, "7 11", "Toneejay");
        insertAfter(favTail->next, "Kay Tagal Kitang Hinintay", "Sponge Cola");
        insertAfter(favTail->next->next, "Tropa", "Siakol");
    } else {
        cout << "Favorite song node not found." << endl;
    }
    
    cout << "Linked List after insertions:" << endl;
    traverse(head);
    
    deleteFromEnd(head);
    deleteFromBeginning(head);
    deleteGivenNode(head, "Blinding Lights");
    
    cout << "\nLinked List after deletions:" << endl;
    traverse(head);
    
    convertToCircular(head);
    cout << "\nCircular Linked List:" << endl;
    traverseCircular(head);
    
    return 0;
}
