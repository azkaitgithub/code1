#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct drinkmachine
{
	string name = "";
	double cost = 0.0;
	int num_of_drinks = 0;
};
void show_menu()
{
	cout << "\n   ----------------------------\t" << endl;
	cout << "\tchoose your drink";
	cout << "\n   ----------------------------\t" << endl;
	cout << "\t1. cola\n";
	cout << "\t2. root beer\n";
	cout << "\t3. lemon lime\n";
	cout << "\t4. grape soda\n";
	cout << "\t5. cream soda\n";
	cout << "\t6. exit program\n";
	cout << "   ----------------------------\t" << endl;
	cout << "\tenter [ 1 - 6 ]" << endl;
}
int validate_input(int& choice, const int& mini, const int& max)
{
	while (choice > max || choice < mini)
	{
		cout << "error: invalid choice\n";
		cout<<left<<setw(20) << "choose again: ";
		cin >> choice;
		cout << endl;
	}
	return choice;
}
double check_amount(double& amount, const double& mini, const double& max)
{
	cout << setprecision(2) << fixed << showpoint;
	while (amount > max || amount < mini)
	{
		if (amount > max)
		{
		    cout << "\n-------------------------------------------\t" << endl;
			cout << "you cannot enter amount greater than $1.00" << endl;
			cout << "--------------------------------------------\t" << endl;
			cout << "enter amount again: ";
			cin >> amount;
			cout << endl;
		}
		else if (amount < mini)
		{
			cout << "\n------------------------------------------------\t" << endl;
			cout << "ops! amount entered is less than the products cost" << endl;
			cout << "the price of this drink is $" << mini << endl;
			cout << "--------------------------------------------------\t" << endl;
			cout << "enter amount again: ";
			cin >> amount;
			cout << endl;
		}
	}
	return amount;
}
bool check_soft_drinks(int& num_of_drinks)
{
	if(num_of_drinks == 0)
	{
		char ch;
		cout << "oops! sold out" << endl;
		cout << "you may choose another drink\n";
		//cout << "thanks for using our services\n";
		cout << "press any key to make selection again" << endl;
		cin.ignore();
		cin.get(ch);
		return true;
	}
	return false;
}
int main()
{
	drinkmachine drinks[5];
	drinks[0] = { "cola",0.75,1 };
	drinks[1] = { "root beer",0.75,20};
	drinks[2] = { "lemon lime",0.75,20 };
	drinks[3] = { "grape soda",0.80,20 };
	drinks[4] = { "cream soda",0.80,20 };

	//declaration of variables
	int choice;
	double amount, total_amount = 0,remaining_amount=0;
	do
	{
		
		show_menu();
		cin >> choice;
		choice = validate_input(choice, 1, 6);
		if (choice != 6)
		{
			int flag = 0;
			flag = check_soft_drinks((drinks[choice - 1]).num_of_drinks);
			if (flag)
			{
				continue;
			}
			cout << "enter the amount to be inserted: ";
			cin >> amount;
			amount = check_amount(amount, (drinks[choice-1]).cost, 1);
			remaining_amount = amount - (drinks[choice - 1]).cost;
			cout<<left<<setw(15) << "your remaining amount is: " <<"$"<< remaining_amount << endl;
			(drinks[choice - 1]).num_of_drinks -= 1;
			total_amount += (drinks[choice - 1]).cost;
		}
		else
		{
			cout<<setprecision(2)<<fixed<<showpoint << endl;
			cout << "total amount earned by machine is $" << total_amount<<endl;
			cout << "thanks for using our services" << endl;
		}
	}while (choice != 6);
}