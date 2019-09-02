#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

    int divide(int *array, int indice_inicial, int indice_final) {
        int left,right,pivot,temp;
        pivot = array[indice_inicial];
        left = indice_inicial;
        right = indice_final;
        while (left < right) {
            while (array[right] > pivot) {
                right--;
            }
            while ((left < right) && (array[left] <= pivot)) {
                left++;
            }
            if (left < right) {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }
        temp = array[right];
        array[right] = array[indice_inicial];
        array[indice_inicial] = temp;
        return right;
    }
    void quicksort(int *array, int indice_inicial, int indice_final){
        int pivot;
        if (indice_inicial < indice_final) {
            pivot = divide(array, indice_inicial, indice_final);
            quicksort(array, indice_inicial, pivot - 1);
            quicksort(array, pivot + 1, indice_final);
        }
    }

    void execute() {
            quicksort(elements,0,size-1);
        }
        inline string name() { return "QuickSort"; }
};

#endif