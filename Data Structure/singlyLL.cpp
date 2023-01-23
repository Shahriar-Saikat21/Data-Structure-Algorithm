#include<bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    struct Node* next;
};

typedef struct Node node;

node* createNode(){
    node* nn = new node();
    cout<<"Enter node value: ";
    cin>> nn->value;
    nn->next = NULL;
    return nn;
}

int listSize(Node* head){
    int size = 0;
    if(head == NULL){
        return size;
    }else{
        node* temp = head;
        while(temp !=NULL){
            size++;
            temp = temp->next;
        }
        return size;
    }
}

node* insertHead(node* head, node* nn){
    if(head != NULL){
        nn->next = head;
    }
    head = nn;
    return head;
}

node* insertNth(node* head,node* newNode,int key){
    if(head==NULL){
        head = insertHead(head,newNode);
    }else{
        node* temp = head;
        while(temp !=NULL){
            if(temp->value==key){
                newNode->next = temp->next;
                temp->next = newNode;
                return head;
            }
            temp = temp->next;
        }
    }
    return head;
}

node* insertTail(node* head, node* nn){
    if(head == NULL){
        //head = insertHead(head,nn);
        head = nn;
    }else{
        node *temp;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;        
    }
    return head;
}

node* insertNth(node* head,int pos,int lSize){
    node* temp = head;
    if(pos >=1 && pos<=lSize+1){
        node* nn = createNode();
        if(pos ==1){
            head = insertHead(head,nn);
        }else if(pos == lSize+1){
            head = insertTail(head,nn);
        }else{
            for(int i = 1;i<= pos -2;i++){
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
        }
    }else{
        cout<<"Invalid Postion"<<endl;
    }
    return head;
}

node* deleteHead(node* head){
    if(head == NULL){
        cout<<"Nothing to delete"<<endl;
    }else{
        node* temp = head;
        head = head->next;
        delete(temp);
    }
    return head;
}

node* deleteTail(node* head){
    int lSize = listSize(head);
    if(lSize <=1){
        head = deleteHead(head);
    }else{
        node* temp = head;
        for(int i = 1;i<= lSize-2;i++){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    return head;
}

node* deleteNth(node* head,int lSize,int pos){
    if(pos ==1){
        head = deleteHead(head);
    }else if(pos == lSize){
        head = deleteTail(head);
    }else{
        node *temp, *del;
        temp = head;
        for(int i = 1;i<= pos -2;i++){
            temp = temp->next;
        }
        del = temp->next;
    }
    return head;
}


void printList(node* head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        cout<< temp->value<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* sort(node* head){
    node *i,*j;
    int temp;
    for(i = head;i!=NULL;i = i->next){
        node *minNode = i;
        for(j = i->next;j!=NULL;j = j->next){
            if(j->value < minNode->value){
                minNode = j;
            }
        }
        temp = i->value;
        i->value = minNode->value;
        minNode->value = temp;
    }
    return head;
}

int search(node* head,int key){
    node *temp;
    temp = head;
    int index = 0;
    while(temp!=NULL){
        if(temp->value == key){
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

void menu(){
    printf("1. insert(head)\n");
    printf("2. insert(nth)\n");
    printf("3. insert(tail)\n");
    printf("4. search\n");
    printf("5. sort\n");
    printf("8. print list\n");
    printf("9. list size\n");
    printf("0. exit\n");
}

int main()
{
    node* head= NULL;

    menu();
    int option;
    cout<<"Enter Choice : ";
    cin>>option;

    while(option !=0){
        if(option == 1)
        {
           node* newNode = createNode(); 
           head = insertHead(head,newNode);
        }
        else if(option == 2)
        {
            int lSize,pos;
            lSize = listSize(head);
            cout<<"Enter Position : ";
            cin>>pos;
            head = insertNth(head,pos,lSize);
            
        }
        else if(option == 3)
        {
            node* newNode = createNode();
            head = insertTail(head,newNode);
        }
        else if(option == 4)
        {
            int key;
            cout<<"Enter search key: ";
            cin>>key;
            int result = search(head,key);
            if(result>-1){
                cout<<"Key is found at index"<<result<<endl;
            }else{
                cout<<"Key is not found"<<endl;
            }
        }
        else if(option ==5)
        {
            head = sort(head);   
        }
        else if(option == 8)
        {
            printList(head);
        }
        else if(option == 9)
        {
            cout<<listSize(head)<<endl;
        }
        else
        {
            printf("wrong input.\n\n");
        }
        menu();
        cout<<"Enter Choice : ";
        cin>>option;        
    }

    return 0;
}



