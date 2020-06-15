#pragma once
#pragma once
#include<iostream>
#include<ctime>
using namespace std;
class Array
{
	long* arr; // dynamic data
	int size;
	bool isValid(int a) const
	{
		return a > 0 && a <= size;
	}
	bool arrCorect(long* arr) const
	{
		return arr != nullptr;
	}
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	//copy array
	Array(const Array& other) {

		this->size = other.size;
		arr = new long[size];
		for (int i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	// fill your array value 0
	Array(int size)
	{
		this->size = size;
		arr = new long[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	//destructor
	~Array()
	{
		delete[] arr;
	}
	//copy constructor, destructor, methods...
	//fill array random value
	void randArray(int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 100 + 1;
		}
	}

	//print array
	void Print() const
	{
		cout << "Array (size=" << size << "): ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ", ";
		}
		cout << endl;
	}
	//print lowest and hights value in your array and avarage value
	void findMinMaxAvarage()
	{
		if (arrCorect(arr)) {
			long min = arr[0];
			long max = arr[0];
			long avg = 0;
			long sum = 0;
			for (int i = 0; i < size; i++) {
				sum += arr[i];
				if (min > arr[i])
					min = arr[i];
				if (max < arr[i])
					max = arr[i];
			}
			avg = sum / size;
			cout << "Avarage value of array : " << avg << endl;
			cout << "Minimum value of array: " << min << endl;
			cout << "Maximum value of array: " << max << endl;
		}
		else
		{
			cout << "error your array is empty" << endl;
		}

	}
	// adding element to array
	void addElemt(long a) {

		long* arr = new long[this->size++];
		for (int i = 0; i < size; i++) {
			arr[i] = this->arr[i];
		}
		if (this->arr != 0)
			delete[] this->arr;
		arr[this->size] = a;
		this->arr = arr;
		this->size++;

	}
	// sortinng array from lovest lo hights value
	void sortArray() const
	{
		if (arrCorect(arr)) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (arr[j] > arr[j + 1]) {
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
			Print();
			cout << "____________________________________________" << endl;
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - 1; j++) {
					if (arr[j] < arr[j + 1]) {
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}

				}

			}
			Print();
		}
		else
			cout << "error your array is empty" << endl;
	}
	//remove element from array by index
	void  removeByIndex(int a)
	{
		if (arrCorect(arr)) {
			a = a - 1;
			if (isValid(a)) {
				for (int i = a; i < size; i++)
					arr[a] = arr[a + 1];
				arr[size - 1] = 0;
			}
			else
			{
				cout << "error" << endl;
			}
		}
		else
		{
			cout << "Error there is no element with index " << a << "in your array" << endl;
		}
	}

	Array operator--();
	Array operator--(int);
	Array operator++();
	Array operator++(int);
	Array operator- ();
	Array operator= (const Array& other);
	operator long();
	operator char* ();
	long operator()(long value)const;

	long& operator[](int index)const;

	int operator[](long ele)const;
};