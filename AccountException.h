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
        cout<<"[예외 메시지 : 잔액 "<<balance<<", 잔액 부족 ]";
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
        cout<<"금액에 음수가 입력 되었습니다.";
    }
};



#endif // __
