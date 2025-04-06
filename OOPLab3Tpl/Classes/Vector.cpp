#include "Vector.h"
#include <iostream>

int Vector::objectCount = 0;

Vector::Vector() {
    size = 5;
    data = new (std::nothrow) long[size];
    if (!data) {
        size = 0;
        std::cout << "Memory allocation failed in default constructor" << std::endl;
    } else {
        for (int i = 0; i < size; i++) data[i] = 0;
    }
    objectCount++;
}

Vector::Vector(int n) {
    size = (n > 0) ? n : 5;
    data = new (std::nothrow) long[size];
    if (!data) {
        size = 0;
        std::cout << "Memory allocation failed in size constructor" << std::endl;
    } else {
        for (int i = 0; i < size; i++) data[i] = 0;
    }
    objectCount++;
}

Vector::Vector(int n, long value) {
    size = (n > 0) ? n : 5;
    data = new (std::nothrow) long[size];
    if (!data) {
        size = 0;
        std::cout << "Memory allocation failed in value constructor" << std::endl;
    } else {
        for (int i = 0; i < size; i++) data[i] = value;
    }
    objectCount++;
}

Vector::Vector(const Vector& other) {
    size = other.size;
    data = new (std::nothrow) long[size];
    if (!data) {
        size = 0;
        std::cout << "Memory allocation failed in copy constructor" << std::endl;
    } else {
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }
    objectCount++;
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new (std::nothrow) long[size];
        if (!data) {
            size = 0;
            std::cout << "Memory allocation failed in assignment" << std::endl;
        } else {
            for (int i = 0; i < size; i++) data[i] = other.data[i];
        }
    }
    return *this;
}

Vector::~Vector() {
    delete[] data;
    objectCount--;
}

long Vector::GetElement(int index) const {
    if (index >= 0 && index < size) return data[index];
    std::cout << "Index out of bounds: " << index << std::endl;
    return 0;
}

void Vector::SetElement(int index, long value) {
    if (index >= 0 && index < size) data[index] = value;
    else std::cout << "Index out of bounds: " << index << std::endl;
}