/*
  BankingSystem ver 9.0
  AccountArray Ŭ���� ���� - Account ��ü�� �ּҰ��� �����ϴ� �迭 Ŭ����
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
