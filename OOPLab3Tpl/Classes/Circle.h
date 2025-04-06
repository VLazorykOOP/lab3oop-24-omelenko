#include <string>

using namespace std;

class Circle {
    private:
        double radius;
        string color;
    public:
        void Print();

        double Area();
        double Length();

        void SetRadius(double r);

        void SetColor(string c);

        double GetRadius();
        string GetColor();

};