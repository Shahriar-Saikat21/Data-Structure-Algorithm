#include <iostream>

using namespace std;

// Binary Search : TC - O(log n), SC- O(1)
// This algorhythm is applicable if the given array is being sorted

int binarySearch(int array[], int arraySize, int searchItem)
{
    int low = 0;
    int high = arraySize - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == searchItem)
        {
            return mid;
        }
        if (array[mid] < searchItem)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arraySize, searchElement;
    cout << "Enter the number of elements: ";
    cin >> arraySize;

    int array[arraySize];

    cout << "Enter array elements : ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> array[i];
    }

    cout << "Enter your search element : ";
    cin >> searchElement;

    int result = binarySearch(array, arraySize, searchElement);

    (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;

    return 0;
}
