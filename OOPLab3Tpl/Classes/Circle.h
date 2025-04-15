#include <string>

using namespace std;

class Circle {
    private:
        double radius;
        string color;
    public:
        Circle() {};
        Circle(double r);
        Circle(double r, string c);

        void Print();

        double Area();
        double Length();

        void SetRadius(double r);

        void SetColor(string c);

        double GetRadius();
        string GetColor();

};