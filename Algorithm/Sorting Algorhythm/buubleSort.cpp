#include <iostream>

using namespace std;

// Bubble Sort : TC -Ω(n),θ(n^2),O(n^2), SC - O(1)

void bubbleSort(int array[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        int flag = 0; // for Optimization, if array is sorted and Ω(n)
        for (int j = 0; j < arraySize-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
        if (flag ==0) break;
    }
}

int main()
{
    int arraySize;
    cout << "Enter the number of elements: ";
    cin >> arraySize;

    int array[arraySize];

    cout << "Enter array elements : ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    bubbleSort(array, arraySize);
    cout << "Array after sorting: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}