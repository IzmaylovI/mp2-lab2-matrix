// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  int size_m;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  cout << "������� ������ ���� ������ ��� ������ � ������ �������: ";
  cin >> size_m;
  cout << "\n\n";
  TMatrix<int> a(size_m), b(size_m);
  cout << "������� �������� ��� ������ ����������� �������(�������� ����� ������������ ���������) : " << endl;
  
  for (int i = 0; i < a.GetSize(); i++) 
  {
      for (int j = i; j < a.GetSize(); j++)
      {
          cin >> a[i][j];
      }
  }

  cout << "\n\n ������� �������� ��� ������ ����������� �������(�������� ����� ������������ ���������) : " << endl;

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
