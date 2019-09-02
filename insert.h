#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i=0;i<size;i++){
                int chain=elements[i];
                int j=i-1;
                while(j>=0 and elements[j]>chain){
                    elements[j+1]=elements[j];
                    j=j-1;
                }
                elements[j+1]=chain;
            }
        }

        inline string name() { return "InsertSort"; }
};

#endif