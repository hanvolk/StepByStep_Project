/*
     BankingSystem ver 5.0
     ���α׷��� ����� ����ϴ� ��Ʈ�� Ŭ���� AccountHandler �Լ����� ����
*/
#include "BankingCommonDel.h"
#include "AccountHandler.h"
#include "Account.h"

void AccountHandler::ShowMenu(void) // ��ü �޴� ���
{
    system("cls");
    cout<<"===== Menu ====="<<endl;
    cout<<"1. ���°���"<<endl;
    cout<<"2. ��   ��"<<endl;
    cout<<"3. ��   ��"<<endl;
    cout<<"4. �������� ��ü ���"<<endl;
    cout<<"5. ���α׷� ����"<<endl;
}
void AccountHandler::MakeAccout(void)  // ���� ����
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[���°���]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��  �� : "; cin>>name;
    fflush(stdin);
    cout<<"�Աݾ� : "; cin>>balance;
    cout<<endl;

    accArr[accNum++]=new Account(id,balance,name);

    cout<<name<<"���� �ű� ���� ������ �Ϸ� �Ǿ����ϴ�."<<endl;
    cout<<"accNum : "<<accNum<<endl;
    fflush(stdin);
    getchar();
    StoreAccData();

}

void AccountHandler::DepositMoney(void) // �Ա� ���
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"�Աݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            accArr[i]->Deposit(money);
            cout<<"�ԱݿϷ�"<<endl<<endl;
            StoreAccData();
            fflush(stdin);
            getchar();
            return;
        }
    }
    cout<<"��ȿ���� ���� ID �Դϴ�."<<endl<<endl;
    fflush(stdin);
    getchar();
}

void AccountHandler::WithdrawMoney(void) // ��� ���
{
    int money;
    int id;
    cout<<"[��   ��]"<<endl;
    cout<<"����ID : "; cin>>id;
    cout<<"��ݾ� : "; cin>>money;

    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccID()==id)
        {
            if(accArr[i]->Withdraw(money)==0)
            {
                cout<<"�ܾ׺���"<<endl<<endl;
                fflush(stdin);
                getchar();
                return;
            }

            cout<<"��ݿϷ�"<<endl<<endl;
            StoreAccData();
            fflush(stdin);
            getchar();
            return;
        }
    }
}
void AccountHandler::ShowAllAccInfo(void) // ��ü ���� ���� ���
{
    cout<<"����ID"<<"    "<<"�� ��"<<"      "<<"�� ��"<<endl;
    for(int i=0;i<accNum;i++)
    {
        accArr[i]->ShowAccInfo();
        cout<<endl;
    }

    cout<<"�� ���¼� : "<<accNum<<endl;
    fflush(stdin);
    getchar();
}

void AccountHandler::Exit(void) // ���α׷� ����
{
    for(int i=0;i<accNum;i++)
            delete accArr[i];
}

void AccountHandler::StoreAccData(void) // �������� ����
{
    FILE* fpw=fopen("PhoneData.dat","wb");
    if(fpw==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �߽��ϴ�."<<endl;
        fflush(stdin);
        getchar();
    }

    fwrite((void*)&accNum,sizeof(int),1,fpw);
    //���� ���� �� �κп� �� ���¼� ������ ���

    for(int i=0;i<accNum;i++)
    {
        bufAcc buf(accArr[i]->GetAccID(), accArr[i]->GetBalance(),accArr[i]->GetCusName());
        /*
           bufAcc Ŭ������ ���� ���� ����, �ҷ����⸦ ���� ������ Ŭ������ �̸��� �����ϴ� �ɹ����� cusName��
           char* ���� �ƴ�, char�� �迭�� ���� �Ǿ� �ֱ� ������ ���Ͽ� �̸� ���ڿ��� ����� ���� �� �� �ִ�.
        */

        fwrite((void*)&buf,sizeof(bufAcc),1,fpw);
    }

    fflush(stdin);
    fclose(fpw);
}

void AccountHandler::LoadAccData(void) // �������� �ε�
{
    int i=0;
    bufAcc* buf=new bufAcc();
    /* bufAcc�� ����� �ҷ����⸦ ���� ������ Ŭ������
       bufAcc�� �ӽ� ��ü�� ����
         ==> �� �ּҰ��� bufAcc ������ �� ��ü buf�� ���� */


    FILE* fpr=fopen("PhoneData.dat","rb");
    if(fpr==NULL)
    {
        cout<<"������ �ҷ� ���µ� ���� �Ͽ����ϴ�."<<endl;

        getchar();
        return;
    }

    fread((void*)&accNum,sizeof(int),1,fpr);
    // ������ ���� �� �κп� ����� ��ü ���¼� ������ �����Ƿ� �װ� ���� �ҷ� �ͼ� accNum�� �ʱ�ȭ

    cout<<"accNum : "<<accNum<<endl;

    while(i<accNum)
    {
        fread((void*)buf,sizeof(bufAcc),1,fpr);
        // fpr(���� ������)���� �ѹ��� bufAcc ũ�⸸ŭ�� �����͸�
        // buf(bufAcc�� ������)�� ����

        accArr[i]=new Account(buf->GetID(),buf->Getbalance(),buf->GetcusName());
        /*
          accArr �迭��(Account ������ �迭) buf�� ����� ���� Account �ӽ� ��ü�� ���� ��
          �� �ּҰ��� ���� �Ҵ� �ؼ� ���Ͽ� ���� ���� ���� �ҷ��ͼ� �����ϰ� �ִ�.
        */

        i++;
    }


    fclose(fpr);
}

void AccountHandler::DeleteAccount(void)
{
    int idx;
    cout<<"[���� ����]"<<endl;
    cout<<"���� Index: "; cin>>idx;
    delete accArr[idx-1];

    for(int i=idx-1;i<accNum-1;i++)
    {
        accArr[i]=accArr[i+1];
    }
    accNum--;

    cout<<"������ �Ϸ� �Ǿ����ϴ�. "<<endl<<endl;
    StoreAccData();
    fflush(stdin);
    getchar();

}

