/*
  BankingSystem ver 3.0
  계좌 정보에 대한 클래스의 정의
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "BankingCommonDel.h"

class Account
{
private:
    int accID;      //계좌번호
    int balance;    //잔   액
    char* cusName;  //고객이름 , char형 배열에서 char형 포인터 배열로 변경

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int GetAccID();
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAllAccInfo();
    ~Account();
};

Account* accArr[100];  // Accout 저장을 위한 배열, Account 배열에서 Account 포인터 배열로 변경
int accNum=0;        // 저장된 Account 수

#endif // __ACCOUNT_H__

