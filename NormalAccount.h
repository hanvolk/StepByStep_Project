/*
  BankingSystem ver 6.0
  NormalAccount(보통예금 계좌) 클래스의 정의
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
// 보통계금 계좌 : 최소한의 이자를 지급하는 자율 입출금식 계좌

#include "Account.h"

class NormalAccount:public Account
{
private:
    int interRate;  // 이자율 %단위
public:
    NormalAccount(int ID, int money, char* name, int rate):Account(ID,money,name), interRate(rate)
    {
        // Normal Account Class의 객체 생성과정에서 생성자로 이자율(interRate) 정보를 등록 하고 있다.
    }

    virtual void Deposit(int money)
    {
        Account::Deposit(money); //원금추가
        Account::Deposit(money*(interRate/100.0));  // 이자추가
    }
};
#endif // __NORMAL_ACCOUNT_H__

