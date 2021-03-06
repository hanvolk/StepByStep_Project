/*
  BankingSystem ver 10.0
  BoundCheckArray 클래스의 템플릿 작성
  (BoundCheckArray 클래스를 템플릿화)
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "BankingCommonDel.h"
#include "Account.h"

template<typename T>
class BoundCheckArray
{
private:
    T* arr;
    int arrlen;
    BoundCheckArray(const BoundCheckArray& arr){}
    BoundCheckArray& operator=(const BoundCheckArray& arr){}
public:
    BoundCheckArray(int len=100);
    T& operator[](int idx);
    T operator[](int idx) const;
    int GetArrLen() const;
    ~BoundCheckArray();
};

BoundCheckArray<T>::BoundCheckArray(int len):arrlen(len)
{
    arr=new T[len];
}

T& BoundCheckArray::operator[](int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

T BoundCheckArray<T>::operator[](int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckArray<T>::GetArrLen() const
{
    return arrlen;
}

BoundCheckArray<T>::~BoundCheckArray()
{
    delete []arr;
}


#endif // __ACCOUNTARRAY_H__
