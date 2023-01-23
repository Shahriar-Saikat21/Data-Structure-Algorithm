# include <bits/stdc++.h>

using namespace std;

//Insertion Sort : TC-Ω(n),θ(n^2),O(n^2), SC - O(1)

void insertionSort(int array[],int size){
    int j,key;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i-1;

        while (array[j]>key && j>=0)
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;             
    }   
}

int main(){
    int arraySize;
    cout << "Enter the number of elements: ";
    cin >> arraySize;

    int array[arraySize];

    cout << "Enter array elements : ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    insertionSort(array, arraySize);
    cout << "Array after sorting: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}