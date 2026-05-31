#include<bits/stdc++.h>
using namespace std;

// structure of a node in a linked list
struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


// function to search for a key in a linked list iteratively
bool search(Node* head,int key){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}


// recursive function to search for a key in a linked list
bool search_recursive(Node* head,int key){
    if(head==NULL)
        return false;
    if(head->data == key)
        return true;
    return search_recursive(head->next,key);
}

// function to search for a key in a circular linked list
bool circular_search(Node* head,int key){
    if(head==NULL)
        return false;
    Node* curr = head;
    do{
        if(curr->data == key)
            return true;
        curr = curr->next;
    }while(curr!=head);
    return false;
}


// function to detect a loop in a linked list using Floyd's cycle detection algorithm
bool loop_detection(Node* head){
    if(head==NULL)
        return false;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

// function to insert a node at the head of a linked list
void insert_at_head(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}


// function to insert a node at the tail of a linked list
void insert_at_tail(Node* &head,int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* curr = head;
    while(curr->next!=NULL){
        curr = curr->next;
    }
    curr->next = temp;
}


// function to insert a node at a given position in a linked list
void insert_at_position(Node* &head,int data,int pos){
    Node* temp = new Node(data);
    if(pos==1){
        temp->next = head;
        head = temp;
        return;
    }
    Node* curr = head;
    for(int i=1;i<pos-1 && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL)
        return;
    temp->next = curr->next;
    curr->next = temp;
}

// function to delete a node at the head of a linked list
void delete_at_head(Node* &head){
    if(head==NULL)
        return;
    Node* temp = head;
    head = head->next;
    delete temp;
}


// function to delete a node at the tail of a linked list
void delete_at_tail(Node* &head){
    if(head==NULL)
        return;
    if(head->next==NULL){
        delete head;
        head = NULL;
        return;
    }
    Node* curr = head;
    while(curr->next->next!=NULL){
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
}


// function to delete a node at a given position in a linked list
void delete_at_position(Node* &head,int pos){
    if(head==NULL)
        return;
    if(pos==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    for(int i=1;i<pos-1 && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr==NULL || curr->next==NULL)
        return;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}


// function to reverse a linked list iteratively
void reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}


// function to reverse a linked list recursively
void reverse_recursive(Node* &head,Node* curr,Node* prev){
    if(curr==NULL){
        head = prev;
        return;
    }
    Node* next = curr->next;
    curr->next = prev;
    reverse_recursive(head,next,curr);
}


// function to reverse a linked list in groups of k
void reverse_k(Node* &head,int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
        head->next = reverse_k(next,k);
    head = prev;
}


// function to reverse a linked list in groups of k iteratively
Node* reverse_k_iterative(Node* &head,int k){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
        head->next = reverse_k_iterative(next,k);
    return prev;
}

// function to traverse a linked list and return the elements in a vector
vector<int> traverse(Node* head){
    vector<int> ans;
    Node* curr = head;
    while(curr!=NULL){
        ans.push_back(curr->data);
        curr = curr->next;
    }
    return ans;
}

// main function to test the above functions
int main (){
Node*curr;
Node* head;
int n;
cin>>n;
  for(int i=0;i<n;i++){
      int r;
      cin >> r;
      Node* temp = new Node(r);
      if(i==0){
          head = temp;
           curr = head;
      }
      else{
          curr->next = temp;
          curr = curr->next;
      }
    }
    vector<int> ans = traverse(head);
    for(int i:ans){
        cout << i << ' ';
    }
return 0;
}