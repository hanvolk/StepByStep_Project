/*
  BankingSystem ver 6.0
  HighCreditAccount(�ſ�ŷ� ����) Ŭ������ ����
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
        // HighCreditAccount Class�� ��ü ������������ �����ڷ� ������(specialRate) ������ ��� �ϰ� �ִ�.
    }

    virtual void Deposit(int money)
    {
        Account::Deposit(money); //�����߰�
        Account::Deposit(money*(specialRate/100.0));  // �����߰�
    }
};

#endif // __HIGHCREDIT_ACCOUNT_H__
