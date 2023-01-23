#include <iostream>

using namespace std;

// Linear Search : TC - O(n), SC- O(1)
int linearSearch(int array[], int arraySize, int searchItem)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == searchItem)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arraySize, searchElement;

    cout << "Enter the size of the array: ";
    cin >> arraySize;

    int array[arraySize];
    cout << "Enter array elements : ";

    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    cout << "Enter your searching element: ";
    cin >> searchElement;

    int result = linearSearch(array, arraySize, searchElement);

    (result == -1) ? cout << "Element not found" : cout << "Element found at index " << result;

    return 0;
}