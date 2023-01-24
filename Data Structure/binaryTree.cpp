#include<bits/stdc++.h>

using namespace std;

typedef struct tree{
    int value;
    tree* left;
    tree* right;
}Tree;

Tree* createNode(int x){
    Tree* node = new Tree();
    node->value = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void dfs(Tree* root){
    if(root!=NULL){
        cout<<root->value<<" ";
        dfs(root->left);
        dfs(root->right);
    }
}

void bfs(Tree* root){
    queue<Tree*> q;
    q.push(root);

    while(!q.empty()){
        Tree* temp = q.front();
        q.pop();
        cout<<temp->value<<" ";
        q.push(temp->left);
        q.push(temp->right);
    }
}

bool search(Tree* root, int key){
    if(root==NULL) return false;
    if(root->value==key) return true;
    return search(root->left,key) || search(root->right,key);
}

int minValue(Tree* root){
    if(root==NULL) return INT_MAX;
    return min(root->value,min(minValue(root->left),minValue(root->right)));
}

int sum(Tree* root){
    if(root==NULL) return 0;
    return root->value + sum(root->left) + sum(root->right);
}

int evenSum(Tree* root){
    if(root==NULL) return 0;
    if(root->value%2==0) return root->value + evenSum(root->left) + evenSum(root->right);
    else return evenSum(root->left) + evenSum(root->right);    
}


int main(){

    Tree* root = NULL;

    root = createNode(10);
    root->left = createNode(2);
    root->right = createNode(25);
    root->left->left = createNode(100);
    root->left->right = createNode(33);
    root->right->left = createNode(99);
    root->right->right = createNode(3);

    dfs(root);
    cout<<endl;

    bfs(root);
    cout<<endl;
    
    search(root,10)? cout<<"Found"<<endl : cout<<"Not found"<<endl;

    cout<<minValue(root)<<endl;

    cout<<sum(root)<<endl;

    cout<<evenSum(root)<<endl;

    return 0;
}
