// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//
#include <iostream>
#include "Classes/Circle.h"
#include "Classes/ComplexNum.h"
#include "Classes/Vector.h"
#include "Classes/Matrix.h"

#include "Lab3Example.h"

void task1()
{
    Circle circle;

    cout << "Initial radius: " << circle.GetRadius() << " (should be 0)" << endl;

    circle.SetRadius(5.0);
    cout << "Set radius to 5, got: " << circle.GetRadius() << " (should be 5)" << endl;

    cout << "Area with radius 5: " << circle.Area() << " (should be 78.5)" << endl;

    cout << "Length with radius 5: " << circle.Length() << " (should be 31.4)" << endl;

    circle.SetRadius(-1.0);
    cout << "After setting -1, radius: " << circle.GetRadius() << " (should still be 5)" << endl;

    circle.SetRadius(0.0);
    cout << "After setting 0, radius: " << circle.GetRadius() << " (should still be 5)" << endl;

    circle.SetColor("Blue");
    cout << "Color set to Blue, got: " << circle.GetColor() << " (should be Blue)" << endl;

    circle.Print();
    cout << "Print method";
}

void task2()
{
    cout << "Initial object count: " << ComplexNum::GetObjectCount() << endl;

    ComplexNum a;                    
    ComplexNum b(5);                
    ComplexNum c(new ComplexNum(3)); 
    ComplexNum d(nullptr);          
    ComplexNum e(c);               

    cout << "\nObject count after creation: " << ComplexNum::GetObjectCount() << endl;

    cout << "\na: " << a.Print();
    cout << "b: " << b.Print();
    cout << "c: " << c.Print();
    cout << "d: " << d.Print();
    cout << "e: " << e.Print();

    ComplexNum sum = b + c;
    cout << "\nb + c: " << sum.Print();

    ComplexNum diff = b - c;
    cout << "b - c: " << diff.Print();

    ComplexNum prod = b * c;
    cout << "b * c: " << prod.Print();

    ComplexNum div = b / c;
    cout << "b / c: " << div.Print();

    ComplexNum divScalar = b / 2;
    cout << "b / 2: " << divScalar.Print();

    ComplexNum divZero = b / 0;
    cout << "b / 0: " << divZero.Print();

    ComplexNum divComplexZero = b / ComplexNum();
    cout << "b / (0+0i): " << divComplexZero.Print();

    cout << "\nb == c: " << (b == c) << endl;
    cout << "b > c: " << (b > c) << endl;
    cout << "b < c: " << (b < c) << endl;

    cout << "\nNorm of b: " << b.Norm() << endl;

    b.SetComplexNum(1, 2);
    cout << "\nUpdated b: " << b.Print();

    cout << "\nObject count before destruction: " << ComplexNum::GetObjectCount() << endl;
}

void task3()
{
    std::cout << "Vector objects: " << Vector::GetObjectCount() << std::endl;
    std::cout << "Matrix objects: " << Matrix::GetObjectCount() << std::endl;

    // Тест конструкторів
    Matrix m1;               // За замовчуванням
    Matrix m2(3);            // Квадратна матриця
    Matrix m3(2, 3, 5);     // Матриця з ініціалізацією
    Matrix m4(m3);           // Копіювання

    std::cout << "\nAfter creation:\n";
    std::cout << "Vector objects: " << Vector::GetObjectCount() << std::endl;
    std::cout << "Matrix objects: " << Matrix::GetObjectCount() << std::endl;

    // Тест методів
    std::cout << "\nm1:\n" << m1.Print();
    std::cout << "m2:\n" << m2.Print();
    std::cout << "m3:\n" << m3.Print();
    std::cout << "m4:\n" << m4.Print();

    // Тест присвоєння елементу
    m3.SetElement(1, 1, 10);
    std::cout << "\nm3 after set (1,1) = 10:\n" << m3.Print();

    // Тест отримання елементу
    std::cout << "m3(1,1): " << m3.GetElement(1, 1) << std::endl;
    std::cout << "m3(5,5): " << m3.GetElement(5, 5) << std::endl; // Помилка

    // Тест операцій
    Matrix sum = m3 + m4;
    std::cout << "\nm3 + m4:\n" << sum.Print();

    Matrix diff = m3 - m4;
    std::cout << "m3 - m4:\n" << diff.Print();

    Matrix prod = m3 * Matrix(3, 2, 2); // 2x3 * 3x2
    std::cout << "m3 * (3x2):\n" << prod.Print();

    Matrix div = m3 / 2;
    std::cout << "m3 / 2:\n" << div.Print();

    Matrix divZero = m3 / 0;
    std::cout << "m3 / 0:\n" << divZero.Print();

    // Тест порівнянь
    std::cout << "\nm3 == m4: " << (m3 == m4) << std::endl;
    std::cout << "m3 > m4: " << (m3 > m4) << std::endl;
    std::cout << "m3 < m4: " << (m3 < m4) << std::endl;

    std::cout << "\nBefore destruction:\n";
    std::cout << "Vector objects: " << Vector::GetObjectCount() << std::endl;
    std::cout << "Matrix objects: " << Matrix::GetObjectCount() << std::endl;
}

int main()
{
    std::cout << " Lab #3  !\n";
    //  Код виконання завдань
    //  Головне меню завдань
    //  Функції та класи можуть знаходитись в інших файлах проекту
    task1();
    task2();    
    task3();
    return 0;
}



