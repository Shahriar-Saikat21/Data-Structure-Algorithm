#include<bits/stdc++.h>

using namespace std;

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void add(int value){
    if(head==NULL){
        head = createNode(value);
        tail = head;
        head->next = head->prev = NULL;
    }else{
        Node* temp = createNode(value);
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
        temp =NULL;
    }
}

void insertFirst(int data){
    Node* temp = createNode(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
    temp = NULL;
}

void insertMiddle(int data,int insertAfter){
    Node* loc = search(insertAfter);
    Node* temp = createNode(data);

    temp->next = loc->next;
    loc->next = temp;
    temp->prev = loc;
    temp->next->prev = temp;
    temp = NULL;
    loc = NULL;
}

void delFirst(){
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
}

void delLast(){
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete(temp);
}

void delMiddle(int key){
    Node* loc = search(key);
    loc->prev->next = loc->next;
    loc->next->prev = loc->prev;
    delete(loc);
}

Node* search(int key){
    for(Node* i = head;i!=NULL;i = i->next){
        if(i->data == key) return i;
    }
    return NULL;
}

void printNode(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    return 0;
}