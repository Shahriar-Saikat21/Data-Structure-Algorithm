#include <iostream>

using namespace std;

// Selection Sort : TC -Ω(n^2),θ(n^2),O(n^2), SC - O(1)

void selectionSort(int array[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main()
{
    int arraySize;
    cout << "Enter array size: ";
    cin >> arraySize;

    int array[arraySize];
    cout << "Enter array elements: ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    selectionSort(array, arraySize);

    cout << "Array after sorted: " << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}