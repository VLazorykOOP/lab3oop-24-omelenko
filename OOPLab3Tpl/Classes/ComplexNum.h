#include <string>
#include <iostream>

using namespace std;

class ComplexNum
{
    private:
        float im;
        float re;
        int state;
        static int objectCount;
    public:
        ComplexNum();

        ComplexNum(float num);

        ComplexNum(ComplexNum* num);

        ComplexNum(const ComplexNum &num);

        ~ComplexNum();

        void SetComplexNum(float i, float r);

        float GetIm() const {return im;}
        float GetRe() const {return re;}
        int GetState() const { return state; }
        static int GetObjectCount() { return objectCount; }

        string Print();

        float Norm();

        ComplexNum operator+(ComplexNum const& obj);

        ComplexNum operator-(ComplexNum const& obj);

        ComplexNum operator*(ComplexNum const& obj);

        ComplexNum operator/(ComplexNum const& obj);

        ComplexNum operator/(short const& obj);

        bool operator==(ComplexNum const& obj);

        bool operator>(ComplexNum const& obj);

        bool operator<(ComplexNum const& obj);


};