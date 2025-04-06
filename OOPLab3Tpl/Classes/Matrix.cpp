#include "Matrix.h"
#include <iostream>

int Matrix::objectCount = 0;

Matrix::Matrix() {
    rows = 5;
    state = 0;
    vectors = new (std::nothrow) Vector[rows];
    if (!vectors) 
    {
        rows = 0;
        state = 1; // Memory error
        std::cout << "Memory allocation failed in default constructor" << std::endl;
    } 
    else 
    {
        for (int i = 0; i < rows; i++) vectors[i] = Vector(5);
    }
    objectCount++;
}

Matrix::Matrix(int n) {
    rows = (n > 0) ? n : 0;
    state = 0;
    vectors = new (std::nothrow) Vector[rows];
    if (!vectors) 
    {
        rows = 0;
        state = 1;
        std::cout << "Memory allocation failed in size constructor" << std::endl;
    } 
    else 
    {
        for (int i = 0; i < rows; i++) vectors[i] = Vector(n);
    }
    objectCount++;
}

Matrix::Matrix(int n, int m, long value) {
    rows = (n > 0) ? n : 0;
    state = 0;
    vectors = new (std::nothrow) Vector[rows];
    if (!vectors) 
    {
        rows = 0;
        state = 1;
        std::cout << "Memory allocation failed in value constructor" << std::endl;
    } 
    else 
    {
        for (int i = 0; i < rows; i++) vectors[i] = Vector(m, value);
    }
    objectCount++;
}

Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    state = other.state;
    vectors = new (std::nothrow) Vector[rows];
    if (!vectors) 
    {
        rows = 0;
        state = 1;
        std::cout << "Memory allocation failed in copy constructor" << std::endl;
    } 
    else 
    {
        for (int i = 0; i < rows; i++) vectors[i] = other.vectors[i];
    }
    objectCount++;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) 
    {
        delete[] vectors;
        rows = other.rows;
        state = other.state;
        vectors = new (std::nothrow) Vector[rows];
        if (!vectors) 
        {
            rows = 0;
            state = 1;
            std::cout << "Memory allocation failed in assignment" << std::endl;
        } 
        else 
        {
            for (int i = 0; i < rows; i++) vectors[i] = other.vectors[i];
        }
    }
    return *this;
}

Matrix::~Matrix() {
    delete[] vectors;
    objectCount--;
}

void Matrix::SetElement(int i, int j, long value) {
    if (i >= 0 && i < rows && j >= 0 && j < vectors[0].GetSize()) 
    {
        vectors[i].SetElement(j, value);
    } 
    else 
    {
        state = 2; // Out of bounds
        std::cout << "Index out of bounds: (" << i << ", " << j << ")" << std::endl;
    }
}

long Matrix::GetElement(int i, int j) const {
    if (i >= 0 && i < rows && j >= 0 && j < vectors[0].GetSize()) 
    {
        return vectors[i].GetElement(j);
    } 
    else
    {
        //state = 2; // Out of bounds
        std::cout << "Index out of bounds: (" << i << ", " << j << ")" << std::endl;
        return 0;
    }
}

std::string Matrix::Print() const {
    std::string result = "Matrix (" + std::to_string(rows) + "x" + std::to_string(vectors[0].GetSize()) + "):\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            result += std::to_string(vectors[i].GetElement(j)) + " ";
        }
        result += "\n";
    }
    result += "State: " + std::to_string(state) + "\n";
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || vectors[0].GetSize() != other.vectors[0].GetSize()) 
    {
        Matrix res;
        res.state = 2;
        std::cout << "Matrix sizes do not match for addition" << std::endl;
        return res;
    }
    Matrix res(rows, vectors[0].GetSize(), 0);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            res.vectors[i].SetElement(j, vectors[i].GetElement(j) + other.vectors[i].GetElement(j));
        }
    }
    return res;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || vectors[0].GetSize() != other.vectors[0].GetSize()) 
    {
        Matrix res;
        res.state = 2;
        std::cout << "Matrix sizes do not match for subtraction" << std::endl;
        return res;
    }
    Matrix res(rows, vectors[0].GetSize(), 0);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            res.vectors[i].SetElement(j, vectors[i].GetElement(j) - other.vectors[i].GetElement(j));
        }
    }
    return res;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (vectors[0].GetSize() != other.rows) 
    {
        Matrix res;
        res.state = 2;
        std::cout << "Matrix sizes do not match for multiplication" << std::endl;
        return res;
    }
    Matrix res(rows, other.vectors[0].GetSize(), 0);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < other.vectors[0].GetSize(); j++) 
        {
            long sum = 0;
            for (int k = 0; k < vectors[i].GetSize(); k++) 
            {
                sum += vectors[i].GetElement(k) * other.vectors[k].GetElement(j);
            }
            res.vectors[i].SetElement(j, sum);
        }
    }
    return res;
}

Matrix Matrix::operator/(long scalar) const {
    if (scalar == 0) 
    {
        Matrix res;
        res.state = 3; // Division by zero
        std::cout << "Division by zero" << std::endl;
        return res;
    }
    Matrix res(rows, vectors[0].GetSize(), 0);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++)
        {
            res.vectors[i].SetElement(j, vectors[i].GetElement(j) / scalar);
        }
    }
    return res;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || vectors[0].GetSize() != other.vectors[0].GetSize()) return false;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            if (vectors[i].GetElement(j) != other.vectors[i].GetElement(j)) return false;
        }
    }
    return true;
}

bool Matrix::operator>(const Matrix& other) const {
    if (rows != other.rows || vectors[0].GetSize() != other.vectors[0].GetSize()) return false;
    long sumThis = 0, sumOther = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            sumThis += vectors[i].GetElement(j);
            sumOther += other.vectors[i].GetElement(j);
        }
    }
    return sumThis > sumOther;
}

bool Matrix::operator<(const Matrix& other) const {
    if (rows != other.rows || vectors[0].GetSize() != other.vectors[0].GetSize()) return false;
    long sumThis = 0, sumOther = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < vectors[i].GetSize(); j++) 
        {
            sumThis += vectors[i].GetElement(j);
            sumOther += other.vectors[i].GetElement(j);
        }
    }
    return sumThis < sumOther;
}