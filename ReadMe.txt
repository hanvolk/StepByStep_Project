StepByStep Project ver 5.0

��� ������ ����ϴ� ��Ʈ�� Ŭ���� AccountHandler �� ���� 
class AccountHandler
{
private:
    Account* accArr[100];  // Accout ������ ���� �迭, Account.h �� �������� ���� �Ǿ� �ִ� �迭�ε� , AccountHandelr Ŭ������ Private �������� �̵� 
    int accNum;              // �� ������ ����, Account.h �� �������� ���� �Ǿ� �ִ� �迭�ε� , AccountHandelr Ŭ������ Private �������� �̵� 
public:
    AccountHandler();
    void ShowMenu(void);
    void MakeAccout(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    ~AccountHandler();
};

/*
  ���� ������ ������, ������ ���� ������ ��� �ִ� accArr �迭 �̳�, accNum ������ �������� �θ� ��𼭳� ���� ������ ���°� �ǹǷ� ���α׷��� �������� ���� �ʴ�. 
  AccountHandler ��� ��Ʈ�� Ŭ������ ������ ����, �� ��Ʈ�� �ڵ鷯�� ���ؼ��� ���� �����ϰ� ���� �����μ� ���������� ���� 
*/

�Լ��� ��ġ �̵�
DefineFunc.cpp �� �ִ� �Լ��� �� 
   ������ ����� ����ߴ� 
      void ShowMenu()  	//�޴��� ���
      void MakeAccout()	// ������ ����
      void DepositMoney()	// �Ա� ��� ����
      void WithdrawMoney()	// ��� ��� ����
      void ShowAllAccInfo()	// ��� ���� ���� ��� 
  �̷��� �Լ����� AccountHandler Ŭ������ �ɹ� �Լ��� ���� 


DefineFunc.cpp �� �ִ� �Լ��� �� 
   ���� Account �� ������ ���� ���� �ϴ� �Լ����� 
     Account(int ID, int money, char* name)	// ������
     void Deposit(int money)			// �Ա�
     void Withdraw(int money)		// ���
     void ShowAccInfo() const		// �������� ���
     ~Account()   				// �Ҹ���
 �̷��� �Լ����� Account.cpp ��� ������ ���� ���� �Լ� ���� 

�� 
  Entity Ŭ���� Account.h �� �׿� ���� �Լ��� ���� Account.cpp
  Control Ŭ���� AccountHandler.h �� �׿� ���� �Լ��� ���� AccountHandler.cpp 
�� ���� ���� �Ǿ���
  Declaration.h  �� DefineFunc.cpp ������ ���� �ߴ�.

����
 Main �Լ����� AccountHandler ��ü manager�� ����
  manager.ShowMenu()
  manager.MakeAccount() 
�̷��� ����� ���� �ϰ� �ȴ�.


   