/*
  BankingSystem ver 1.0
  BankingSystem�� �ʿ��� �Լ����� ����
*/

#include "BankingCommonDel.h"
#include "Declaration.h"
#include "Accout.h"

void ClearBuf(void)
{
    while(getchar()!='\n');
}

void ShowMenu(void)
{
    system("cls");
    cout<<"===== Menu ====="<<endl;
    cout<<"1. ���°���"<<endl;
    cout<<"2. ��   ��"<<endl;
    cout<<"3. ��   ��"<<endl;
    cout<<"4. �������� ��ü ���"<<endl;
    cout<<"5. ���α׷� ����"<<endl;
}

void MakeAccout(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[���°���]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��  �� : "; cin>>name;
    ClearBuf();
    cout<<"�Աݾ� : "; cin>>balance;
    cout<<endl;

    accArr[accNum].accID=id;
    accArr[accNum].balance=balance;
    strcpy(accArr[accNum].cusName,name);
    accNum++;

    cout<<name<<"���� �ű� ���� ������ �Ϸ� �Ǿ����ϴ�."<<endl;
    cout<<"accNum : "<<accNum<<endl;
    StoreAccData();
    ClearBuf();
    getchar();

}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"�Աݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i].accID==id)
        {
            accArr[i].balance+=money;
            cout<<"�ԱݿϷ�"<<endl<<endl;
            StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
    cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
    ClearBuf();
    getchar();
}

void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��ݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i].accID==id)
        {
            if(accArr[i].balance<money)
            {
                cout<<"�ܾ׺���"<<endl<<endl;
                ClearBuf();
                getchar();
                return;
            }
            accArr[i].balance-=money;
            cout<<"��ݿϷ�"<<endl<<endl;
            StoreAccData();
            ClearBuf();
            getchar();
            return;
        }
    }
}

void ShowAllAccInfo()
{
    for(int i=0;i<accNum;i++)
    {
        cout<<"����ID : "<<accArr[i].accID<<endl;
        cout<<"��  �� : "<<accArr[i].cusName<<endl;
        cout<<"��  �� : "<<accArr[i].balance<<endl<<endl;
    }

    cout<<"�� ���¼� : "<<accNum<<endl;
    ClearBuf();
    getchar();
}

void StoreAccData()
{

    FILE* fpw=fopen("PhoeData.dat","wb");
    if(fpw==NULL)
    {
        cout<<"���� ���忡 ������ �߻� �߽��ϴ�."<<endl;
        ClearBuf();
        getchar();
        return;
    }
    fwrite((void*)accArr,sizeof(Account),accNum,fpw);
    fclose(fpw);
}

void LoadAccData()
{
    int i=0,cnt=0;
    Account buf;
    FILE* fpr=fopen("PhoeData.dat","rb");
    if(fpr==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �Ͽ����ϴ�."<<endl;

        getchar();
        return;
    }

    while(1)
    {
        cnt=fread((void*)&buf,sizeof(Account),1,fpr);
        if(cnt<1)
            break;
        accArr[i]=buf;
        i++;
    }
    accNum=i;

    fclose(fpr);
    return;
}
