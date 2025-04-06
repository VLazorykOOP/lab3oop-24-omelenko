#include <string>
#include <iostream>
#include "ComplexNum.h"

using namespace std;

int ComplexNum::objectCount = 0;

ComplexNum::ComplexNum()
{
    im = 0;
    re = 0;
    state = 0;
    objectCount++;
}

ComplexNum::ComplexNum(float num)
{
    im = num;
    re = num;
    state = !isnan(im) || !isnan(re) ? 0 : 3;
    objectCount++;
}

ComplexNum::ComplexNum(ComplexNum* num)
{
    if(num == nullptr) 
    {
        im = 0;
        re = 0;
        state = 2;
        cout << "Error: nullptr passed to constructor" << endl;
    }
    else
    {
        im = num->im;
        re = num->re;
        state = !isnan(im) || !isnan(re) ? 0 : 3;
    }
    objectCount++;
}

ComplexNum::ComplexNum(const ComplexNum &num)
{
    im = num.im;
    re = num.re;
    state = num.state;
    objectCount++;
}

ComplexNum::~ComplexNum()
{
    cout << "Im: " << im << endl;
    cout << "Re: " << re << endl;
    cout << "State: " << state << endl;
    objectCount--;
}

void ComplexNum::SetComplexNum(float i, float r)
{
    im = i;
    re = r;
    state = !isnan(im) || !isnan(re) ? 0 : 3;
}

string ComplexNum::Print() 
{
    string stateMsg;
    switch (state) {
        case 0: stateMsg = "OK"; break;
        case 1: stateMsg = "Division by zero"; break;
        case 2: stateMsg = "Nullptr error"; break;
        case 3: stateMsg = "NaN detected"; break;
        default: stateMsg = "Unknown"; break;
    }
    return "Im: " + to_string(im) + "\nRe: " + to_string(re) + "\nState: " + stateMsg + "\n";
}

float ComplexNum::Norm()
{
    float z = sqrt(((re*re)+(im*im)));
    return z >= 0 ? z : -z;
}

ComplexNum ComplexNum::operator+(ComplexNum const& obj)
{
ComplexNum res;
res.re = re + obj.re;
res.im = im + obj.im;
res.state = !isnan(im) || !isnan(re) ? 0 : 3;
return res;
}

ComplexNum ComplexNum::operator-(ComplexNum const& obj)
{
ComplexNum res;
res.re = re - obj.re;
res.im = im - obj.im;
res.state = !isnan(im) || !isnan(re) ? 0 : 3;
return res;
}

ComplexNum ComplexNum::operator*(ComplexNum const& obj)
{
ComplexNum res;
res.re = re * obj.re;
res.im = im * obj.im;
res.state = !isnan(im) || !isnan(re) ? 0 : 3;
return res;
}

ComplexNum ComplexNum::operator/(ComplexNum const& obj)
{
ComplexNum res;
res.re = re / obj.re;
res.im = im / obj.im;
res.state = !isnan(im) || !isnan(re) ? 0 : 3;
return res;
}

ComplexNum ComplexNum::operator/(short const& obj)
{
    if(obj != 0)
    {
        ComplexNum res;
        res.re = re / obj;
        res.im = im / obj;
        res.state = !isnan(im) || !isnan(re) ? 0 : 3;
        return res;
    }
    else
    {
        cout << "Cannot divide by 0";
        return this;
    }
}

bool ComplexNum::operator==(ComplexNum const& obj)
{
if(re == obj.re && im == obj.im) return true;
return false;
}

bool ComplexNum::operator>(ComplexNum const& obj)
{
if(re > obj.re && im > obj.im) return true;
return false;
}

bool ComplexNum::operator<(ComplexNum const& obj)
{
if(re < obj.re && im < obj.im) return true;
return false;
}