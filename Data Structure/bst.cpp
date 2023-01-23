#include<bits/stdc++.h>

using namespace std;

typedef struct tree{
    int value;
    tree* left;
    tree* right;
}Tree;

Tree* createNode(int value){
    Tree* temp = new Tree();
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
}

Tree* insert(Tree* root,int value){
    if(root==NULL){
        root  = createNode(value);
        return root;
    }
    if(value < root->value){
        root->left = insert(root->left,value);        
    }else{
        root->right = insert(root->right,value);
    }
}

Tree* deleteNode(Tree* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->value){
        root->left = deleteNode(root->left,data);
    }else if(data>root->value){
        root->right = deleteNode(root->right,data);
    }else{
        /// no child
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        /// only left child
        else if(root->left!=NULL && root->right==NULL)
        {
            Tree* temp = root->left;
            delete(root);
            return temp;
        }
        /// only right child
        else if(root->left==NULL && root->right!=NULL)
        {
            Tree* temp = root->right;
            delete(root);
            return temp;
        }
        /// two child
        else
        {
            Tree* rightLeftMost = root->right;
            while(rightLeftMost->left!=NULL)
            {
                rightLeftMost = rightLeftMost->left;
            }
            root->value = rightLeftMost->value;
            root->right = deleteNode(root->right, rightLeftMost->value);
        }
    }
    return root;
}

Tree* search(Tree* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key == root->value){
        return root;
    }else if(key<root->value){
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

// Most of the BST Problems can be solved by this technique
int maxHeight(Tree* root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);

    if(leftHeight>rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }
}

void minElement(Tree* root){
    Tree* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    cout<<temp->value;
}

void maxElement(Tree* root){
    Tree* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    cout<<temp->value;
}

void inOder(Tree* root){
    if(root!=NULL){
        inOder(root->left);
        cout<<root->value<<" ";
        inOder(root->right);
    }
}

void dfs(Tree* root){
    if(root!=NULL){
        cout<<root->value<<" ";
        dfs(root->left);
        dfs(root->right);
    }
}

void bfs(Tree* root){
    if(root==NULL) return;

    queue<Tree*> q;
    q.push(root);

    while(!q.empty()){
        root = q.front();
        q.pop();
        cout<<root->value<<" ";
        if(root->left!=NULL) q.push(root->left);
        if(root->right!=NULL) q.push(root->right);
    }
}

int main(){

    Tree* root = NULL;

    int option;

    while(option!=0){
        cout<<"1. Create a BST"<<endl;
        cout<<"2. Show the tree"<<endl;
        cout<<"3. DFS"<<endl;
        cout<<"4. BFS"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter Your Option: ";
        cin>>option;

        switch(option){
            case 1:
                int n;
                cout<<"Enter number of nodes: ";
                cin>>n;
                for (int i = 0; i < n; i++)
                {
                    int node;
                    cin>>node;
                    root = insert(root,node);
                }                
                break;

            case 2:
                inOder(root);
                cout<<endl;
                break;

            case 3:
                dfs(root);
                cout<<endl;
                break;

            case 4:
                bfs(root);
                cout<<endl;
                break;

            case 0:
                cout<<"Thank You !!!"<<endl;
            break;

            default:
                cout<<"Invalid Option!!!"<<endl;
                break;
        }
    }

    return 0;
}