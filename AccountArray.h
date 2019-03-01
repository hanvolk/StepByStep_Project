/*
  BankingSystem ver 9.0
  AccountArray 클래스 정의 - Account 객체의 주소값을 저장하는 배열 클래스
*/

#ifndef __ACCOUNTARRAY_H__
#define __ACCOUNTARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
    ACCOUNT_PTR* arr;
    int arrlen;
    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}
    BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr){}
public:
    BoundCheckAccountPtrArray(int len=100);
    ACCOUNT_PTR& operator[](int idx);
    ACCOUNT_PTR operator[](int idx) const;
    int GetArrLen() const;
    ~BoundCheckAccountPtrArray();

};
#endif // __ACCOUNTARRAY_H__
