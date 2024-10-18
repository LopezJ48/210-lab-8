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

    void delete_pos(int pos) {// deletes positions 
        if (!head) {// if head is empty 
            cout << "List is empty." << endl;
            return;// will say list empty and return
        }
    
        if (pos == 1) {// if the posiiton is 1 it will pop the front node
            pop_front();
            return;
        }
    
        Node* temp = head; //node starts at head
    
        for (int i = 1; i < pos; i++){ // goes through list to find position 
            if (!temp) {//if the position is not found it returns
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next; //else it continues to search
        }
        if (!temp) { //if the position isnt found say pos doesnt exist
            cout << "Position doesn't exist." << endl;
            return;// returns
        }
    
        if (!temp->next) { //if pos is at the end and does not have a nother node it will call to pop the back node
            pop_back();
            return;
        }
    
        Node* tempPrev = temp->prev;//  links the nodes together while deleting the current temp one
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp; //deletes node 
    }

    void push_back(int v) { //puts a new node at the end of the list 
        Node* newNode = new Node(v); 
        if (!tail) // if the tail is empty assign all to the same value
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode; // new node is now at the tail 
        }
    }
    // puts a new node at the front 
    void push_front(int v) {
        Node* newNode = new Node(v); 
        if (!head)
            head = tail = newNode; // if the head is empty assign all these to the same value 
        else {
            newNode->next = head; //else new node is head node
            head->prev = newNode;
            head = newNode;
        }
    }
    // function to pop the front node
    void pop_front() {

        if (!head) { // head is empty cout and return
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head; //start at head

        if (head->next) {
            head = head->next;
            head->prev = nullptr;  // if head is next make prev null
        }
        else
            head = tail = nullptr;// else make all equal and delete temp
        delete temp;
    }
// function to pop the back node 
    void pop_back() {
        if (!tail) { // tail empty cout and return
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
// Destructor 
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp; // deletes the temp node thats made to go through 
        }
    }
    //Print function 
    void print() {
        Node* current = head; //starts at head node
        if (!current) { //if there is no current node list is empty 
            cout << "List is empty." << endl;
            return;
        }
        while (current) { //if there is cout the data and go to the next
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
// starts at the tail and prints the nodes in reverse order statrting at the tail 
    void print_reverse() {
        Node* current = tail;
        if (!current) { 
            cout << "List is empty." << endl;
            return;
        }
        while (current) { // couts data and goes the the one behind it as you are traversing backwards
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

void every_other_element(){
     Node* current = head;
}
int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS;  // dummy statement to avoid compiler warning

    
    return 0;
}