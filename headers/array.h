#ifndef ARRAY_H
#define ARRAY_H
#include "number.h"

class Array{
private:
    int length;
    number *array;
public:
    Array(int length = 0);
    void fill(int n);
    ~Array();
    int changeLength(int new_length);
    void add();
    void printArray();
    number average();
    number sko();
    void sortIncrease();
    void sortDecrease();
    void changeElem(int index, int value);

};

#endif // ARRAY_H