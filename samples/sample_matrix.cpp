// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  int size_m;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  cout << "Введите размер один размер для первой и второй матрицы: ";
  cin >> size_m;
  cout << "\n\n";
  TMatrix<int> a(size_m), b(size_m);
  cout << "Введите значения для первой треугольной матрицы(значения будут записываться построчно) : " << endl;
  
  for (int i = 0; i < a.GetSize(); i++) 
  {
      for (int j = i; j < a.GetSize(); j++)
      {
          cin >> a[i][j];
      }
  }

  cout << "\n\n Введите значения для второй треугольной матрицы(значения будут записываться построчно) : " << endl;

  for (int i = 0; i < b.GetSize(); i++)
  {
      for (int j = i; j < b.GetSize(); j++)
      {
          cin >> b[i][j];
      }
  }

  TMatrix<int> c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
}
//---------------------------------------------------------------------------
