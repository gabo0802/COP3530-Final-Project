//Citation: Lecture PPT Sorting: Slide 122
#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Call static functions in main.cpp with "QuickSort<insert variable type>::insert method"
template<typename T>
class QuickSort {
private:
    static void swap(vector<T>& vector, int first, int last) {
        T temp = vector.at(first);
        vector.at(first) = vector.at(last);
        vector.at(last) = temp;
    }

    static int partition(vector<T>& vector, int low, int high) {
        //pivot is value at first index of vector
        T pivotValue = vector.at(low);
        //up and down are indexes
        int up = low;
        int down = high;

        //stops once the up and down indexes meet or pass each other
        while (up < down) {
            //stops when the "up" element is greater than the pivot element
            for (int j = up; j < high; j++) {
                if (vector.at(up) > pivotValue) {
                    break;
                }
                up++;
            }
            //stops when the "down" element is less than the pivot element
            for (int j = high; j > low; j--) {
                if(vector.at(down) < pivotValue) {
                    break;
                }
                down--;
            }
            //swaps the "up" and "down" elements
            if (up < down) {
                swap(vector, up, down);
            }
        }
        //swaps the value that the "down" index lands on with the pivot value
        swap(vector, low, down);
        return down;
    }

//passes in a vector, the lowest index, and highest index
    static void quickSort(vector<T>& vector, int low, int high) {
        if (low < high) {
            //splits vector in half
            int pivotIndex = partition(vector, low, high);
            //calls quicksort on left half of vector
            quickSort(vector, low, pivotIndex - 1);
            //calls quicksort on right half of vector
            quickSort(vector, pivotIndex + 1, high);
        }
    }

public:
    static vector<T> sortAscending(vector<T>& vector, int low, int high) {
        quickSort(vector, low, high);
        return vector;
    }

    static vector<T> sortDescending(vector<T>& vector, int low, int high) {
        quickSort(vector, low, high);
        reverse(vector.begin(), vector.end());
        return vector;
    }
};
//Mason Enojo

