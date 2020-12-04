
#include <stdio.h>  
#include "myBank.h"
#include "myBank.c"

int checkInput();


int main(){ 
	
  int more=1;
	while ( more){
    char acttion;

    printf("Please choose a transaction type:\n");
    printf("O-Open Account\n");
    printf("B-Balance Inquiry\n");
    printf("D-Deposit\n");
    printf("W-Withdrawal\n");
    printf("C-Close Account\n");
    printf("I-Interest\n");
    printf("P-Print\n");
    printf("E-Exit\n");
    scanf(" %c", &acttion);

    if(acttion == 'O'){
      printf("Please enter amount for deposit: ");
      double dis =checkInput("Failed to read the amount","Invalid Amount");
      if(dis != -1){
        OpenAccount(dis);
      }
    }
   
    else if(acttion == 'B'){    
		  printf("Please enter account number: ");
		  int numAccount = checkInput("Failed to read the account number","Invalid account number");
      if(numAccount != -1){
        int indexAccount = numAccount - 901;
        if(isOpenAndExist(indexAccount)){
  		    getBalance(indexAccount);
        }
      }
    }
    
    else if(acttion == 'D'){
      printf("Please enter account number: ");
      int numAccount = checkInput("Failed to read the account number","Invalid account number");
      if(numAccount != -1){
        int indexAccount = numAccount-901;
        if(isOpenAndExist(indexAccount)){
          printf("Please enter amount for deposit: ");
          int dis = checkInput("Failed to read the amount", "Cannot deposit a negative amount");
          if(dis != -1){
            Deposit(indexAccount, dis);
          }
        }
      }
    }
    
    else if(acttion == 'W'){
      printf("Please enter account number: ");
	    int numAccount = checkInput("Failed to read the account number","Invalid account number");
      if(numAccount != -1){

      int indexAccount = numAccount-901;
      if(isOpenAndExist(indexAccount)){
          printf("Please enter the amount to withdraw: ");
          double withdraw=checkInput("Failed to read the amount", "Cannot withdraw a negative amount");
          if (withdraw != -1){
            Withdraw(indexAccount, withdraw);
          }
        }
      }
    }
    
    else if(acttion == 'C'){
      printf("Please enter account number: ");
	    int numAccount = checkInput("Failed to read the account number","Invalid account number");
      if(numAccount != -1){
        int indexAccount = numAccount-901;
        CloseAccount(indexAccount);
      }
    }
    
    else if(acttion == 'I'){
      printf("Please enter interest rate:");
	    double interest_byPrecent=checkInput("Failed to read the interest rate","Invalid interest rate");
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
      printf("Invalid transaction type\n");
    }

	  printf("\n");
  }
	
	return 0;
}


//Helper function for make sure the imput is numeric and positive
int checkInput(char* msg1, char* msg2){   
    //char c;
    double num;
    if(scanf("%lf", &num) == 0){
        printf("%s \n", msg1);
        //scanf("%c", &c);
        return -1;
    }else if(num <= 0){ 
         printf("%s \n", msg2);
        return -1;
    }
    return num;
}