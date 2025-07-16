/*---------------------------------------------------------------
1.a. Linked List Traversal
----------------------------------------------------------------*/

#include <iostream>
using namespace std;

// Define the node structure
struct Node {
    int data;
    Node* next;
};

int main() {
    // Create three nodes dynamically
    Node* first = new Node;
    Node* second = new Node;
    Node* third = new Node;

    // Assign data and link nodes
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    /*
	    // Create three nodes on the stack
	    Node first;
	    Node second;
	    Node third;

	    // Assign data and link nodes
	    first.data = 10;
	    first.next = &second; // Use the address of the next node

	    second.data = 20;
	    second.next = &third; // Use the address of the next node

	    third.data = 30;
	    third.next = nullptr; // End of the list

	    We prefer to create objects in heap because of dynamic nature of the objects like Linked Lists
	    and heap offers much more memory than stack
    */

    // // Direct access
    // cout << "Direct access" << endl;
    // cout << "---------------" << endl;
    // cout << "first = " << first << endl;
    // cout << "first->data = " << first->data << endl;
    // cout << "first->next (second) = " << first->next << endl;
    // cout << "first->next->data (second data) = " << first->next->data << endl;
    // cout << "first->next->next (second next) = " << first->next->next << endl;
    // cout << "---------------" << endl;


    // Traverse and print the list
    Node* temp = first;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    // Free allocated memory
    delete first;
    delete second;
    delete third;

    return 0;
}

/*---------------------------------------------------------------
1.b. Linked List Traversal using global variable START
----------------------------------------------------------------*/

#include <iostream>
using namespace std;

// Define the node structure and global START pointer
struct Node {
    int data;
    Node* next;
} *START = nullptr;

void set_node(Node* curr_node,int data, Node* next)
{
	curr_node->data = data;
	curr_node->next = next;
}

int traverse()
{
	int nodes = 0;
	// Traverse and print the list using START
    Node* temp = START;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        nodes++;
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return nodes;
}

int main() {
    // Create three nodes dynamically
    START = new Node;
    Node* second = new Node;
    Node* third = new Node;

    // Assign data and link nodes using START as the beginning
    set_node(START,10,second);
    set_node(second,20,third);
    set_node(third,30,nullptr);

    int num_of_nodes = traverse();
    cout << "num_of_nodes = " << num_of_nodes << endl;

    // Free allocated memory
    delete START;
    delete second;
    delete third;

    return 0;
}


/*---------------------------------------------------------------
2. Print last node data if exists or else return -1
----------------------------------------------------------------*/

#include <iostream>
using namespace std;

// Define the node structure and global START pointer
struct Node {
    int data;
    Node* next;
} *START = nullptr;

void set_node(Node* curr_node,int data, Node* next)
{
	curr_node->data = data;
	curr_node->next = next;
}

int print_last_node()
{
    Node* temp = START;
    if (temp != nullptr){
    	while (temp != nullptr) {
    		if(temp->next == nullptr){
    			cout << temp->data << " -> ";
    		}
    		temp = temp->next;
    	}
    	cout << "NULL" << endl;
    }
    else{
    	return -1;
    }
    return 0;
}

int main() {
    // Create three nodes dynamically
    START = new Node;
    Node* second = new Node;
    Node* third = new Node;

    // Assign data and link nodes using START as the beginning
    set_node(START,10,second);
    set_node(second,20,third);
    set_node(third,30,nullptr);

    // START = nullptr;
    int status = print_last_node();
    cout << "status = " << status << endl;

    // Free allocated memory
    delete START;
    delete second;
    delete third;

    return 0;
}
