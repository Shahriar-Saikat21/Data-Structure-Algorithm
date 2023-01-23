#include<bits/stdc++.h>

using namespace std;

//TC: TC-Ω(n log(n)), θ(n log(n)), O(n^2), SC - O(log(n))
// Best case when the array can be divivde into even two parts
// Worse case when the array is already sorted and pivot is the first element
// Better to choose the median element as pivot

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
int partition(int array[],int left,int right){
    int pivot = right;
    int i = left-1;
    for(int j = left; j<right; j++){
        if(array[j]<= array[pivot]){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[pivot]);
    return i+1;
}

void quickSort(int array[],int left,int right){
    if(left<right){
        int pivot = partition(array,left,right);
        quickSort(array,left,pivot-1);
        quickSort(array,pivot+1,right);
    }
}

int main(){

    int array[] = {4,1,0,7,6,2};
    int size = 6;

    quickSort(array,0,size-1);

    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}