#include <iostream>
using namespace std;


void resizeArray(int*& arr, int oldSize, int newSize) {
    int* newArr = new int[newSize]();

    
    int elementsToCopy = (oldSize < newSize) ? oldSize : newSize;

    
    for (int i = 0; i < elementsToCopy; ++i) {
        newArr[i] = arr[i];
    }

    delete[] arr;

   
    arr = newArr;
}

int main() {
    int size = 3;
    int* arr = new int[size]{10, 20, 30};

   
    resizeArray(arr, size, 5);
    size = 5; // В массиве 10 20 30 0 0
    
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    
    resizeArray(arr, size, 2);
    size = 2;


    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;
    return 0;
}
