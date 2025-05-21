#include <bits/stdc++.h>
using namespace std;

// Function to update the array in most recently used (MRU) fashion
void recently(int* arr, int size, int elem) {
	int index = 0;
    index = elem % size;
    int temp = index;
    int id = arr[index];

    while (temp > 0) {
        arr[temp] = arr[--temp];
    }

    arr[0] = id;
}

// Function to print array elements
void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int elem = 3;
    int arr[] = { 6, 1, 9, 5, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    recently(arr, size, elem);

    cout << "Array in most recently used fashion: ";
    print(arr, size);

    return 0;
}

