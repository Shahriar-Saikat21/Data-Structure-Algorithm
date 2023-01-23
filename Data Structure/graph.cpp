#include<bits/stdc++.h>

using namespace std;

#define n 6

void menu(){
    cout<<"1. Show Your Graph"<<endl;
    cout<<"2. BFS"<<endl;
    cout<<"3. DFS"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Enter Your Option: ";
}

void initGraph(int graph[][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
    {
            graph[i][j] = 0;
        }       
    }   
}


void graphInputUndirected(int graph[][n],int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void graphInputDirected(int graph[][n],int u, int v){
    graph[u][v] = 1;
}

void printGraph(int graph[][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }   
}

void bfs(int Graph[][n],int visited[],int src){

    queue<int>q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        for (int i = 0; i < n; i++)
        {
            if(Graph[t][i]==1 && visited[i]!=1){
                q.push(i);
                visited[i] = 1;
            }
        }       
    }
    cout<<endl;
}

void dfs(int Graph[][n],int visited[], int src){
    visited[src] = 1;
    cout<<src<<" ";
    for (int i = 0; i < n; i++)
    {
        if(Graph[src][i]==1 && visited[i]!=1){
            dfs(Graph,visited,i);
        }
    }
}


int main(){
 
    int Graph[n][n], visited[n]={0}; 
    initGraph(Graph);
    cout<<"Enter number of edges : ";
    int x;
    cin>>x;

    int op;
    cout<<"Enter Tpye of graph:\n1.Undirected\n2.Directed\n";
    cin>>op;
    if(op == 1){
        cout<<"Enter your edges : \n";
        for (int i = 0; i < x; i++)
        {
                int u,v;
                cin>>u>>v;
                graphInputUndirected(Graph,u,v);
        }
    }else if(op==2){
        cout<<"Enter your edges : \n";
        for (int i = 0; i < x; i++)
        {
                int u,v;
                cin>>u>>v;
                graphInputDirected(Graph,u,v);
        }
    }else{
        cout<<"Go to hell you dumb!!!!"<<endl;
        return 0;
    }
    
    int option;

    while(option!=0){

        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }

        menu();
        cin>>option;

        switch (option)
        {
        case 1:
            printGraph(Graph);  
            break;

        case 2:
            cout<<"Enter Source vertex: ";
            int src;
            cin>>src;
            bfs(Graph,visited,src);
            break;
        
        case 3:
            cout<<"Enter Source vertex: ";
            int s;
            cin>>s;
            dfs(Graph,visited,s);
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