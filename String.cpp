/*
  BankingSystem ver 9.0
  String 클래스의 함수 정의 - 문자열을 다루는 클래스
*/

#include "BankingCommonDel.h"
#include "String.h"


String::String():len(0)
{
    str=NULL;
}

String::String(const char* sptr)
{
    len=strlen(sptr)+1;
    str=new char[len];
    strcpy(str,sptr);
}

String::String(const String& ref)
{
    len=ref.len;
    str=new char[len];
    strcpy(str,ref.str);
}

String::~String()
{
    if(str!=NULL)
        delete []str;
}

String& String::operator=(const String& ref)
{
    delete []str;
    str=new char[ref.len];
    strcpy(str,ref.str);
    return *this;
}

String String::operator+(const String& ref)
{
    char* temp_str = new char[len+ref.len-1];
    strcpy(temp_str,str);
    strcat(temp_str,ref.str);

    String temp(temp_str);
    delete []temp_str;
    return temp;
}

String& String::operator+=(const String& ref)
{
    char* temp_str=new char[len+ref.len-1];
    strcpy(temp_str,str);
    strcat(temp_str,ref.str);

    if(str!=NULL)
        delete []str;

    str=temp_str;
    return *this;
}

bool String::operator==(const String& ref)
{
    if(strcmp(str,ref.str)==0)
        return true;
    else
        return false;

}

ostream& operator<<(ostream& os, const String& ref)
{
    cout<<ref.str;
    return os;
}

istream& operator>>(istream& is, String& ref)
{
    fflush(stdin); // 문자열을 입력 받기 전에 입력 버퍼를 지워 준다.

    char buf[100];
    gets(buf);
    ref=String(buf);
    return is;
}
