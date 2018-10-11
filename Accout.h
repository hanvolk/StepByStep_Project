/*
  BankingSystem ver 1.0
  계좌 정보에 대한 구조체 정의
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "BankingCommonDel.h"

typedef struct
{
    int accID;    // 계좌번호
    int balance;  // 잔   액
    char cusName[NAME_LEN]; //고객이름
}Account;

Account accArr[100];  // Accout 저장을 위한 배열
int accNum=0;        // 저장된 Account 수

#endif // __ACCOUNT_H__

