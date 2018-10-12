#pragma once

/*
  BankingSystem ver 1.0
  계좌 정보에 대한 구조체 정의
*/


class Account
{
private:
    int accID;    // 계좌번호
    int balance;  // 잔   액
    char *cusName; //고객이름
public:
    Account(int ID, int money, char* name);
    int GetAccID();
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo();
    ~Account(){delete []cusName;};
};

Account *accArr[100];  // Accout 저장을 위한 배열
int accNum;        // 저장된 Account 수


