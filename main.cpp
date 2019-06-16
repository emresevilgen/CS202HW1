#include <iostream>
#include "sorting.h"
using namespace std;

/**
* Title : Algorithm Efficiency and Sorting
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 1
* Description : main class
*/


int main(){
    sorting s;
    int compCount = 0;
    int moveCount = 0;
    int theArray[] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int theArray2[] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int theArray3[] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int theArray4[] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int sizeOfArray = 16;


    cout << "Bubble sort: " <<endl;
    s.bubbleSort(theArray, sizeOfArray, compCount, moveCount );
    s.printArray(theArray, sizeOfArray);
	//cout << "\nCompCount: " << compCount << " MoveCount: "  << moveCount <<endl;


    cout << "\nQuick sort: " <<endl;
    s.quickSort(theArray2, sizeOfArray, compCount, moveCount );
    s.printArray(theArray2, sizeOfArray);
	//cout << "\nCompCount: " << compCount << " MoveCount: "  << moveCount <<endl;

    cout << "\nMerge sort: " <<endl;
    s.mergeSort(theArray3, sizeOfArray, compCount, moveCount );
    s.printArray(theArray3, sizeOfArray);
	//cout << "\nCompCount: " << compCount << " MoveCount: "  << moveCount <<endl;

    cout << "\nRadix sort: " <<endl;
    s.radixSort(theArray4, sizeOfArray );
    s.printArray(theArray4, sizeOfArray);

    cout << endl;
    s.performanceAnalysis();

    return 0;
}
