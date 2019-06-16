#ifndef SORTING_H
#define SORTING_H

/**
* Title : Algorithm Efficiency and Sorting
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 1
* Description : Sorting functions header file
*/

class sorting {
public:

    void bubbleSort(int *arr, int size, int &compCount, int &moveCount);
    void quickSort(int *arr, int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, int size, int &compCount, int &moveCount);
    void radixSort(int *arr, int size);
    void printArray(int *arr, int size);
    void performanceAnalysis();

private:
    void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
    void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    void partition( int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
};

#endif // SORTING_H
