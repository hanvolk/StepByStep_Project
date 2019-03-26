/*
   BankingSystem ver 11.0
   NormalAccount(보통예금 계좌) 클래스의 함수들 정의
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount:public NormalAccount
{
private:
    int specialRate;
public:
    //HighCreditAccount(int ID, int money, char* name, int rate, int special)
    HighCreditAccount(int ID, int money, String name, int rate, int special)
        :NormalAccount(ID, money, name, rate), specialRate(special)
    {
        // HighCreditAccount Class의 객체 생성과정에서 생성자로 이자율(specialRate) 정보를 등록 하고 있다.
    }

    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money); //원금과 이자 추가
        Account::Deposit(money*(specialRate/100.0));  // 이자추가
    }
};

#endif // __HIGHCREDIT_ACCOUNT_H__
