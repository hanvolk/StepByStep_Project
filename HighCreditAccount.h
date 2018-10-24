/*
  BankingSystem ver 6.0
  HighCreditAccount(신용신뢰 계좌) 클래스의 정의
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount:public NormalAccount
{
private:
    int specialRate;
public:
    HighCreditAccount(int ID, int money, char* name, int rate, int special)
        :NormalAccount(ID, money, name, rate), specialRate(special)
    {
        // HighCreditAccount Class의 객체 생성과정에서 생성자로 이자율(specialRate) 정보를 등록 하고 있다.
    }

    virtual void Deposit(int money)
    {
        Account::Deposit(money); //원금추가
        Account::Deposit(money*(specialRate/100.0));  // 이자추가
    }
};

#endif // __HIGHCREDIT_ACCOUNT_H__
