#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
};

int main(){
    
    Node* aa = new Node(44);
    cout<<&aa<<endl;
    cout<<aa<<endl;
    cout<<aa->data<<endl;
    cout<<(*aa).data<<endl;
    cout<<*(&aa)<<endl;  // Equivalent to aa only --> It means (value at) the (address of) aa.

    cout<<endl;
    cout<<"******************"<<endl;
    cout<<endl;
    
    Node bb = Node(33);
    Node* pointer_to_bb = &bb;
    cout<<&pointer_to_bb<<endl;
    cout<<pointer_to_bb<<endl;
    cout<<pointer_to_bb->data<<endl;

    return 0;
}