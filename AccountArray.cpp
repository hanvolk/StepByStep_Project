/*
  BankingSystem ver 9.0
  AccountArray 클래스의 함수들 정의  - Account 객체의 주소값을 저장하는 배열 클래스
*/

#include "BankingCommonDel.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len):arrlen(len)
{
    arr=new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[](int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[](int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array Index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
    return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
    delete []arr;
}
