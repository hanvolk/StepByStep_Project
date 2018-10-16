StepByStep Project ver 5.0

기능 제공을 담당하는 컨트롤 클래스 AccountHandler 를 정의 
class AccountHandler
{
private:
    Account* accArr[100];  // Accout 저장을 위한 배열, Account.h 에 전역으로 정의 되어 있던 배열인데 , AccountHandelr 클래스의 Private 영역으로 이동 
    int accNum;              // 총 계좌의 숫자, Account.h 에 전역으로 정의 되어 있던 배열인데 , AccountHandelr 클래스의 Private 영역으로 이동 
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
  계좌 정보의 데이터, 계좌의 수의 정보를 담고 있는 accArr 배열 이나, accNum 변수를 전역으로 두면 어디서나 접근 가능한 형태가 되므로 프로그램의 안정성에 좋지 않다. 
  AccountHandler 라는 컨트롤 클래스를 정의해 놓고, 그 컨트롤 핸들러에 의해서만 접근 가능하게 제한 함으로서 정보은닉이 실현 
*/

함수의 위치 이동
DefineFunc.cpp 에 있던 함수들 중 
   계좌의 기능을 담당했던 
      void ShowMenu()  	//메뉴의 출력
      void MakeAccout()	// 계좌의 생성
      void DepositMoney()	// 입금 기능 실행
      void WithdrawMoney()	// 출금 기능 실행
      void ShowAllAccInfo()	// 모든 계좌 정보 출력 
  이러한 함수들을 AccountHandler 클래스의 맴버 함수로 정의 


DefineFunc.cpp 에 있던 함수들 중 
   실제 Account 의 정보에 직접 접근 하던 함수들은 
     Account(int ID, int money, char* name)	// 생성자
     void Deposit(int money)			// 입금
     void Withdraw(int money)		// 출금
     void ShowAccInfo() const		// 계좌정보 출력
     ~Account()   				// 소멸자
 이러한 함수들은 Account.cpp 라는 파일을 따로 만들어서 함수 정의 

즉 
  Entity 클래스 Account.h 와 그에 대한 함수의 정의 Account.cpp
  Control 클래스 AccountHandler.h 와 그에 대한 함수의 정의 AccountHandler.cpp 
는 새로 생성 되었고
  Declaration.h  과 DefineFunc.cpp 파일은 삭제 했다.

이제
 Main 함수에서 AccountHandler 객체 manager를 만들어서
  manager.ShowMenu()
  manager.MakeAccount() 
이렇게 기능을 수행 하게 된다.


   