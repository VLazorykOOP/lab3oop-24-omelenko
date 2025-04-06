#include "Vector.h"
#include <string>

class Matrix {
    private:
        Vector* vectors;
        int rows;
        int state; // 0: OK, 1: Memory error, 2: Out of bounds, 3: Division by zero
        static int objectCount;

    public:
        Matrix();
        Matrix(int n);
        Matrix(int n, int m, long value);
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
        ~Matrix();

        void SetElement(int i, int j, long value = 0);
        long GetElement(int i, int j) const;
        std::string Print() const;
        int GetRows() const { return rows; }
        int GetState() const { return state; }
        static int GetObjectCount() { return objectCount; }

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix operator/(long scalar) const;

        bool operator==(const Matrix& other) const;
        bool operator>(const Matrix& other) const;
        bool operator<(const Matrix& other) const;
};