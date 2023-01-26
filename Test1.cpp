//GROUP : 7
//SUBJECT: OOP DIT 2125 
//NAME FHERHAD ADITYA AZ ZAHRA (1211205488)
//NAME MUHAMAD ARIF BIN SALLEHUDDIN (1211206128)
//NAME MUHAMMAD FITRI BIN YUSA'(1211206096)
//NAME DANIEL ISKANDAR BIN MIZAN (1211206299)
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//define class for food
class CAFE
{
	private:
		float price=0;
		float totPrice=0;
		float sumPrice=0;
		
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
	cout << "\n\t\t\t\t\t================================="<<endl;
	cout << "\t\t\t\t\t\t   === Menu ==="<<endl;
	cout << "\t\t\t\t\t================================="<<endl;
	
	cout <<"\n\t\t\t\t\tFOODS"<<endl<<endl;	
	cout <<"\t\t\t\t\t[1]\t Pizza RM 18.00"<<endl;
	cout <<"\t\t\t\t\t[2]\t Burger RM 15.00"<<endl;
	cout <<"\t\t\t\t\t[3]\t Pasta RM 12.00"<<endl;
	cout <<"\t\t\t\t\t[4]\t Choch Cake RM 8.00"<<endl;
	
	//COFFEE SECTION 
	cout << "\n\t\t\t\t\tBevarage"<<endl<<endl;
	cout <<"\t\t\t\t\t[5]\t Ice Mocha RM 10.00"<<endl;
	cout <<"\t\t\t\t\t[6]\t Vanilla Latte RM 10.00"<<endl;
	cout <<"\t\t\t\t\t[7]\t Green Macha Tea RM 12.00"<<endl;
	cout <<"\t\t\t\t\t[8]\t Sparkling Water RM 5.00"<<endl;
	
	cout << "\n\t\t\t\t\t================================="<<endl;

}

//CONSTRUCTOR OUTSIDE CLASS
//USER KEY-IN TO ORDER/FINISH ORDER 
void CAFE::setOrder()
{
	char code;
	
	do
	{
	
	cout<<"\n\t\t\t\t\t|ADD[A]|   |DONE[D]|"<<endl;
	cout<<"\t\t\t\t\tWhat would you like to do:";
	cin>>code;	

		if(code!='A' && code!='D')
			cout<<"\t\t\t\t\tRETRY"<<endl;
		
	}while(code!='A' && code!='D');
	

		
	if(code=='A')
	{	
		cout<<"\t\t\t\t\tHow many order : ";
		cin>>size;
		
		//copy of size 
		copySize += size;
		
		//cout<<"\t\t\t\t\tEnter order number : "<<endl;
		
		for (int i = 0; i < size; i++) 
		{
    		cout<<"\t\t\t\t\tOrder "<<i+1<<": ";
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
	
	
	for (int i=0; i<size; i++)
	{     
        sumPrice=0;
		//int orderNum;
		float price=0;
		
		//orderNum = arr[i];
		
	    switch (arr[i]) 
		{
	        case 1: price = 18.00; 
            break;
			case 2: price = 15.00; 
            break;
			case 3: price = 12.00;
            break;
			case 4: price = 8.00; 
            break; 	
			
			case 5: price = 10.00; 
            break;
			case 6: price = 10.00; 
            break;
			case 7: price = 12.00; 
            break;
			case 8: price = 5.00; 
            break;
	    }
		sumPrice += price;   
    }
	totPrice += sumPrice;
	
	
	cout<<"\t\t\t\t\tPrice : RM"<<fixed<<setprecision(2)<<sumPrice;
	cout<<"\n";
    
	setOrder();
	
}

//CONSTRUCTOR OUTSIDE CLASS
//RECEIPT 
void CAFE::setResit()
{
    system("PAUSE");
    system("CLS");
    
	for (int i=0; i<copySize; i++)
	{
		cout<<"\n";
		switch(copyArr[i])
		{
			case 1: cout<<"\t\t\t\t\tPizza\t18.00"; break;
			case 2: cout<<"\t\t\t\t\tBurger\t15.00"; break;
			case 3: cout<<"\t\t\t\t\tPasta\t12.00"; break;
			case 4: cout<<"\t\t\t\t\tChoc Cake\t8.00"; break; 	
			
			case 5: cout<<"\t\t\t\t\tIce Mocha\t10.00"; break;
			case 6: cout<<"\t\t\t\t\tVanilla Latte\t10.00"; break;
			case 7: cout<<"\t\t\t\t\tGreen Macha Tea\t12.00"; break;
			case 8: cout<<"\t\t\t\t\tSparkling Water \t.00"; break;	
		}
	}
	cout<<"\n\t\t\t\t\tYour Total Price : RM"<<fixed<<setprecision(2)<<totPrice;	
}

//CONSTRUCTOR OUTSIDE CLASS
//DISCOUNT SECTION IF USER HAVE DISCOUNT CODE 
void CAFE::setDisc()
{
	string discount;
	float disPrice;
	char ans,ans1;
	
	if (totPrice!=0)
	{
        cout<<"\n\n\t\t\t\t\tDo you have a discount code[Y/N]:  ";
        cin>>ans1;
        
	    if (ans1=='Y')
        {   
            cout<<"\n\n\t\t\t\t\tPlease key in your discount code : ";
            cin>>discount;
            do{
    			if (discount == "A12B")
    			{
    				cout<<"\n\t\t\t\t\tYou get 10% discount";
    				disPrice = totPrice * 0.1;
    				totPrice -= disPrice;
    			}
    			else if (discount == "Huat23")
    			{
    				cout<<"\n\t\t\t\t\tYou get 20% discount";
    				disPrice = totPrice * 0.2;
    				totPrice -= disPrice;
    			}
    			else
    			{
    				cout<<"\n\t\t\t\t\tinvalid";	
    			//cout<<"\nYour Total Price : RM"<<fixed<<setprecision(2)<<totPrice;
    				cout<<"\n\n\t\t\t\t\tDo you want to try again Y/N: ";
    				cin>>ans;
                }   
            }while(ans=='Y');
        cout<<"\n\t\t\t\t\tDiscounted price : RM"<<fixed<<setprecision(2)<<disPrice;
        //cout<<"\n\t\t\t\t\tYour Total Price After Discount : RM"<<fixed<<setprecision(2)<<totPrice;    
        }
		cout<<"\n\t\t\t\t\tTotal Price to pay: RM"<<fixed<<setprecision(2)<<totPrice;		
	}		
}

//MAIN 
int main()
{
	//CAFE OBJECT 
	CAFE CF;
	
	//HEADER OF THE RESTAURANT NAME 
	cout<<"\n\t\t\t\t\t\t Welcome To 4Baris \n";
	
	//CALL BACK USING OBJECT
	CF.displayMenu();
	CF.setOrder();
	
	CF.setDisc(); //IF-ELSE STATEMENT
	
	
	return 0;
}
