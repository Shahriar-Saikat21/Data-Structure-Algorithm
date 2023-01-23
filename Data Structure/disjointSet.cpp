#include<bits/stdc++.h>
using namespace std;


void make_set(int p[], int r[], int x){
    p[x] = x;
    r[x] = 0;
    cout << "making a one-element set of "<<x<< endl;
}

int find_set(int p[], int x){
    if (x!=p[x])
        return find_set(p, p[x]);
    return p[x];
}

void link(int p[],int r[],int x, int y){
    if(r[x]>r[y]){
        p[y] = x;
    }else{
        p[x] = y;
        if(r[x]==r[y]){
            r[y]++;
        }
    }
}

void _union(int p[], int r[], int x, int y){
    link(p,r,find_set(p,x),find_set(p,y));
    cout << "union "<<x << " and "<<y<< endl;
}

struct Edge{
    int u, v;
};


void connected_components(int p[], int r[], int V, vector<Edge> edges){
    for (int i = 0; i < V; i++)
    {
        make_set(p,r,i);
    }
    for (int i = 0; i < edges.size(); i++)
    {
        if(find_set(p,edges[i].u)!=find_set(p,edges[i].v)){
            _union(p,r,edges[i].u,edges[i].v);
        }
    }   
}

bool same_component(int p[], int u, int v){
    if(find_set(p,u)==find_set(p,v)){
        return true;
    }
    return false;
}

int main(){
    /// This code is for an undirected graph
    int V, E;
    /// take the number of vertices V and
    /// the number of edges E as input from user
    cin>>V>>E;
    /// take the E edges as input from the user
    vector<Edge> edges;
    for (int i=0;i<E;i++){
        struct Edge e;
        cin>>e.u>>e.v;
        edges.push_back(e);
    }
    /// create the parent array for a disjoint set of V elements
    int p[V],r[V];
    /// call the function connected_components
    connected_components(p, r, V, edges);

    while(1){
        /// take an integer "option" as input.
        int option;
        cin>>option;

        /// if "option" is 1, take another integer x as input,
        /// check if x is an element of the disjoint set or not, and
        /// if it is then print the root/representative-element of x
        if (option==1){
            int x;
            cin>>x;
            if(x>=0 && x<V){
                cout<<"root of "<<x<<" is "<<find_set(p,x)<<endl;
            }else{
                cout<<x<<" is not an element of the disjoint set"<<endl;
            }
        }
        /// if "option" is 2, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print whether they belong to the
        /// same connected component or not
        else if (option==2){
            int x,y;
            cin>>x>>y;
            if((x>=0 && x<V)&&(y>=0 && y<V)){
                if(same_component(p,x,y)){
                    cout<<x<<" and "<<y<<" are same connected component"<<endl;
                }else{
                    cout<<x<<" and "<<y<<" are not same connected component"<<endl;
                }
            }else{
                cout<<x<<" and "<<y<<" are not the element of the disjoint set"<<endl;
            }
        }
        /// if "option" is 3, take integers x and y as input,
        /// check if x and y are elements of the disjoint set or not, and
        /// if they are, print if there is a path from x to y or not.
        else if (option==3){
            int x,y;
            cin>>x>>y;
            if((x>=0 && x<V)&&(y>=0 && y<V)){
                if(same_component(p,x,y)){
                    cout<<"There is a path from "<<x<<" to "<<y<<endl;
                }else{
                    cout<<"There is no path from "<<x<<" to "<<y<<endl;
                }
            }else{
                cout<<x<<" and "<<y<<" are not the element of the disjoint set"<<endl;
            }
        }
        /// if "option" is 4, print all the roots of this disjoint set
        else if (option==4){
            int temp[V];
            for (int i = 0; i < V; i++)
            {
                temp[i] = p[i];
            }
            sort(temp,temp+V);
            int t = temp[0];
            for (int i = 1; i < V; i++)
            {
                if(p[i]!=t){
                    cout<<t<<" ";
                    t = p[i];
                }
            }
            cout<<t<<endl;           
        }
        /// if "option" is 5, print the vertices of each connected components
        /// in each line
        else if (option==5){
            bool visited[V];
            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
            }
            for (int i = 0; i < V; i++)
            {
                vector<int> component;
                if(!visited[i]){
                    component.push_back(i);
                }
                for(int j = i+1;j<V;j++){
                    if(same_component(p,i,j) && !visited[j]){
                        component.push_back(j);
                        visited[j] = true;
                    }
                }
                if(!component.empty()){
                    for (int i = 0; i < component.size(); i++)
                    {
                        cout<<component[i]<<" ";
                    }
                    cout<<endl;
                }

            }
            
            
        }else {
            return 0;
        }
    }
}
