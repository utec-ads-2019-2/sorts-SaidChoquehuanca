#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i=0;i<size-1;i++){
                int minimo=i;
                for(int j=i+1;j<size;j++){
                    if(elements[j]<elements[minimo]){
                        minimo=j;}}
                    int temp = elements[minimo];
                    elements[minimo]= elements[i];
                    elements[i]=temp;
            }
            // TODO
        }

        inline string name() { return "SelectSort"; }
};

#endif