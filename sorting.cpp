#include "sorting.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

/**
* Title : Algorithm Efficiency and Sorting
* Author : Munib Emre Sevilgen
* ID: 21602416
* Section : 1
* Assignment : 1
* Description : sorting functions implementations
*/

int MIN_SIZE = 30000;

void sorting::bubbleSort(int *arr, int size, int &compCount, int &moveCount){
    bool sorted = false; // False when swaps occur
    compCount = 0;
    moveCount = 0;
	int pass = 1;
	int temp;
	while (!sorted && (pass < size)) {
        // At this point, theArray[n+1-pass..n-1] is sorted
        // and all of its entries are > the entries in theArray[0..n-pass]
		sorted = true; // Assume sorted
       	for ( int index = 0; index < size - pass; index++){
 			// At this point, all entries in theArray[0..index-1]
            // are <= theArray[index]
 			int nextIndex = index + 1;
			if (arr[index] > arr[nextIndex]){
				// Exchange entries
				temp = arr[index];
				arr[index] = arr[nextIndex];
				arr[nextIndex] = temp;
				sorted = false; // Signal exchange
				moveCount = moveCount + 3;
			}
			compCount++;
       	}
        // Assertion: theArray[0..n-pass-1] < theArray[n-pass]
        pass++;
	}
}

void sorting::quickSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::quickSort(int *arr, int first, int last, int &compCount, int &moveCount){
    int pivotIndex;
    if (first < last) {
        // Create the partition: S1 | Pivot | S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        // Sort subarrays S1 and S2
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void sorting::partition( int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int temp;
    // Choose pivot as first
    int pivot = arr[first];
    // Determine the regions S 1 and S 2
    int lastS1 = first;
    int firstUnknown = first + 1;
    for (  ; firstUnknown <= last; ++firstUnknown) {
      // Locate first entry on left that is ≥ pivot
      if (arr[firstUnknown] < pivot) {
		  ++lastS1;
		  temp = arr[firstUnknown];
          arr[firstUnknown] = arr[lastS1];
          arr[lastS1] = temp;
    	  moveCount = moveCount + 3;
      }
      compCount++;
   }
   // Place pivot in proper position between S 1 and S 2 , and mark its new location
   temp = arr[first];
   arr[first] = arr[lastS1];
   arr[lastS1] = temp;
   moveCount = moveCount + 3;
   pivotIndex = lastS1;
}

void sorting::mergeSort(int *arr, int size, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, size - 1, compCount, moveCount);
}

void sorting::mergeSort(int *arr, int first, int last, int &compCount, int &moveCount){
    if (first < last){
        // Sort each half
        int mid = first + (last - first) / 2; // Get midpoint
        // Sort theArray[first..mid]
        mergeSort(arr, first, mid, compCount, moveCount);
        // Sort theArray[mid+1..last]
        mergeSort(arr, mid + 1, last, compCount, moveCount);
        // Merge sorted halves theArray[first..mid] and theArray[mid+1..last]
        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount){
    int tempArray[MIN_SIZE]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray

    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray

    while ((first1 <= last1) && (first2 <= last2)){
        compCount++;
        // At this point, tempArray[first..index-1] is in order
        if (arr[first1] <= arr[first2]){
            tempArray[index] = arr[first1];
            first1++;
            moveCount++;
        } else {
            tempArray[index] = arr[first2];
            first2++;
            moveCount++;
        }
        index++;
    }
    // Finish off the first subarray, if necessary
    while (first1 <= last1){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = arr[first1];
        first1++;
        index++;
        moveCount++;
    }
    // Finish off the second subarray, if necessary
    while (first2 <= last2){
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = arr[first2];
        first2++;
        index++;
        moveCount++;
    }
    // Copy the result back into the original array
    for (index = first; index <= last; index++) {
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void sorting::radixSort(int *arr, int size) {
    int largestNumber = arr[0];
    // Find the largest number in the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > largestNumber) {
            largestNumber = arr[i];
        }
    }

    for (int digitMultiplier = 1; largestNumber/digitMultiplier > 0; digitMultiplier *= 10) {
        int temp[size];
        int digit;
        int location[10] = {0};

        // Calculate the last locations of the corresponding digit (0, 1, 2, ... , 9)
        for (int i = 0; i < size; i++) {
            digit = ( arr[i] / digitMultiplier) % 10;
            // To shift the all of the indexes
            for(int j = digit; j < 10; j++)
                location[j]++;
        }

        // Rebuild the temporary array
        for (int i = size - 1; i >= 0; i--) {
            digit = ( arr[i] / digitMultiplier) % 10;
            temp[ location[digit] - 1 ] = arr[i];
            location[digit]--;
        }

        // Put the temporary array to the actual array
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }
    }
}

void sorting::printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void sorting::performanceAnalysis(){
    int compCount = 0;
    int moveCount = 0;
    double timeMeasured = 0;

    clock_t startTime;
    clock_t duration = 0;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Radix Sort" <<endl;
    cout << "Array Size   "<<"Time Elapsed"<<endl;
    for(int i = 2000; i <= 30000; i= i + 4000) {
        int arr[i];
        // Do the sort for a lot of array to get the time
        for(int j = 0; j < 10000000/i; j++) {
            // Fill the array with random numbers
            for(int k = 0; k < i; k++) {
                arr[k] = rand() % i + 1;
            }
            // Get the elapsed time
            startTime = clock();
            radixSort(arr,i);
            duration = duration + clock() - startTime;
        }
        timeMeasured = duration/(10000000/i);
        timeMeasured = timeMeasured/CLOCKS_PER_SEC;
        duration = 0;
        cout << std::setw(9) << std::left << i << ""<< std::setw(13) << std::right << timeMeasured << " ms" << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Bubble Sort" <<endl;
    cout << "Array Size   "<<"Time Elapsed   "<< "   compCount   "<<"   moveCount"<<endl;


    for(int i = 2000; i <= 30000; i= i + 4000) {
        int arr[i];
        // Fill the array with random numbers
        for(int j = 0; j < i; j++) {
            arr[j] = rand() % i + 1;
        }
        // Get the elapsed time
        startTime = clock();
        bubbleSort(arr,i,compCount,moveCount);
        timeMeasured = clock() - startTime;
        timeMeasured = timeMeasured/CLOCKS_PER_SEC;
        cout << std::setw(9) << std::left << i << ""<< std::setw(13) << std::right << timeMeasured << " ms" <<std::setw(15)<< compCount << std::setw(15)<< moveCount << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Quick Sort" <<endl;
    cout << "Array Size   "<<"Time Elapsed   "<< "   compCount   "<<"   moveCount"<<endl;
    for(int i = 2000; i <= 30000; i= i + 4000){
        int arr[i];
        // Do the sort for a lot of array to get the time
        for(int j = 0; j < 50000000/i; j++) {
            // Fill the array with random numbers
            for(int k = 0; k < i; k++) {
                arr[k] = rand() % i + 1;
            }
            // Get the elapsed time
            startTime = clock();
            quickSort(arr,i,compCount,moveCount);
            duration = duration + clock() - startTime;
        }
        timeMeasured = duration/(50000000/i);
        timeMeasured = timeMeasured/CLOCKS_PER_SEC;
        duration = 0;
        cout << std::setw(9) << std::left << i << ""<< std::setw(13) << std::right << timeMeasured << " ms" <<std::setw(15)<< compCount << std::setw(15)<< moveCount << endl;
    }

    cout << "-----------------------------------------------------------" << endl;
    cout << "Part c - Time analysis of Merge Sort" <<endl;
    cout << "Array Size   "<<"Time Elapsed   "<< "   compCount   "<<"   moveCount"<<endl;
    for(int i = 2000; i <= 30000; i= i + 4000) {
        int arr[i];
        // Do the sort for a lot of array to get the time
        for(int j = 0; j < 5000000/i; j++) {
            // Fill the array with random numbers
            for(int k = 0; k < i; k++) {
                arr[k] = rand() % i + 1;
            }
            // Get the elapsed time
            startTime = clock();
            mergeSort(arr,i,compCount,moveCount);
            duration = duration + clock() - startTime;
        }
        timeMeasured = duration/(5000000/i);
        timeMeasured = timeMeasured/CLOCKS_PER_SEC;
        duration = 0;
        cout << std::setw(9) << std::left << i << ""<< std::setw(13) << std::right << timeMeasured << " ms" <<std::setw(15)<< compCount << std::setw(15)<< moveCount << endl;
    }
    cout << "-----------------------------------------------------------" << endl;

}




