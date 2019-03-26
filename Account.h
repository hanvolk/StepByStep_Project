/*
  BankingSystem ver 11.0
  Account Ŭ����(Entity Class) ���� Ŭ������ ����
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"
#include "AccountException.h"

class Account
{
private:
    int accID;
    int balance;

    String cusName;   // char* cusName �� String Class �� ����

public:
    Account(int ID, int money, String name);
  /* String Ŭ���� �������� ���� �����¿� ���� ������, �Ҹ��� �� ���� ���� �� �ʿ䰡 ���� ����.
    Account(const Account& ref);
    Account& operator=(const Account& ref);
  */
    int GetAccID() const;
    virtual void Deposit(int money);
    virtual int Withdraw(int money);
    void ShowAccInfo() const;

   // ~Account();
};


#endif // __ACCOUNT_H__

