/*
  BankingSystem ver 5.0
  Account 클래스에 대한 함수 정의
*/

#include "BankingCommonDel.h"
#include "Account.h"

Account::Account():accID(0), balance(0){cusName=NULL;};  // Default Constructor

Account::Account(int ID, int money, char* name):accID(ID), balance(money)
{
    cusName=new char[strlen(name)+1];
    strcpy(cusName,name);
}

Account::Account(const Account& ref):accID(ref.accID), balance(ref.balance)
{
    cusName=new char[strlen(ref.cusName)+1];
    strcpy(cusName,ref.cusName);
}

int Account::GetAccID() const{return accID;}
int Account::GetBalance(){return balance;};
char* Account::GetCusName(){return cusName;};

void Account::Deposit(int money)
{
    balance+=money;
}

int Account::Withdraw(int money)
{
    balance-=money;
}

void Account::ShowAccInfo() const
{
    cout<<" "<<accID<<"     "<<cusName<<"      "<<balance;
}
Account::~Account(){delete []cusName;};

