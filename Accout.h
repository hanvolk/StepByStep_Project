/*
  BankingSystem ver 1.0
  ���� ������ ���� ����ü ����
*/
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include "BankingCommonDel.h"

typedef struct
{
    int accID;    // ���¹�ȣ
    int balance;  // ��   ��
    char cusName[NAME_LEN]; //���̸�
}Account;

Account accArr[100];  // Accout ������ ���� �迭
int accNum=0;        // ����� Account ��

#endif // __ACCOUNT_H__

