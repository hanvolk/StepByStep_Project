/*
  BankingSystem ver 5.0
  ���� ������ ���� Ŭ������ ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "BankingCommonDel.h"

class Account
{
private:
    int accID;      //���¹�ȣ
    int balance;    //��   ��
    char* cusName;  //���̸� , char�� �迭���� char�� ������ �迭�� ����

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int GetAccID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};


#endif // __ACCOUNT_H__

