/*
  BankingSystem ver 11.0
  String Ŭ���� ���� - ���ڿ��� �ٷ�� Ŭ����
*/

#ifndef __STRING_H__
#define __STRING_H__
#include "BankingCommonDel.h"

class String
{
private:
    char* str;
    int len;
public:
    String();
    String(const char* sptr); // ������
    String(const String& ref);  // ���� ������
    ~String(); // �Ҹ���

    /* String class ������ �����ε� */
    String& operator=(const String& ref);
    String operator+(const String& ref);
    String& operator+=(const String& ref);

    bool operator==(const String& ref);

    friend ostream& operator<<(ostream& os, const String& ref);
    friend istream& operator>>(istream& os, String& ref);

};


#endif
