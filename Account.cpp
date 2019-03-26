/*
  BankingSystem ver 11.0
  Account Ŭ����(Entity Class) �� �Լ����� ����
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
    cout<<"����ID : "<<accID<<endl;
    cout<<"��  �� : "<<cusName<<endl;
    cout<<"��  �� : "<<balance<<endl;
}
