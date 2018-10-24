StepByStep Project ver 6.0

-------------------------------------------------------------------------
                                           Account
-------------------------------------------------------------------------
  private:
    accID - int   // 계좌 ID
    balance - int   //  잔액 
    cusName - char*   // 고객 이름

 public:
    Account(int ID, int Money, char* money); - constructor
    Account(const Account& ref);	- cpy constructor
    GetAccID() const  -  int
    virtual Deposit() - void
    Widthdraw() - int
    ShowAccInfo() - void
    ~ Account()
-----------------------------------------------------------------------------



/* NormalAccount : 보통예금계좌 클래스 (최소한의 이자를 지급 하는 자율 입출금식 계좌) */
--------------------------------------------------------------------------------------------
                            NormalAccount : public Account
---------------------------------------------------------------------------------------------
  private :
     interRate -  int  // 이자율 % 단위
  public :
     NormalAccount( ) - constructor 
         // Normal Account Class의 객체 생성과정에서 
        //  생성자로 이자율(interRate) 정보를 등록 하고 있다.    
     
  /* 입금을 담당 하는 함수 Account 클래스의 정의된 Deposit() -가상함수로
    Normal Account 계좌의 잔액을 증가 시킨다. */
    virtual void Deposit()     
     //  Account::Deposit(money); //원금추가
     //  Account::Deposit(money*(interRate/100.0));  // 이자추가
---------------------------------------------------------------------------------------------

/* HighCreditAccount : 신용신뢰 계좌 (신용 등급에 따라서 이자율이 다른 계좌)
------------------------------------------------------------------------------------------------
                           HighCreditAccount : public NormalAccount
-----------------------------------------------------------------------------------------------
private:
    specialRate - int // 이자율 % 단위
public: 
     HighCreditAccount() - constructor
       // HighCreditAccount Class의 객체 생성과정에서 
       // 생성자로 이자율(specialRate) 정보를 전달 받아서 등록 하고 있다.
       // AccountHandler::MakeCreditAcoount() 함수에서 신용등급에 따라서 Credit_Level을 설정해서 
          HighCreditAccount의 생성자를 호출(전달) 해서 객체를 생성

    virtual void Deposit(int money)
        // NormalAccount::Deposit(money); //원금 과 이자 추가
             - NormalAccount의 Deposit() 는 원금을 더해주는 과정과 이자를 더해주는 과정을 진행 하고 있다. 
       //  Account::Deposit(money*(specialRate/100.0));  // 특별 이자추가

-----------------------------------------------------------------------------------------------------


/* AccountHandler 에서....*/
AccountHandler::MakeAccount()
 - 이제 실제 객체를 만들지는 않고   보통 예금 계좌를 만들지 신용신뢰계좌를 만들지만을 결정해서 절절한 함수 호출을 한다. 
 - accArr[accNum] =new MakeAccoun( .....)  는 필요 없어 졌으므로, MakeNormalAccount 와 MakeCreditAccount로 이전 시켜서
   배열을 초기화 

AccountHandler::MakeNormalAccount()
  -  id, name, balance(금액), interRate(이자율) 변수를 초기화 시켜서 NormalAccount 객체를 동적할당하여 accArr 배열에 저장 

AccountHandler::MakeCreditAccount()
  -  id, name, balance(금액), interRate(이자율), creditLevel(신용등급)  변수를 초기화 시킨 후
  - creditLevel 에 따라서 HighCreditAccount 객체를 생성할때, 전달해야 하는 specialRate값 LEVEL_A, LEVEL_B, LEVEL_C 값을 결정(switch 구문)
  - HighCreditAccount 객체의 생성자에 id, balance(금액), name, interRate(이자율) 

    