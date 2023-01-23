#include<bits/stdc++.h>

using namespace std;

typedef struct Node Node;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void add(int value){
    if(head==NULL){
        head = createNode(value);
        tail = head;
        head->next = NULL;
    }else{
        Node* temp = createNode(value);
        tail->next = temp;
        tail = tail->next;
        tail->next = head;
        temp =NULL;
    }
}

void insertFirst(int data){
    if(head==NULL){
        head = createNode(data);
        tail = head;
        head->next = head;
    }else{
        Node* temp = createNode(data);
        temp->next = head;
        head = temp;
        tail->next = head;
        temp = NULL;
    }
}

void insertMiddle(int data,int insertAfter){
    Node* loc = search(insertAfter);
    Node* temp = createNode(data);

    temp->next = loc->next;
    loc->next = temp;
    temp = NULL;
    loc = NULL;
}

void delFirst(){
    Node* temp = head;
    head = head->next;
    tail = head;
    delete(temp);
}

Node* prevTail(){
    Node* i = head;
    Node* j = NULL;
    while(i!=tail){
        j = i;
        i = i->next;
    }
    return j;
}

void delLast(){
    Node* loc = prevTail();
    Node* temp = tail;
    loc->next = head;
    tail = loc;
    delete(temp);
}

void delMiddle(int key){
    Node* loc = search(key);
    loc->next = loc->next->next;
    delete(loc);
}

Node* search(int key){
    if(head==NULL) return NULL;
    Node* i = head;
    do{
        if(i->data ==key) return i;
        i = i->next;
    }while(i != NULL);
    
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