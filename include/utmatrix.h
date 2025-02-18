﻿// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора
#include <vector>
#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
  ValType *pVector;
  int Size;       // размер вектора
  int StartIndex; // индекс первого элемента вектора
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector &v);                // конструктор копирования
  ~TVector();
  int GetSize()      { return Size;       } // размер вектора
  int GetStartIndex(){ return StartIndex; } // индекс первого элемента
  ValType& operator[](int pos);             // доступ
  bool operator==(const TVector &v) const;  // сравнение
  bool operator!=(const TVector &v) const;  // сравнение
  TVector& operator=(const TVector &v);     // присваивание

  // скалярные операции
  TVector  operator+(const ValType &val);   // прибавить скаляр
  TVector  operator-(const ValType &val);   // вычесть скаляр
  TVector  operator*(const ValType &val);   // умножить на скаляр

  // векторные операции
  TVector  operator+(const TVector &v);     // сложение
  TVector  operator-(const TVector &v);     // вычитание
  ValType  operator*(const TVector &v);     // скалярное произведение

  // ввод-вывод
  friend istream& operator>>(istream &in, TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend ostream& operator<<(ostream &out, const TVector &v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};

template <class ValType>
TVector<ValType>::TVector(int s = 10, int si = 0)
{
    if (si < 0 || si >= MAX_MATRIX_SIZE || s < 0 || s > MAX_VECTOR_SIZE)
    {
        throw exception("invalid argument of Tvector");
    }
    
    Size = s;
    StartIndex = si;
    pVector = new ValType[Size]{};
} /*-------------------------------------------------------------------------*/

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
    : Size(v.Size)
    , StartIndex(v.StartIndex)
{
    pVector = new ValType[Size];

    for (int i = 0; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < StartIndex || pos >= Size + StartIndex)
    {
        throw exception("Out of bounds TVector");
    }
    return pVector[(pos - StartIndex)];
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
    bool flag = 1;
    
    if ((StartIndex == v.StartIndex) && (Size == v.Size))
    {
        for (int i = 0; i < Size; i++)
        {
            if (pVector[i] != v.pVector[i])
            {
                flag = 0;
                break;
            }
        }
    }
    else
    {
        flag = 0;
    }

    return flag;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
    return(!(*this == v));
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
    if (this == &v)
    {
        return *this;
    }

    if (Size != v.Size)
    {
        delete[] pVector;
        pVector = NULL;
        Size = v.Size;
        pVector = new ValType[Size]{};
    }

    StartIndex = v.StartIndex;
    
    for (int i = 0; i < Size; i++)
    {
        pVector[i] = v.pVector[i];
    }
    return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
    
    TVector<ValType> res = *this;

    for (int i = 0; i < Size; i++)
    {
        res.pVector[i] += val;
    }

    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
    return(*this + (val*(-1)));
} /*-------------------------------------------------------------------------*/

template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
    TVector<ValType> res = *this;

    for (int i = 0; i < Size; i++)
    {
        res.pVector[i] = pVector[i] * val;
    }

    return res;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
    if (Size + StartIndex != v.Size + v.StartIndex)
    {
        throw exception("TVectors have different dim");
    }

    int S_max = max(Size, v.Size);
    int SI_min = min(StartIndex, v.StartIndex);
    TVector<ValType> res(S_max, SI_min);

    for (int i = 0; i < Size; i++)
    {
        res.pVector[S_max - Size + i] =  pVector[i];
    }
    for (int i = 0; i < v.Size; i++)
    {
        res.pVector[S_max - v.Size + i] = res.pVector[S_max - v.Size + i] + v.pVector[i];
    }
    return res;

} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
    TVector<ValType> curr = v;

    for (int i = 0; i < curr.Size; i++)
    {
        curr.pVector[i] = curr.pVector[i] * (-1);
    }

    return(*this + curr);
} /*-------------------------------------------------------------------------*/


template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
    if (Size + StartIndex != v.Size + v.StartIndex)
    {
        throw exception("Dimension of TVectors are not equal");
    }

    ValType res = 0;

    int S_min = min(Size, v.Size);
    for (int i = 0; i < S_min; i++)
    {
        res += pVector[Size - S_min + i] * v.pVector[v.Size - S_min + i];
    }

    return res;
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public: 

  TMatrix(int s = 10);                           
  TMatrix(const TMatrix &mt);                    // копирование
  TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;      // сравнение
  bool operator!=(const TMatrix &mt) const;      // сравнение
  TMatrix& operator= (const TMatrix &mt);        // присваивание
  TMatrix  operator+ (const TMatrix &mt);        // сложение
  TMatrix  operator- (const TMatrix &mt);        // вычитание

  // ввод / вывод
  friend istream& operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream & operator<<( ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
    if ((s < 0) || (s > MAX_MATRIX_SIZE))
    {
        throw exception ("invalid size of TMatrix ");
    }

    for (int i = 0; i < s; i++)
    {
        TVector<ValType> elem(s - i, i);
        pVector[i] = elem;
    }

} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):
  TVector<TVector<ValType> >(mt) {}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
  TVector<TVector<ValType> >(mt)
{}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
    return(TVector<TVector<ValType> > :: operator==(mt));
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
    return (!(TVector<TVector<ValType> >:: operator==(mt)));
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
    return(TMatrix<ValType>(TVector<TVector<ValType>>:: operator=(mt)));
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
    return(TVector<TVector<ValType>>:: operator+(mt));
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
    return(TVector<TVector<ValType>>:: operator-(mt));
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
