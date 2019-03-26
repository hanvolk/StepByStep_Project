/*
  BankingSystem ver 11.0
  String 클래스 정의 - 문자열을 다루는 클래스
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
    String(const char* sptr); // 생성자
    String(const String& ref);  // 복사 생성자
    ~String(); // 소멸자

    /* String class 연산자 오버로딩 */
    String& operator=(const String& ref);
    String operator+(const String& ref);
    String& operator+=(const String& ref);

    bool operator==(const String& ref);

    friend ostream& operator<<(ostream& os, const String& ref);
    friend istream& operator>>(istream& os, String& ref);

};


#endif
