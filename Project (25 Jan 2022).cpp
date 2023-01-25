#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//define class for food
class CAFE
{
	private:
		float price;
		float totPrice;
		float sumPrice;
		
		//size of array
		int size, copySize;
		
		//dynamic array
		int* arr = new int[size];
		
		//copy of array
		int* copyArr = new int[copySize];
		int emtyIndex = 0;

	public: 	
		void displayMenu();
		void setOrder();
	    void setPrice();
	    void setResit();
	    void setDisc();
};

//CONSTRUCTOR OUTSIDE CLASS
//DISPLAY THE MENU 
void CAFE::displayMenu()
{
	cout << "\n================================="<<endl;
	cout << "	  === Menu ==="<<endl;
	cout << "================================="<<endl;
	
	cout <<"FOODS"<<endl<<endl;	
	cout <<"[1]\t Pizza RM 18.00"<<endl;
	cout <<"[2]\t Burger RM 15.00"<<endl;
	cout <<"[3]\t Pasta RM 12.00"<<endl;
	cout <<"[4]\t Choch Cake RM 8.00"<<endl;
	
	//COFFEE SECTION 
	cout << "\nBevarage"<<endl<<endl;
	cout <<"[5]\t Ice Mocha RM 10.00"<<endl;
	cout <<"[6]\t Vanilla Latte RM 10.00"<<endl;
	cout <<"[7]\t Green Macha Tea RM 12.00"<<endl;
	cout <<"[8]\t Sparkling Water RM 5.00"<<endl;
	
	cout << "\n================================="<<endl;

}

//CONSTRUCTOR OUTSIDE CLASS
//USER KEY-IN TO ORDER/FINISH ORDER 
void CAFE::setOrder()
{
	char code;
	
	do
	{
	
	cout<<"\n|ADD[A]|   |DONE[D]|"<<endl;
	cout<<"What would you like to do:";
	cin>>code;	

		if(code!='A' && code!='D')
			cout<<"RETRY"<<endl;
		
	}while(code!='A' && code!='D');
	

		
	if(code=='A')
	{	
		cout<<"How many order : ";
		cin>>size;
		
		//copy of size 
		copySize += size;
		
		cout<<"Enter order number : "<<endl;
		
		for (int i = 0; i < size; i++) 
		{
    		cout<<"Order "<<i+1<<": ";
			cin>>arr[i];
		}
		
		
		for (int i = 0; i < copySize; i++) 
		{
			//value of arr being copy to copyArr 
        	copyArr[emtyIndex] = arr[i];
        	emtyIndex++;
   		}
		setPrice();	
	}
 	else
 	{
		setResit();
	}
}

//CONSTRCUTOR OUTSIDE CLASS 
//PRICING
void CAFE::setPrice()
{
	//float sumPrice;
	
	sumPrice=0;
	for (int i=0; i<size; i++)
	{
		//int orderNum;
		float price;
		
		//orderNum = arr[i];
		
	    switch (arr[i]) 
		{
	        case 1: price = 18.00; break;
			case 2: price = 15.00; break;
			case 3: price = 12.00; break;
			case 4: price = 8.00; break; 	
			
			case 5: price = 10.00; break;
			case 6: price = 10.00; break;
			case 7: price = 12.00; break;
			case 8: price = 5.00; break;
	    }
		sumPrice += price;
	}
	
	totPrice += sumPrice;
	
	cout<<"Price : RM"<<fixed<<setprecision(2)<<totPrice;
	
	setOrder();
	
}

//CONSTRUCTOR OUTSIDE CLASS
//RECEIPT 
void CAFE::setResit()
{
	for (int i=0; i<copySize; i++)
	{
		cout<<"\n";
		switch(copyArr[i])
		{
			case 1: cout<<"Pizza \t18.00"; break;
			case 2: cout<<"Burger \t15.00"; break;
			case 3: cout<<"Pasta \t12.00"; break;
			case 4: cout<<"Choc Cake \t8.00"; break; 	
			
			case 5: cout<<"Ice Mocha 10.00"; break;
			case 6: cout<<"Vanilla Latte 10.00"; break;
			case 7: cout<<"Green Macha Tea 12.00"; break;
			case 8: cout<<"Sparkling Water 5.00"; break;	
		}
	}
	cout<<"\nYour Total Price : RM"<<fixed<<setprecision(2)<<totPrice;	
}

//CONSTRUCTOR OUTSIDE CLASS
//DISCOUNT SECTION IF USER HAVE DISCOUNT CODE 
void CAFE::setDisc()
{
	string discount;
	float disPrice;
	char ans;
	
	if (totPrice!=0)
	{
		do
		{
		
		cout<<"\n\nDo you have a discount code : ";
		cin>>discount;
		
		
		
			if (discount == "A12B")
			{
				cout<<"\nu get discount";
				disPrice = totPrice * 0.1;
				totPrice -= disPrice;
			}
			else if (discount == "Huat23")
			{
				cout<<"\nu get discount";
				disPrice = totPrice * 0.2;
				totPrice -= disPrice;
			}
			else
			{
				cout<<"\ninvalid";
				
				//cout<<"\nYour Total Price : RM"<<fixed<<setprecision(2)<<totPrice;
				cout<<"\n\nwanna try again Y/N: ";
				cin>>ans;
			}
		}while(ans=='Y');
		
		cout<<"\nYour Total Price After Discount : RM"<<fixed<<setprecision(2)<<totPrice;		
	}		
}

//MAIN 
int main()
{
	//CAFE OBJECT 
	CAFE CF;
	
	//HEADER OF THE RESTAURANT NAME 
	cout<<"\n Welcome To 4Baris \n";
	
	//CALL BACK USING OBJECT
	CF.displayMenu();
	CF.setOrder();
	
	CF.setDisc(); //IF-ELSE STATEMENT
	
	
	return 0;
}
