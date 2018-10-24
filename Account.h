/*
  BankingSystem ver 6.0
  계좌 정보에 대한 클래스의 정의
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__


class Account
{
private:
    int accID;      //계좌번호
    int balance;    //잔   액
    char* cusName;  //고객이름 , char형 배열에서 char형 포인터 배열로 변경

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);

    int GetAccID() const;
    virtual void Deposit(int money);
    virtual int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};


#endif // __ACCOUNT_H__

