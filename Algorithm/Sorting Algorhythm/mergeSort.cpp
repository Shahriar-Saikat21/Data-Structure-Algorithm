#include<bits/stdc++.h>

using namespace std;

//TC: TC-Ω(nlogn),θ(nlogn),O(nlogn), SC - O(n)

void merge(int array[],int left,int mid,int right){

    int leftArraySize = mid - left+1;
    int rightArraySize = right-mid;

    int leftArray[leftArraySize+1];
    int rightArray[rightArraySize+1];

    /* copy data to temp arrays */ 
    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = array[left+i];
    }
    leftArray[leftArraySize] = INT_MAX;

    for (int i = 0; i < rightArraySize; i++)
    {
        rightArray[i] = array[mid+1+i];
    }
    rightArray[rightArraySize] = INT_MAX;

    int leftArrayIndicator = 0;
    int rightArrayIndicator = 0;

    while(left<=right){
        if(leftArray[leftArrayIndicator]<rightArray[rightArrayIndicator]){
            array[left++] = leftArray[leftArrayIndicator++];
        }else{
            array[left++] = rightArray[rightArrayIndicator++];
        }
    }

}

void mergeSort(int array[],int left,int right){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}

int main(){

    int array[] = {9,9,7,7,5,4};
    int size = 6;

    mergeSort(array,0,size-1);

    for (int i = 0; i < size; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}