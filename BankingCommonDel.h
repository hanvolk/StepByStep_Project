/*
  BankingSystem ver 9.0
  공통 헤더 및 Enum 상수들
*/

#ifndef __BANKINGCOMMONDEL_H__
#define __BANKINGCOMMONDEL_H__

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int NAME_LEN=20;

// Menu 화면에서 선택
enum{MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

//계좌의 종료
enum{NORMAL=1, CREDIT=2};

//신용 등급
enum{LEVEL_A=7, LEVEL_B=4, LEVEL_C=2};

#endif // __BANKINGCOMMONDEL_H__
