#include "array.h"
Array Array::operator--()
{
    for (int i = 0; i < this->size; i++) {
        arr[i]--;
    }
    return Array(*this);
}

Array Array::operator--(int)
{
    Array* temp = new Array[this->size];
    for (int i = 0; i < this->size; i++) {
        Array* temp = new Array[this->size];
        temp[i] = this->arr[i];
    }
    for (int i = 0; i < this->size; i++) {
        this->arr[i]--;
    }
    return Array(*temp);
}

Array Array::operator++()
{
    for (int i = 0; i < this->size; i++) {
        arr[i]++;
    }
    return Array(*this);
}

Array Array::operator-()
{
    for (int i = 0; i < this->size; i++) {
        this->arr[i] *= -1;

    }
    return Array(*this);
}

Array Array::operator++(int)
{
    Array temp = *this;
    for (int i = 0; i < this->size; i++) {
        this->arr[i]++;
    }
    return temp;
}

Array Array::operator= (const Array& other)
{
    this->size = other.size;
    this->arr = new long[other.size];
    for (int i = 0; i < other.size; i++) {
        this->arr[i] = other.arr[i];
    }
    return Array(*this);
}

Array::operator long()
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

Array::operator char* ()
{
    char* temp = new char[this->size];
    for (int i = 0; i < this->size; i++) {
        temp[i] = (char)arr[i];

    }
    return temp;
}

long Array::operator()(long value)const
{
    for (int i = 0; i < size; i++) {
        arr[i] *= value;
    }
    return Array();
}

long& Array::operator[](int index)const
{
    if(index >= 0 &&  index <= size)
    return arr[index];
}

int Array::operator[](long ele) const
{
    for (int i = 0; i < size; i++) {
        if (arr[i] == ele)
            return i;
    }
    return -1;
}
