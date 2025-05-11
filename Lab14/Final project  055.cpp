#include <iostream>
using namespace std;

class StringListNode {
public:
    string data;
    StringListNode* next;

    StringListNode(string d) {
        data = d;
        next = nullptr;
    }
};


class StringList {
private:
    StringListNode* head;
    StringListNode* tail;

public:
    StringList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(string s) {
        StringListNode* newNode = new StringListNode(s);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(string s) {
        StringListNode* newNode = new StringListNode(s);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void reverse() {
        StringListNode* prev = nullptr;
        StringListNode* curr = head;
        StringListNode* next;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void printRoute() {
        StringListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " |" << string(25, '-') << "| ";
            temp = temp->next;
        }
        cout << endl;
    }

    StringListNode* getHead() {
        return head;
    }
};

class VisitedList {
private:
    StringListNode* head;

public:
    VisitedList() {
        head = nullptr;
    }

    void insert(string val) {
        if (!contains(val)) {
            StringListNode* newNode = new StringListNode(val);
            newNode->next = head;
            head = newNode;
        }
    }

    bool contains(string val) {
        StringListNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }
};

class QueueNode {
public:
    string data;
    QueueNode* next;

    QueueNode(string d) {
        data = d;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string val) {
        QueueNode* newNode = new QueueNode(val);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    string dequeue() {
        if (front == nullptr) return "";
        string val = front->data;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) rear = nullptr;
        return val;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

class RouteNode {
public:
    string name;
    RouteNode* next;

    RouteNode(string n) {
        name = n;
        next = nullptr;
    }
};

class RideNode {
public:
    string username;
    string from;
    string to;
    StringList path;
    RideNode* next;

    RideNode(string uname, string f, string t, StringList p) {
        username = uname;
        from = f;
        to = t;
        path = p;
        next = nullptr;
    }
};

class Landmark {
public:
    string name;
    RouteNode* head;
    Landmark* next;

    Landmark(string n) {
        name = n;
        head = nullptr;
        next = nullptr;
    }

    void addConnection(string destination) {
        RouteNode* newNode = new RouteNode(destination);
        newNode->next = head;
        head = newNode;
    }

    void showConnections() {
        RouteNode* temp = head;
        while (temp != nullptr) {
            cout << " -> " << temp->name;
            temp = temp->next;
        }
        cout << endl;
    }
};

class RouteMap {
private:
    Landmark* head;

public:
    RouteMap() {
        head = nullptr;
    }

    Landmark* findLandmark(string name) {
        Landmark* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void addLandmark(string name) {
        if (!findLandmark(name)) {
            Landmark* newL = new Landmark(name);
            newL->next = head;
            head = newL;
        }
    }

    void addRoute(string from, string to) {
        addLandmark(from);
        addLandmark(to);
        Landmark* lFrom = findLandmark(from);
        Landmark* lTo = findLandmark(to);
        lFrom->addConnection(to);
        lTo->addConnection(from);
        cout << "Route added between " << from << " and " << to << ".\n";
    }

    void displayAll() {
        Landmark* temp = head;
        while (temp != nullptr) {
            cout << temp->name;
            temp->showConnections();
            temp = temp->next;
        }
    }

    StringList findPath(string start, string end) {
        StringList path;
        Landmark* lStart = findLandmark(start);
        Landmark* lEnd = findLandmark(end);
        if (lStart == nullptr || lEnd == nullptr) {
            cout << "One or both landmarks not found.\n";
            return path;
        }

        Queue q;
        VisitedList visited;
        Landmark* parents[100];
        string names[100];
        int size = 0;

        q.enqueue(start);
        visited.insert(start);
        names[size] = start;
        parents[size] = nullptr;
        size++;

        bool found = false;

        while (!q.isEmpty()) {
            string current = q.dequeue();
            if (current == end) {
                found = true;
                break;
            }

            Landmark* currLandmark = findLandmark(current);
            RouteNode* temp = currLandmark->head;
            while (temp != nullptr) {
                if (!visited.contains(temp->name)) {
                    q.enqueue(temp->name);
                    visited.insert(temp->name);
                    names[size] = temp->name;
                    for (int i = 0; i < size; ++i) {
                        if (names[i] == current) {
                            parents[size] = findLandmark(current);
                        }
                    }
                    size++;
                }
                temp = temp->next;
            }
        }

        if (!found) {
            cout << "No route found from " << start << " to " << end << ".\n";
            return path;
        }

        string trace = end;
        while (trace != start) {
            path.push_front(trace);
            for (int i = 0; i < size; ++i) {
                if (names[i] == trace) {
                    trace = parents[i] ? parents[i]->name : start;
                }
            }
        }
        path.push_front(start);
        return path;
    }
};

class RideManager {
private:
    RideNode* head;

public:
    RideManager() {
        head = nullptr;
    }

    void addRide(string uname, string from, string to, StringList path) {
        RideNode* newRide = new RideNode(uname, from, to, path);
        newRide->next = head;
        head = newRide;
        cout << "Ride added successfully for user " << uname << ".\n";
    }

    void displayRides() {
        if (head == nullptr) {
            cout << "No rides available.\n";
            return;
        }
        RideNode* temp = head;
        cout << "\nAvailable Rides:\n";
        while (temp != nullptr) {
            cout << "User: " << temp->username
                 << " | From: " << temp->from
                 << " | To: " << temp->to << " | Route: ";
            temp->path.printRoute();
            temp = temp->next;
        }
    }
};

void showMenu() {
    cout << "\n========= Ride Sharing Route Matcher =========\n";
    cout << "1. Add Landmark\n";
    cout << "2. Add Route Between Landmarks\n";
    cout << "3. Display All Routes\n";
    cout << "4. Find Route Between Two Landmarks\n";
    cout << "5. Add Ride for a User\n";
    cout << "6. Display All Rides\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RouteMap routeMap;
    RideManager rideManager;
    int choice;
    string from, to, username;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Landmark name: ";
                getline(cin, from);
                routeMap.addLandmark(from);
                break;
            case 2:
                cout << "Enter FROM landmark: ";
                getline(cin, from);
                cout << "Enter TO landmark: ";
                getline(cin, to);
                routeMap.addRoute(from, to);
                break;
            case 3:
                routeMap.displayAll();
                break;
            case 4:
                cout << "Enter START landmark: ";
                getline(cin, from);
                cout << "Enter DESTINATION landmark: ";
                getline(cin, to);
                {
                    StringList path = routeMap.findPath(from, to);
                    path.printRoute();
                }
                break;
            case 5:
                cout << "Enter Username: ";
                getline(cin, username);
                cout << "Enter FROM landmark: ";
                getline(cin, from);
                cout << "Enter TO landmark: ";
                getline(cin, to);
                {
                    StringList path = routeMap.findPath(from, to);
                    rideManager.addRide(username, from, to, path);
                }
                break;
            case 6:
                rideManager.displayRides();
                break;
            case 7:
                cout << "Thank you for using the Ride Sharing System!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
