
#include <stdio.h>  
#include "myBank.h"
#include "myBank.c"

int checkInput();


int main(){ 

	printf("Hello! Which acction do you like to do?\n");
	printf("For open new account please press O.\n") ; 
	printf("For getting the balance of money please press B.\n");
	printf("For deposit money please press D.\n");
	printf("For withdraw money please press W.\n");
	printf("For closing the account please press C. \n");
	printf("For adding interest to all the accounts please press I. \n");
	printf("For printing all the open accounts and their balance please press P.\n");
	printf("For closing all the accounts and finish acttions please press C. \n\n");	

  int more=1;
	while ( more){
    char acttion;
    scanf(" %c", &acttion);

    if(acttion == 'O'){
      printf("What is the first desposit? ");
      int dis =checkInput();
      OpenAccount(dis);
    }
   
    else if(acttion == 'B'){    
		  printf("Anter number account: ");
		  int numAccount = checkInput();
      int indexAccount = numAccount - 901;
  		getBalance(indexAccount);
    }
    
    else if(acttion == 'D'){
      printf("Anter number account: ");
      int numAccount = checkInput();
      int indexAccount = numAccount-901;
      if(isOpenAndExist(indexAccount)){
		    printf("Anter amount of desposits: ");
        int dis = checkInput();
	      Deposit(indexAccount, dis);
      }
    }
    
    else if(acttion == 'W'){
      printf("Anter number account: ");
	    int numAccount = checkInput();
      int indexAccount = numAccount-901;
      if(isOpenAndExist(indexAccount)){
 	      printf("Anter amount of withdraw: ");
	      double withdraw=checkInput();
	      Withdraw(indexAccount, withdraw);
      }
    }
    
    else if(acttion == 'C'){
      printf("Anter number account:");
	    int numAccount = checkInput();
      //scanf("%d",&numAccount);
      int indexAccount = numAccount-901;
      if(isOpenAndExist(indexAccount)){
	      CloseAccount(indexAccount);
      }
    }
    
    else if(acttion == 'I'){
      printf("Anter interest by precent: ");
	    double interest_byPrecent=checkInput();
	  	addInterest(interest_byPrecent);
    }
    
    else if(acttion == 'P'){
      PrintAccounts();
    }
    
    else if(acttion == 'E'){
      EndProgram();
      more = 0;
    }
    
    else{
      printf("worng acction. Please press 'O', 'B', 'D', 'W', 'C', 'I', 'P' or 'E'.\n");
    }

	  printf("Which acction do you like to do now? ");
  }
	
	return 0;
}


//Helper function for make sure the imput is numeric and positive
int checkInput(){   
  char c;
	double num;
  int valid;
  do{
    valid=1;
    if(scanf("%lf", &num)==0){
      printf("Illegat number to this acttion. Please try again.\n");
      scanf("%c", &c);
      valid=0;
    }
    else if(num<=0){ 
      printf("Can't get negative number. Pleaes enter legal number.\n");
      valid=0;
    }
  }
  while(valid==0);
  return num;
}