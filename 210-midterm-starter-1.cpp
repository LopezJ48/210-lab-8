#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20; // constants

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;// allows you to traverse backwards
        Node* next;// allows you to traverse forward
        //Initializer
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head; // points to the first node in the linked list
    Node* tail; // points to the last node in the linked list

public:
//constructor making a empty list hence the nullptr
    DoublyLinkedList() { head = nullptr; tail = nullptr; }
        // function that works to instert a new node
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        // creates a new node and if the head is empty it will give head tail newnode the same value
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }
        // A loop that goes through the node 
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
            // if the loop exceeds the size of the list it will delete the node and return
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next; // This links a newnode with the next one in line
        newNode->prev = temp; // this links the new node to the last
        if (temp->next) // if it links then it will make a newnode
            temp->next->prev = newNode;
        else 
            tail = newNode;
        temp->next = newNode;
    }
        // deletes the values stored 
    void delete_val(int value) {
        if (!head) return; 

        Node* temp = head; //starts at the head node
        
        while (temp && temp->data != value) //loop through until it hits the position of said value
            temp = temp->next;

        if (!temp) return; // returns if temp value is not found 

        if (temp->prev)
            temp->prev->next = temp->next; // links the found value to the next node
        else
            head = temp->next; //replaces head node

        if (temp->next) // will link to next node if there is a next node 
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // else will change the tail

        delete temp; // deletes the temp node 
    }

    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
    
        if (pos == 1) {
            pop_front();
            return;
        }
    
        Node* temp = head;
    
        for (int i = 1; i < pos; i++){
            if (!temp) {
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next;
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
    
        if (!temp->next) {
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp;
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    
    void pop_front() {

        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;

        if (head->next) {
            head = head->next;
            head->prev = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        delete temp;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}