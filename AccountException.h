/*
    Banking Systemm ver 11
    Define Exception Class
*/

#ifndef __ACOUNTEXCEPTION_H__
#define __ACOUNTEXCEPTION_H__
#include "BankingCommonDel.h"


class WithDrawException
{
private:
    int balance;
public:
    WithDrawException(int money):balance(money)
    { }
    void ShowExceptionReason()
    {
        cout<<"[���� �޽��� : �ܾ� "<<balance<<", �ܾ� ���� ]";
    }
};

class MinusMoneyException
{
private:
    int expn_num;
public:
    MinusMoneyException(int num):expn_num(num){}
    void ShowExceptionReason()
    {
        cout<<"�ݾ׿� ������ �Է� �Ǿ����ϴ�.";
    }
};



#endif // __
