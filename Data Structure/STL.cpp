#include<bits/stdc++.h>

using namespace std;

int main(){

    // Stack

    stack<int> s;

    s.push(1);
    s.push(3);
    s.push(4);
    s.push(2);

    cout<<s.top()<<" "<<s.size()<<endl;
    s.pop();
    cout<<s.top()<<" "<<s.size()<<endl;

    // Queue

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    cout<<q.front()<<" "<<q.size()<<endl;
    q.pop();
    cout<<q.front()<<" "<<q.size()<<endl;

    // Priority Queue
    //Max Heap

    priority_queue<int,vector<int>> maxHeap;

    maxHeap.push(14);
    maxHeap.push(13);
    maxHeap.push(20);
    maxHeap.push(17);
    maxHeap.push(19);
    maxHeap.push(21);
    maxHeap.push(2);

    cout<<maxHeap.top()<<" "<<maxHeap.size()<<endl;
    maxHeap.pop();
    cout<<maxHeap.top()<<" "<<maxHeap.size()<<endl;

    //Min Heap

    priority_queue<int,vector<int>,greater<int>> minHeap;

    minHeap.push(14);
    minHeap.push(13);
    minHeap.push(20);
    minHeap.push(17);
    minHeap.push(19);
    minHeap.push(21);
    minHeap.push(2);

    cout<<minHeap.top()<<" "<<minHeap.size()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<" "<<minHeap.size()<<endl;


    // Set

    set<int>ss;

    ss.insert(1);
    ss.insert(1);
    ss.insert(2);
    ss.insert(2);
    ss.insert(3);

    for(int x:ss){
        cout<<x<<" ";
    }
    cout<<endl;

    // Map

    map<int,string> m;

    m[1] = "Hasan";
    m[2] = "Ahmed";
    m[3] = "Mridha";
    m[4] = "Khan";
    m[5] = "Chowdhury";

    map<int,string>::iterator itr;

    for (itr = m.begin(); itr!=m.end(); itr++)
    {
        cout<< itr->first<<" "<<itr->second<<endl;
    }
    
    /* Given an array, find out the frequency of the element */

    int arr[] = {1,2,3,4,2,4,1,3,5};

    map<int,int> freq;

    for (int i = 0; i < 9; i++)
    {
        freq[arr[i]]++;
    }

    for(auto i = freq.begin(); i!= freq.end(); i++){
        cout<<i->first<<" -> "<<i->second<<endl;
    }
    

    //Vector

    vector<int> v;

    v.push_back(6);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);

    sort(v.begin(),v.end());

    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

   //pair
    pair<int,int> p;

    p.first = 1;
    p.second = 2;

    cout<<p.first<<" "<<p.second<<endl; 

    

    return 0;
}
