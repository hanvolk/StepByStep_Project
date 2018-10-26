StepByStep Project ver 6.0

-------------------------------------------------------------------------
                                           Account
-------------------------------------------------------------------------
  private:
    accID - int   // ���� ID
    balance - int   //  �ܾ� 
    cusName - char*   // �� �̸�

 public:
    Account(int ID, int Money, char* money); - constructor
    Account(const Account& ref);	- cpy constructor
    GetAccID() const  -  int
    virtual Deposit() - void
    Widthdraw() - int
    ShowAccInfo() - void
    ~ Account()
-----------------------------------------------------------------------------



/* NormalAccount : ���뿹�ݰ��� Ŭ���� (�ּ����� ���ڸ� ���� �ϴ� ���� ����ݽ� ����) */
--------------------------------------------------------------------------------------------
                            NormalAccount : public Account
---------------------------------------------------------------------------------------------
  private :
     interRate -  int  // ������ % ����
  public :
     NormalAccount( ) - constructor 
         // Normal Account Class�� ��ü ������������ 
        //  �����ڷ� ������(interRate) ������ ��� �ϰ� �ִ�.    
     
  /* �Ա��� ��� �ϴ� �Լ� Account Ŭ������ ���ǵ� Deposit() -�����Լ���
    Normal Account ������ �ܾ��� ���� ��Ų��. */
    virtual void Deposit()     
     //  Account::Deposit(money); //�����߰�
     //  Account::Deposit(money*(interRate/100.0));  // �����߰�
---------------------------------------------------------------------------------------------

/* HighCreditAccount : �ſ�ŷ� ���� (�ſ� ��޿� ���� �������� �ٸ� ����)
------------------------------------------------------------------------------------------------
                           HighCreditAccount : public NormalAccount
-----------------------------------------------------------------------------------------------
private:
    specialRate - int // ������ % ����
public: 
     HighCreditAccount() - constructor
       // HighCreditAccount Class�� ��ü ������������ 
       // �����ڷ� ������(specialRate) ������ ���� �޾Ƽ� ��� �ϰ� �ִ�.
       // AccountHandler::MakeCreditAcoount() �Լ����� �ſ��޿� ���� Credit_Level�� �����ؼ� 
          HighCreditAccount�� �����ڸ� ȣ��(����) �ؼ� ��ü�� ����

    virtual void Deposit(int money)
        // NormalAccount::Deposit(money); //���� �� ���� �߰�
             - NormalAccount�� Deposit() �� ������ �����ִ� ������ ���ڸ� �����ִ� ������ ���� �ϰ� �ִ�. 
       //  Account::Deposit(money*(specialRate/100.0));  // Ư�� �����߰�

-----------------------------------------------------------------------------------------------------


/* AccountHandler ����....*/
AccountHandler::MakeAccount()
 - ���� ���� ��ü�� �������� �ʰ�   ���� ���� ���¸� ������ �ſ�ŷڰ��¸� ���������� �����ؼ� ������ �Լ� ȣ���� �Ѵ�. 
 - accArr[accNum] =new MakeAccoun( .....)  �� �ʿ� ���� �����Ƿ�, MakeNormalAccount �� MakeCreditAccount�� ���� ���Ѽ�
   �迭�� �ʱ�ȭ 

AccountHandler::MakeNormalAccount()
  -  id, name, balance(�ݾ�), interRate(������) ������ �ʱ�ȭ ���Ѽ� NormalAccount ��ü�� �����Ҵ��Ͽ� accArr �迭�� ���� 

AccountHandler::MakeCreditAccount()
  -  id, name, balance(�ݾ�), interRate(������), creditLevel(�ſ���)  ������ �ʱ�ȭ ��Ų ��
  - creditLevel �� ���� HighCreditAccount ��ü�� �����Ҷ�, �����ؾ� �ϴ� specialRate�� LEVEL_A, LEVEL_B, LEVEL_C ���� ����(switch ����)
  - HighCreditAccount ��ü�� �����ڿ� id, balance(�ݾ�), name, interRate(������) 

    