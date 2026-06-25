#pragma once
#include <iostream>

template <typename T>
// Extended dynamic array with custom methods
class List {
private:
    size_t length;
    size_t capacity;
    T* data = nullptr;
public:
    // Constructor create object of type List (by default with capacity = 2, length = 0). It recieves 2 parametrs (length, capacity)
    List(size_t length = 0, size_t capacity = 2) {
        if (length > capacity) {
            throw std::invalid_argument("length arg must be less than capacity");
        } else {
            this->length = length;
            this->capacity = capacity;
            this->data = new T[capacity];
        }
    }
    // Function "size" returns current length of List
    size_t size() const {
        return length;
    }
    // Function "cap" returns current capacity of List
    size_t cap() const {
        return capacity;
    }
    // Function "get" returns value by index
    T get(size_t index) const {
        if (index >= length) {
            throw std::out_of_range("Invalid index");
        }
        return data[index];
    }
    // Function "append" add new element at the end of the List
    void append(const T& value) {
        if (capacity == length) {
            T* new_arr = new T[capacity * 2];
            capacity *= 2;
            for (int i = 0; i < length; i++) {
                new_arr[i] = std::move(data[i]);
            }
            delete[] data;
            data = new_arr;
        }
        data[length] = value;
        length++;
    }
    // Function "pop" returns last value and delete it
    T pop() {
        // There is should be implemented pointer-checker and deletion of pointers. So actually it works only with simple types. Composite type will cause memory leak.
        length--;
        return data[length];
    }
    // Function "print" prints elements of non-composite types
    void print() const {
        // There is should be implemented override of composite types or functuion should recieve callback function to display custom types (optional)
        std::cout << "[";
        for (int i = 0; i < length; i++) {
            std::cout << data[i];
            if (i != length - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }
    // Overloaded operator of "[]" allows get access to data elements using indexs
    T& operator[](size_t index) {
        if (index >= length) {
            throw std::out_of_range("Invalid index");
        }
        return data[index];
    }
    // Overloaded operator of "+" allows link to Lists together and return third
    List operator+(const List& list) {
        size_t newLen = length + list.size();
        size_t newCap = capacity < newLen ? newLen * 2 : capacity;
        List newList(newLen, newCap);
        for (size_t i = 0; i < length; i++) {
            newList[i] = data[i];
        }
        for (size_t i = 0; i < list.size(); i++) {
            newList[length + i] = list.data[i];
        }
        return newList;
    }
    // Destructor delete private array pointer
    ~List() {
        delete[] data;
    }
};