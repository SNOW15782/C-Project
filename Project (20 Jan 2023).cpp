#include <iostream>
#include <iomanip>
using namespace std; 
//CLASS MENU 
class Menu
{
	private:
		string selection;
		int number;
		float price; 
	
	public:
		void setMenu ();
		void setChoice();
		void setHowMany ();
		
		//FRIEND FUNCTION 
		friend void display_receipt (Menu); 
		
		//CONSTRUCTOR DEFAULT 
		Menu ();
};

//FUNCTION OUTSIDE OF THE CLASS 
//DISPLAY THE FULL MENU
void Menu::setMenu()
{
cout << "\n====================================="<<endl;
cout << "=== Menu ==="<<endl;
cout << "====================================="<<endl;

//COFFEE SECTION 
cout << "COFFEE"<<endl<<endl;
cout <<"[1]=== Chocolate Mocha RM 10.00"<<endl;
cout <<"[2]=== Vanilla Latte RM 10.00"<<endl;
cout <<"[3]=== Buttercream Latte RM 12.00"<<endl;
cout <<"[4]=== Caramel Frappe RM 10.00"<<endl;

//TEA SECTION
cout << "TEA"<<endl<<endl;
cout <<"[5]=== Green Tea Macha Latte RM 12.00"<<endl;
cout <<"[6]=== Thai Milk Tea RM 10.00"<<endl;
cout <<"[7]=== Oolong Tea RM 10.00"<<endl;
cout <<"[8]=== Hojicha Black Tea RM 9.00"<<endl;

//OTHER SECTION
cout <<"OTHER"<<endl<<endl;
cout <<"[9]=== Mineral Water RM 2.00"<<endl;
cout <<"[10]=== Sparkling Water RM 5.00"<<endl;

//PROMO SECTION (FOR FUTURE UPDATE) [UP TO YOU - ARIF]
}


//FUNCTION OUTSIDE CLASS 
//DISPLAY USER TO KEY-IN 
void Menu::setChoice()
{
	int choice;
	cout <<"\nWhat Would You Like to Order? [ENTER CODE] : "; 
	//USER ENTER 1-10 (MIGHT CHANGE TO CHAR BUT WE'LL SEE 1ST - ARIF]
	cin >> choice;
	
	//SWITCH STATEMENT (MAKE SURE IT TALLY ON THE DISPLAY MENU - ARIF) 
	switch (choice)
	{
	
	case 1: selection = "Chocolate Mocha";price = 10.00; break;
	case 2: selection = "Vanilla Latte"; price = 10.00; break;
	case 3: selection = "Buttercream Latte"; price = 12.00; break;
	case 4: selection = "Caramel Frappe"; price = 10.00; break; 	
	
	case 5: selection = "Green Tea Macha Latte";price = 12.00; break;
	case 6: selection = "Thai Milk Tea"; price = 10.00; break;
	case 7: selection = "Oolong Tea RM 10.00"; price = 10.00; break;
	case 8: selection = "Hojicha Black Tea"; price = 9.00; break;
	
	case 9: selection = "Mineral Water";price = 12.00; break;
	case 10: selection = "Sparkling Water"; price = 5.00; break;

	//SELECTION IS FROM PRIVATE 
	//PRICE IS FROM PRIVATE
	}
}
	void Menu::setHowMany()
	{
		cout << "\nHow many: ";
		cin >> number; 
		// NUMBER IS FROM PRIVATE 
	}
	
	Menu::Menu () //NO VOID FOR CONSTRCUTOR 
	{
		cout << "==THE FOUR BARISTAS=="; //[COSTMETIC WILL CHANGE, THIS WILL DO FOR NOW - ARIF]
	}

	void display_receipt (Menu M) //FRIEND FUNCTION ACCEPTING OBJECT 
	{
		float total = 0; //BECAUSE 0.00
		cout << "\n==========================================="<<endl;
		cout << "===PAYMENT==="<<endl;
		
		cout << "Order\t\t: "<< M.selection<<endl; //OBJECT FROM PRIVATE 
		cout << "Quantity\t\t: "<<M.number << endl; //OBJECT FROM PRIVATE 
		cout << "Price\t: RM "<<M.price << endl; //OBJECT FROM PRIVATE 
		
		/*//CALCULATION FOR TOTAL PRICE 
		float cost = M.price * M.number;
		total = total + cost;
		cout << "Total Price\t: RM "<<fixed<<setprecision(2) <<total <<endl; //OBJECT FROM PRIVATE*/
		//NOT SURE WHY CANNOT RUN 
		
	}
	
	
	int main ()
	{
		Menu M;
		char repeat = 'y';
		do
		{
		
		M.setMenu();
		M.setChoice();
		M.setHowMany();
		display_receipt (M); 
		
		cout << "\nDo you want to order again? (Y/N): ";
		cin >> repeat; 
		} while (repeat == 'y' || repeat == 'Y');
		cout << "Thank you for your order!"<<endl;
		
		return 0;
	}

	//CURRENTLY MISSING 
	// DISCOUNT CODE 
	//LARGE OPTION (+2 ringgit extra)
	// NEED TO CALCULATE TOTAL OVERALL (MIGHT NEED ANOTHER FUNCTION)
	//REMARK (User can write down additional info like less sugar, less ice etc..) 
