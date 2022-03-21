// Implementation of Cycles in Singly Linked List
#include <iostream>
#include <stdlib.h>
using namespace std;
class Node                     // Node class for Singly Linked List
{
    public:
    int data;
    Node* next;
    public:
    Node(int val)               // Parametrized Constructor
    {data = val; next = NULL;}
};
class SinglyLinkedList
{
    public:
    void InsertAtEnd(Node* &head, int val)
    {
        Node* n = new Node(val);    // New Node created with the given Value
        if (head == NULL)         // If the list is empty and head is pointing to Null then no need
        {                         // to traverse simply add the new node to head
            head = n;     // head becomes the new Node
            return;
        }
        Node* temp = head;          // Temporary node for Traversing
        while( temp -> next != NULL )
        {
            temp = temp -> next;        // Pointer becomes the next pointer
        }
        temp -> next = n;   // Update the value to which temp of next is pointing to
    }
    public:
    void ShowTheList(Node* &head)
    {
        Node* temp = head;          // Temporary pointer created pointing as head
        while (temp != NULL)        // While temp reaches the end of the list
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;               // Pointer is moved towards the next
        }
        cout << "Null" << endl;
    }
    void CreateLoopInList(Node* &head, int val)
    {                        // Creating Loop in List at the random value chosen
        Node* temp = head;
        while(temp -> data != val)
        {
            temp = temp -> next;     // Pointer Traversing until random value is found
        }
        Node* temp1 = temp;              // Another temporary variable to store the location of the
        while(temp -> next != NULL)      // joining of the loop
        {
            temp = temp -> next;     // Again Iterating to reach the end of the loop and the List
        }
        temp -> next = temp1;   // Joining the end to the stated random index of the List
    }
    void DisplayLoopedLinkedList(Node* &head, int val)
    {
        Node* temp = head;                                // Temporary Node Pointer
        cout << "The Looped Linked List is : " << endl;
        while(temp -> data != val)                       // Traversing till given random number
        {
            cout << temp -> data << " -> ";       // Printing Node data value
            temp = temp -> next;                  // Incrmenting Node pointer
        }
        do      // do-while loop to make the loop run atleast once
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }while(temp -> data != val);    // Condition statement
        cout << val << endl;
    }
    void HareAndTortoiseAlgorithmToCheckLoop(Node* &head)     // Floyd's Algorithm for Loop checking
    {
        Node* hare = head;        // Hare Pointer created
        Node* tortoise = head;    // Tortoise Pointer created
        int check = 1;                               // Loop for checking the steps taken by Tortoise
        while(hare -> next != NULL)   // Traversing Hare through the List to the end
        {
            tortoise = tortoise -> next;   // Tortoise moves one steps per Iteration
            hare = hare -> next -> next;   // Hare moves two steps per Iteration
            check = check + 1;
            if(tortoise -> data == hare -> data)  // If both land on same Node then there is a loop
            {
                cout << "There is a Loop in the Linked List !!" << endl;
                cout << "Encountered by Floyd's Algorithm in " << check << " Steps !!" << endl;
                HareAndTortoiseAlgorithmToRemoveLoop(head, tortoise);  // Calling remove function
                return;    // The control moves out of the function
            }
        }           // If Tortoise moves to the end then there is no loop as he is not struck in it
        cout << "There was no loop encountered by Floyd's Algorithm!!" << endl;
    }
    void HareAndTortoiseAlgorithmToRemoveLoop(Node* head, Node* turtle)
    {             // Floyd's Algorithm Continuation for Cycle Removal
        Node* Hare = head;              // Hare moves to the Head Node pointer
        Node* Tortoise = turtle;        // Tortoise stays in place
        int check = 1;
        while(Hare -> next != Tortoise -> next)  // If both point the same Node then that is the 
        {                                        // entry point of the Loop or Cycle
            Hare = Hare -> next;         
            Tortoise = Tortoise -> next;   // Incrementing both Hare and Tortoise by one Step
            check = check + 1;             // Incrementing step variable
        }
        Tortoise -> next = NULL;      // We point the next of Tortoise to NULL to remove the cycle
        cout << "The Loop is Removed by Floyd's Algorithm in " << check << " Steps !!" << endl;
        ShowTheList(head);            // Displaying the Normal Linked List
    }
};
int main()
{
    Node* head = NULL;           // Node creation of Singly Linked List       
    SinglyLinkedList object;     // Object Creation of Singly Linked List
    int s, x;
    cout << "Enter the number of Nodes in a Linked List ( minimum 6 ) : ";
    cin >> s;
    for(int a = 1; a <= s ; a++)  // Loop begins
    {
        cout << "Enter Node data : ";
        cin >> x;
        object.InsertAtEnd(head, x);    // function calling for Insertion
    }
    srand(time(0));    // To generate random numbers without reptition
    cout << "A Loop will be created randomly within the Linked List !!" << endl;
    x = rand()%s;                           // Generating random numbers upto last node number
    object.CreateLoopInList(head, x);
    object.DisplayLoopedLinkedList(head, x);   // Displaying Looped List
    object.HareAndTortoiseAlgorithmToCheckLoop(head);     // Calling Floyd's Algorithm
}