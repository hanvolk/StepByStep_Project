/*
  BankingSystem ver 11.0
  Account 클래스(Entity Class) 대한 클래스의 정의
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

    String cusName;   // char* cusName 을 String Class 로 변경

public:
    Account(int ID, int money, String name);
  /* String 클래스 도입으로 복사 생성좌와 대입 연산자, 소멸자 를 따로 정의 할 필요가 없어 졌다.
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

