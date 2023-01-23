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

    return 0;
}