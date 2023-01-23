#include<bits/stdc++.h>

using namespace std;

//Linear Time Sorting(only for Positive integer): 
//TC: TC-Ω(n+k),θ(n+k),O(n+k), SC - O(k)

void countingSort(int array[],int size,int maxKeyValue){
    int countSize = maxKeyValue+1;
    int count[countSize];
    int outputArray[size];

    for (int i = 0; i < countSize; i++) // Initialize count array with all zeros.     
    {
        count[i] = 0;
    }   
    
    for (int i = 0; i < size; i++) // Store the count of each element              
    {
        count[array[i]]++;
    }

    for (int i = 1; i <= countSize; i++) // Store the cummulative count of each array or prefix sum    
    {
        count[i] += count[i-1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array                                     
    for (int i = size-1; i >= 0; i--)
    {
        outputArray[--count[array[i]]] = array[i];
    }
    
    for (int i = 0; i < size; i++) // Copy the sorted elements into original array      
    {
        array[i] = outputArray[i];
    }
       
}

int main(){

    int array[] = {1,0,2,2,9,9,1};
    int size = sizeof(array)/sizeof(array[0]);
    int maxKeyValue = 9;

    countingSort(array,size,maxKeyValue);

    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}