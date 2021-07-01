#include <iostream>
#include <math.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

const double COSTCAPPUCHINO = 3.2;
const double COSTESPRESSO = 2.7;
const double COSTLATTE = 3.0;
const int MAXNUMBERGLASSES = 700;

double cash = 0.0;
string PIN ="1122";
int numbersAttempt = 3;

void blankLines();
void showMenu();
void showServiceMenu();
void showBalanceUser(double balance);
double showRemainingBalanceUser(double cashUser, double costCofee);
double getMoney();
void showNotEnoughMoney();
void showProceeds(double proceeds);
bool checkCost(double byn, double costCofee);
bool checkPIN();
void doCoffee();
bool exitServiceMenu();
void showInputZeroToExit();
bool ckeckNominalMoney(double nominal);
void showNumberOfGlasses();
bool ckeckNumberGlasses(int cups);
void showNotEnoughGlasses();
int uploadGlasses(int MAX, int glasses);

int main()
{
	int choice = 0;
	int choice2 = 0;
	int choice3 = 0;
	double nominal = 0;
	int choiceService = 0;
	double byn = 0.00;
	double proceeds = 0.00;
	int numberOfGlasses = 2;
	
	while (true){
		system("cls");
		cout << endl << "   COFEEBOX DOES NOT GIVE CHANGE!" << endl;
		if (ckeckNumberGlasses(numberOfGlasses) == false)
			showNotEnoughGlasses();
		showBalanceUser(byn);
		cout << endl << endl << endl;
		showMenu();
		blankLines();
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 0)
			break;
			
			
// ------------- 1.ПОЛЬЗОВАТЕЛЬ ВВОДИТ CASH  --------------------------------------------------------------------
		else if (choice == 1) {
			system("cls");
			cout << endl;
			byn += getMoney();
			proceeds += cash;
		}	
// ------------- 2.КАПУЧЧИНО  ------------------------------------------------------------------------------
		else if (choice == 2) {    
			system("cls");
			if (ckeckNumberGlasses(numberOfGlasses) == false) {
				showNotEnoughGlasses();
				Sleep (1500);
			}
			else {
				if (checkCost(byn,COSTCAPPUCHINO) == true) {
					doCoffee();
					system("cls");
					byn = showRemainingBalanceUser(byn, COSTCAPPUCHINO);
					numberOfGlasses--;
				}				
				else 
				showNotEnoughMoney();
			}
		}
// ------------- 3.ЭСПРЕССО  ------------------------------------------------------------------------------
		else if (choice == 3) {    
			system("cls");
			if (ckeckNumberGlasses(numberOfGlasses) == false) {
				showNotEnoughGlasses();
				Sleep (1500);
			}
			else {
				if (checkCost(byn,COSTESPRESSO) == true) {
					doCoffee();
					system("cls");
					byn = byn = showRemainingBalanceUser(byn, COSTESPRESSO);
					numberOfGlasses--;
				}				
				else 
				showNotEnoughMoney();
			}
		}
// ------------- 4.ЛАТТЕ  ------------------------------------------------------------------------------
		else if (choice == 4) {    
			system("cls");
			if (ckeckNumberGlasses(numberOfGlasses) == false) {
				showNotEnoughGlasses();
				Sleep (1500);
			}
			else {
				if (checkCost(byn,COSTLATTE) == true) {
					doCoffee();
					system("cls");
					byn = byn = showRemainingBalanceUser(byn, COSTLATTE);
					numberOfGlasses--;
				}				
				else 
				showNotEnoughMoney();
			}
		}
// ------------- 5.Service menu  ------------------------------------------------------------------------
		else if (choice == 5) {    
			system("cls");
			if (checkPIN() == true){
				system("cls");
				while (true) {
					system("cls");
					cout << endl;
					showServiceMenu();
					blankLines();
					cout << " Your choice: ";
					cin >> choice2;
					if (choice2 == 0)
						break;	
					else if (choice2 == 1){
						system("cls");
						while (true){
							system("cls");
							cout << " Balance is " << proceeds << ", BYN";
							if (exitServiceMenu() == true)
								break;
							else {
								showInputZeroToExit();								
							}

						}
					}
					else if (choice2 == 2){
						system("cls");
						while (true){
							system("cls");
							cout << " Number of glassses in cofeebox is " << numberOfGlasses;
							if (exitServiceMenu() == true)
								break;
							else {
								showInputZeroToExit();								
							}
						}
					}
					else if (choice2 == 3){
						system("cls");
						cout << " You can upload the maximum number of glasses only " << MAXNUMBERGLASSES - numberOfGlasses << " glasses" << endl; 
						numberOfGlasses += uploadGlasses(MAXNUMBERGLASSES, numberOfGlasses);
					}
					else if (choice2 == 4){
						system("cls");
						while (true){
							cout << " You take proceeds " << proceeds << ", BYN";
							Sleep(1500);
							proceeds = 0.0;
							byn = 0.0;
							break;
						}
					}													
				}
			}
			else {
				system("cls");
				cout << " Error! COFFEBOX IS LOCKED";
				cout << endl << " Wait for service";
				return 1;
			}
				

			}

		}
	return 0;
}

//-----------------------------Functions------------------------------------


//---------------------------- Main menu -----------------------------------
void showMenu()
{
	cout << " 1 - Input cash " << endl;
	cout << " 2 - Cappuccino [3.2 BYN]  " << endl;
	cout << " 3 - Espresso   [2.7 BYN]" << endl;
	cout << " 4 - Latte      [3.0 BYN]" << endl;
	cout << endl <<" 5 - service" << endl;
	cout << " 0 - Exit" << endl;
}

//---------------------------- Service menu -----------------------------------
void showServiceMenu()
{
	cout << " 1 - View balance" << endl;
	cout << " 2 - Check the number of glasses" << endl;
	cout << " 3 - Add glasses" << endl;		
	cout << " 4 - Pick up the proceeds" << endl;	
	cout << endl << " 0 - Back to the main menu" << endl;
}

double getMoney()
{
	
	cout << " Insert money [0.1 BYN, 0.2 BYN, 0.5 BYN, 1 BYN, 2 BYN]:    ";
	cin >> cash;
	
	if (cash == 0.10 or cash == 0.20 or cash == 0.50 or cash == 1.00 or cash == 2.00)
		return cash;
	else {
		system("cls");
		cout << " The nominal of money is wrong";
		Sleep (1500);
		return cash = 0.0;			
	}			
}

int uploadGlasses(int MAX, int currentGlasses)
{
	int uploadglasses = 0;
	
	cout << " Upload glasses:";
	cin >> uploadglasses;
	
	if ((uploadglasses + currentGlasses) <= 700 and uploadglasses >= 1)
		return uploadglasses;
	else {
		system("cls");
		cout << " The wrong number of glasses";
		Sleep (1500);
		return uploadglasses = 0;			
	}			
}
//---------------------------- Проверка достаточности денег для заказа кофе ---
bool checkCost(double byn, double costCofee)
{
	if (byn >= costCofee) 
		return true;
	else 
		return false;
}
//---------------------------- Service menu -----------------------------------

void showNotEnoughMoney()
{
	cout << " Not enough money!" << endl;
	Sleep (2000);
}
//---------------------------- Показывает баланс юзера -------------------------
void showBalanceUser(double balance)
{
	cout << "         Balance " << balance << " BYN";
}
//---------------------------- Показывает выручку ------------------------------
void showProceeds(double proceeds)
{
	cout << " Your proceeds is " << proceeds << ", BYN";
}
//---------------------------- Показывает баланс после заказа кофе -------------
double showRemainingBalanceUser(double cashUser, double costCofee)
{
	double remaining = 0.0;
	remaining = cashUser - costCofee;
	return remaining;
}
//---------------------------- Пустые строки -----------------------------------
void blankLines()
{
	cout << endl << endl << endl; 	
}
//---------------------------- Проверка вводимого ПИН --------------------------
bool checkPIN()
{
	char symbalUser;
	string userPIN;
	do {
		system("cls");
		cout << endl << " Enter password: ";
		userPIN = "";
		do {
			symbalUser = getch();
			cout << symbalUser;
			Sleep(100);
			cout << "\b";
			cout << "*";
			if (symbalUser != char(13))
				userPIN = userPIN + symbalUser;
		} while (symbalUser != char(13));
		
		if (userPIN == PIN){
		return true;
		break;
	}
	numbersAttempt--;
	if (numbersAttempt < 1) {
		return false;
		break;
	}
	system("cls");
	cout << endl << " Wrong PIN! Attempt " << numbersAttempt << " left.Try again";
	Sleep(1500);
	} while (userPIN != PIN);
}
//---------------------------- Показ приготовления кофе --------------------------
void doCoffee() 
{
	cout << " Loading";
	
	for (int i = 0; i <= 5; i++, Sleep(200))
	{
		cout << ".";
	}
	cout << " Your coffee is done!" << endl;
	
	Sleep(1500);
}
//---------------------------- Выход в сервисное меню -----------------------------
bool exitServiceMenu()
{	
	int numerChoise = 0;
	
	cout << endl << " 0 - Back to the service menu";
	cout << endl << endl;
	cout << " Your choice: ";
	cin >> numerChoise;
	
	if (numerChoise == 0)
		return true;
	else 
		return false;
}
//---------------------------- Выход в сервисное меню -----------------------------
void showInputZeroToExit()
{	
	system("cls");
	cout << endl << " Input '0' back to the service menu";
	Sleep (2000);
}

bool ckeckNumberGlasses(int cups)
{
	if (cups >= 1) 
		return true;
	else 
		return false;
}
//---------------------------- Показывает что нет стаканов --------------------------
void showNotEnoughGlasses()
{	
	cout << endl << " *** We apologize. There are no glasses in the coffee machine. Wait for service ***" << endl << endl;
}


