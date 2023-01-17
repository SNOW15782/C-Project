//GROUP ...
//PROJECT : COFFEE SHOP / PARLOR 
//i was here
//COFFEE SECTION: 
//Caffe Mocha 
//Vanilla Latte
//BUttercream Latte 
//Caramel Frappe

//TEA SECTION:
//Green Tea Mache Latte 
//Thai Milk Tea 
//Oolong Tea 
//Hojicha Black Tea 

//Limited Time:
//Mango Smoothie Lycee
//Orange Lime Smoothie

//Other 
// Mineral Water
// Sparkling Water 


#include <iostream>
using namespace std; 
//class strawberry
class Strawberry 
{
private:
	string selection;
	double price;
	
public:
	void dispStrawberrySelection()
	{
		cout << "[1] Strawberry & Nutella Crepe\t Price: RM 10.00"<<endl;
		cout << "[2] Strawberry & Chocolate Crepe\t Price: RM 12.00"<<endl;
		cout << "[3] Strawberry Waffle with Custard\t Price: RM 13.00"<<endl;
		cout << "[4] Strawberry Smoothie\t Price: RM 10.00"<<endl;
		cout << "[5] Strawberry & Country Cream\t Price: RM 13.00"<<endl;
		}	
	
	void purchase(int choice)
	{
		if (choice == 1)
		{
			selection = "Stawberry & Nutella Crepe";
			price = 10.00;
		}
		else if (choice == 2)
		{
			selection = "Stawberry & Chocolate Crepe";
			price = 12.00;
		}
		else if (choice == 3)
		{
			selection = "Stawberry Waffle with Custard";
			price = 13.00;
		}
		else if (choice == 4)
		{
			selection = "Stawberry Smoothie";
			price = 10.00;
		}
		else if (choice == 5)
		{
			selection = "Stawberry & Country Cream";
			price = 13.00;
		}
		else 
		{
		selection = "Not Available";
		price = 0.00;	
		}			
	}

	double getPrice()
	{
		return price;
	}
	
	string getSelection()
	{
		return selection;
	}
};

//class Customer 
class Customer

{
private : 
	string strawSelect;
	string name;
	double payment;
	Strawberry st;
	
public:
	void set_data ()
	{
	cout << "++++++++++++++++++++++++++++++++++"<<endl;
	cout << "    XD Tutti Frutti: Strawberry"<<endl; 
	cout << "++++++++++++++++++++++++++++++++++"<<endl;
	
	cout << "Enter name\t: ";
	cin >> name; 
	
	st.dispStrawberrySelection();
	getOrder();
	}
	
	void getOrder()
	{
	int choice; 
	cout << "\nEnter your choice based on the number"<<endl;
	cin >> choice;
	st.purchase (choice);
	strawSelect = st.getSelection();
	payment = st.getPrice(); 
	}
	
	void dispDetails()
	{
	cout << "...................................."<<endl;
	cout << name << ", Your purchase details"<<endl;
	cout << "...................................."<<endl;
	cout << "Selection:\t" << strawSelect << endl;
	cout << "Payment to be made:\tRM" <<payment<<endl;
	}
	
};

int main ()
{
	Customer c;
	c.set_data();
	c.dispDetails();
	
	return 0;  
}
