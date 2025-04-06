#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    private:
        long* data;
        int size;
        static int objectCount;

    public:
        Vector();
        Vector(int n);
        Vector(int n, long value);
        Vector(const Vector& other);
        Vector& operator=(const Vector& other);
        ~Vector();

        long GetElement(int index) const;
        void SetElement(int index, long value);
        int GetSize() const { return size; }
        static int GetObjectCount() { return objectCount; }
};

#endif