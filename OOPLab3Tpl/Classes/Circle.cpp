#include <string>
#include <iostream>
#include <cmath>
#include "Circle.h"
#include <corecrt_math_defines.h>

using namespace std;

Circle::Circle(double r)
{
    radius = r;
    color = "White";
}

Circle::Circle(double r, string c)
{
    radius = r;
    color = c;
}

void Circle::Print()
{
    cout << "Radius: " << radius << endl;
    cout << "Color: " << color << endl;
}

double Circle::Area()
{
    return ( M_PI * (radius * radius));
}

double Circle::Length()
{
    return (2 * M_PI * radius);
}

void Circle::SetRadius(double r)
{
    if(r < 0) 
    {
        cout << "Radius cannot be less or equal to 0";
    }
    else
    {
        radius = r;
    }
}

void Circle::SetColor(string c)
{
    color = c;
}

double Circle::GetRadius() {return radius;}
string Circle::GetColor() {return color;}