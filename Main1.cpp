#include <iostream>
#include <string>
using namespace std;

struct ReviewNode {
    int rating;
    string comments;
    ReviewNode* next;
};

void addToHead(ReviewNode*& head, int rating, const string& comments){}

void addToTail(ReviewNode*& head, int rating, const string& comments){}

void traverseAndPrint(ReviewNode* head){}

int main() {
    ReviewNode* head = nullptr;
    int choice, rating;
    string comments;

    cout << "Enter 1 to add reviews at the head, or 2 to add reviews at the tail: ";
    cin >> choice;

    while (true) {
        cout << "Enter a rating (1-5) or -1 to finish: ";
        cin >> rating;
        if (rating == -1) break;

        cout << "Enter your comments: ";
        cin.ignore();
        getline(cin, comments);
        if (choice == 1) {
            addToHead(head, rating, comments);
        } else if (choice == 2) {
            addToTail(head, rating, comments);
        } else {
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    cout << "\nMovie Reviews:" << endl;
    traverseAndPrint(head);

    while (head) {
        ReviewNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


void addToTail(ReviewNode*& head, int rating, const string& comments) {
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ReviewNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void traverseAndPrint(ReviewNode* head) {
    int count = 0;
    int sum = 0;
    if (!head) {
        cout << "No reviews to display." << endl;
        return;
    }
    ReviewNode* temp = head;
    while (temp) {
        cout << "Rating: " << temp->rating << ", Comments: " << temp->comments << endl;
        sum += temp->rating;
        count++;
        temp = temp->next;
    }
    if (count > 0) {
        cout << "Average Rating: " << static_cast<double>(sum) / count << endl;
    }
}

void addToHead(ReviewNode*& head, int rating, const string& comments) {
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comments = comments;
    newNode->next = head;
    head = newNode;
}