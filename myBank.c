#include <stdio.h>




double bankAcouns [50][2] = {{0}};

int isOpenAndExist (int indexAccount){ 
    if (indexAccount > 49 || indexAccount<0){
        printf("Invalid account number\n");
        return 0;
    }
    if (bankAcouns[indexAccount][0] == 0){
        printf("This account is closed\n");
        return 0;
    }  
    return 1;  
}
   
    
    
void OpenAccount(double money){
    //finding a place in the array:
	int findPlace=0;    //false
    int numAccount;
	for (int i=0; (i<50)&&(!findPlace); ++i){   //  looking for a place
		if (bankAcouns[i][0] == 0){  //fing a place!
		    numAccount = i+901;
		    findPlace=1;				
		}
	}
	if (!findPlace){
		printf("Can't create a new bank account. There is no enough space\n");
        return;
	}
    int indexAccount = numAccount-901;
    bankAcouns[indexAccount][0] = 1;       //set this acounas as open
    bankAcouns[indexAccount][1] = money;   //set the balance of money 
    printf("New account number is: %d.\n" , numAccount);
}

void getBalance(int indexAccount){
    printf("The balance of account number: %d is: %.2lf\n",indexAccount+901, bankAcouns[indexAccount][1]);
}

void Deposit(int indexAccount, double add){
    bankAcouns[indexAccount][1]= bankAcouns[indexAccount][1] + add;
    printf("The new balance is: %.2lf\n", bankAcouns[indexAccount][1]);
}

void Withdraw(int indexAccount, double withdraw){
    if(bankAcouns[indexAccount][1]-withdraw < 0){
        printf("Cannot withdraw more than the balance\n");
        return;
    }
    bankAcouns[indexAccount][1]= bankAcouns[indexAccount][1] - withdraw;
    printf("The new balance is: %.2lf\n", bankAcouns[indexAccount][1]);
    
}

void CloseAccount(int indexAccount){
    if (indexAccount > 49 || indexAccount<0){
        printf("Invalid account number\n");
        return;
    }
   
    if(bankAcouns[indexAccount][0] == 0){
        printf("This account is already closed\n");
    }
    else{
        bankAcouns[indexAccount][0] = 0;
    printf("Closed account number %d\n", indexAccount+901);
    }
}

void addInterest(double interest_byPrecent){
	double interest = interest_byPrecent/100;
    for ( int i=0; i<50; ++i){
        if (bankAcouns[i][0]==1){
            bankAcouns[i][1] *= (1+interest);
            //printf("Successfully update the balance in account: %d, to: %.2lf\n", i+901, bankAcouns[i][1]);
        }
    }
}

void PrintAccounts(){
    for ( int i=0; i<50; ++i){
        if (bankAcouns[i][0]==1){
            printf("The balance of account number %d is: %.2lf \n", i+901, bankAcouns[i][1]);
        }
    }    
}

void EndProgram (){
    for ( int i=0; i<50; ++i){
        if (bankAcouns[i][0] == 1){
            bankAcouns[i][0] = 0;
        }
    }
}

