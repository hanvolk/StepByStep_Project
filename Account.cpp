/*
  BankingSystem ver 11.0
  Account 클래스(Entity Class) 의 함수들의 정의
*/
#include "BankingCommonDel.h"
#include "Account.h"


Account::Account(int ID, int money, String name):accID(ID), balance(money)
{
    cusName=name;
    //cusName=new char[strlen(name)+1];
    //strcpy(cusName,name);
}

int Account::GetAccID() const{return accID;}
void Account::Deposit(int money)
{
    if(money<0)
        throw MinusMoneyException(money);

    balance+=money;
}
int Account::Withdraw(int money)
{
    if(money<0)
        throw MinusMoneyException(money);

    if(balance<money)
        throw WithDrawException(balance);

    balance-=money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout<<"계좌ID : "<<accID<<endl;
    cout<<"이  름 : "<<cusName<<endl;
    cout<<"잔  액 : "<<balance<<endl;
}
