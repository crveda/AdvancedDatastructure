#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;

class Node {
public : int data;
Node* xnode;
};

Node* Xor(Node* x, Node* y)
{
return reinterpret_cast<Node*>(
reinterpret_cast<uintptr_t>(x)
^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node** head_ref, int data)
{
Node* new_node = new Node();
new_node -> data = data;
new_node -> xnode = *head_ref;
if (*head_ref != NULL) {
(*head_ref)
-> xnode = Xor(new_node, (*head_ref) -> xnode);
}
*head_ref = new_node;
}

void printList(Node* head)
{
Node* curr = head;
Node* prev = NULL;
Node* next;

cout << "\nThe nodes of Linked List are: \n";
while (curr != NULL) {
cout << curr -> data << " ";
next = Xor(prev, curr -> xnode);
prev = curr;
curr = next;
}
}

struct Node* delEnd(struct Node** head)
{
    // Base condition
    if (*head == NULL)
        cout << "List is empty";
    else
    {

        // Stores XOR pointer in current node
        struct Node* curr = *head;

        // Stores XOR pointer of in previous Node
        struct Node* prev = NULL;

        // Stores XOR pointer of in next node
        struct Node* next;

        // Traverse XOR linked list
        while (Xor(curr->xnode, prev) != NULL)
        {
            // Forward traversal
            next = Xor(prev, curr->xnode);

            // Update prev
            prev = curr;

            // Update curr
            curr = next;
        }
        // If the Linked List contains more than 1 node
        if (prev != NULL) {
            prev->xnode = Xor(Xor(prev->xnode, curr), NULL);
        }
        // Otherwise
        else {
            *head = NULL;
        }

        // Delete the last node from memory
        delete(curr);
    }

    // Returns head of new linked list
    return *head;
}

int main()
{
Node* head = NULL;
int n;
cout<<"Enter number of nodes: ";
cin>>n;
cout<<"Enter Elements:\n";
int ele;
for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert(&head , ele);
    }
printList(head);
    cout<<"\n\nThe list after deletion :";
    delEnd(&head);
    printList(head);

return (0);
}
