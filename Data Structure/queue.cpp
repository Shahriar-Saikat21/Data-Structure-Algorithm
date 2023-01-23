#include<bits/stdc++.h>

using namespace std;

void menu();
void enqueue(int queue[],int qSize,int *elementCount,int *back);
void dequeue(int queue[],int qSize,int *elementCount,int *front);
void size(int elementCount);
void frontElement(int queue[],int front,int elementCount);


int main()
{
    int queue[100],ch, qSize, front = 0, back = 0;
    int elementCount = 0;
    printf("enter queue size: ");
    scanf("%d",&qSize);

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            enqueue(queue,qSize,&elementCount,&back);
        }
        else if(ch == 2)
        {
            dequeue(queue,qSize,&elementCount,&front);
        }
        else if(ch == 3)
        {
            size(elementCount);
        }
        else if(ch == 4)
        {
            frontElement(queue,front,elementCount);
        }
        else
        {
            printf("invalid choice\n\n");
        }
        menu();
        printf("enter choice: ");
        scanf("%d",&ch);
    }
    return 0;
}


void menu()
{
    printf("1. enqueue\n");
    printf("2. dequeue\n");
    printf("3. queue size\n");
    printf("4. front element\n");
    printf("0. exit\n");
}

void enqueue(int queue[],int qSize,int *elementCount,int *back){
    if(*elementCount == qSize)
        cout<<"queue full"<<endl<<endl;
    else
    {
        cout<<"Enter value: ";
        cin>>queue[*back];
        *back = (*back+1)%qSize;
        (*elementCount)++;
    }
}

void dequeue(int queue[],int qSize,int *elementCount,int *front){
    if(*elementCount == 0)
        cout<<"Queue empty"<<endl<<endl;
    else
    {
        cout<<queue[*front]<<" dequeued"<<endl<<endl;
        *front = (*front+1)%qSize;
        (*elementCount)--;
    }
}

void size(int elementCount){
    cout<<"queue size: "<<elementCount<<endl<<endl;
}

void frontElement(int queue[],int front,int elementCount){
    if(elementCount==0){
        cout<<"Queue empty"<<endl<<endl;
    }else{
        cout<<"front element: "<<queue[front]<<endl<<endl;
    }   
}
