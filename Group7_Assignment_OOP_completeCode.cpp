//GROUP : 7
//SUBJECT: OOP DIT 2125 
//NAME FHERHAD ADITYA AZ ZAHARA (1211205488)
//NAME MUHAMAD ARIF BIN SALLEHUDDIN (1211206128)
//NAME MUHAMMAD FITRI BIN YUSA'(1211206096)
//NAME DANIEL ISKANDAR BIN MIZAN (1211206299)

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//CLASS CAFE
class CAFE
{
	private:
		float price=0;
		float totPrice=0;
		float sumPrice=0;
		
		//USE TO CREATE DYNAMIC ARRAY SIZE
		int size, copySize;
		//ARRAY FOR ORDERARR
		int* orderArr = new int[size];
		//ARRAY FOR RESITARR
		int* resitArr = new int[copySize];
		int emtyIndex = 0;

	public: 	
		void displayMenu();
		void setOrder();
	    void setPrice();
	    void setResit();
	    void setDiscount();
};


//DISPLAY THE MENU 
void CAFE::displayMenu()
{
	cout << "\n\t\t\t\t\t================================="<<endl;
	cout << "\t\t\t\t\t\t   === MENU ==="<<endl;
	cout << "\t\t\t\t\t================================="<<endl;
	
    //FOOD MENU
	cout <<"\n\t\t\t\t\tFOODS"<<endl<<endl;	
	cout <<"\t\t\t\t\t[1]\t Pizza RM 18.00"<<endl;
	cout <<"\t\t\t\t\t[2]\t Burger RM 15.00"<<endl;
	cout <<"\t\t\t\t\t[3]\t Pasta RM 12.00"<<endl;
	cout <<"\t\t\t\t\t[4]\t Choch Cake RM 8.00"<<endl;
	
	//BEVARAGE MENU 
	cout << "\n\t\t\t\t\tBevarage"<<endl<<endl;
	cout <<"\t\t\t\t\t[5]\t Ice Mocha RM 10.00"<<endl;
	cout <<"\t\t\t\t\t[6]\t Vanilla Latte RM 10.00"<<endl;
	cout <<"\t\t\t\t\t[7]\t Green Macha Tea RM 12.00"<<endl;
	cout <<"\t\t\t\t\t[8]\t Sparkling Water RM 5.00"<<endl;
	
	cout << "\n\t\t\t\t\t================================="<<endl;

}


//USER KEY-IN TO ORDER/FINISH ORDER 
void CAFE::setOrder()
{
	char code;
	
	do
	{
	cout<<"\n\t\t\t\t\t|ADD[A]|   |DONE[D]|"<<endl;
	cout<<"\t\t\t\t\tWhat would you like to do:";
	cin>>code;	

		//DISPLAY ErROR CODE INPUT
		if(code!='A' && code!='D')
        {
            cout<<"\t\t\t\t\tRETRY"<<endl;
        }
	}while(code!='A' && code!='D'); //IT WILL START LOOPING IF USER INPUT OTHER THEN A/D
	

	if(code=='A')
	{	
		cout<<"\t\t\t\t\tHow many order : ";
		cin>>size;//NUMBER OF ORDER WILL BE USE AS ORDER ARRAY SIZEe
		
		//VALUE OF SIZE WILL BE ADD&COPPIED TO COPYSIZE
		copySize += size;
		
		//cout<<"\n\t\t\t\t\tEnter order number : "<<endl;
		
		//EVERY VALUE/ORDER WILL BE STORED IN ORDERARR
		for (int i = 0; i<size; i++) 
		{
			
    		cout<<"\t\t\t\t\tOrder "<<i+1<<": ";
			cin>>orderArr[i];
		}
		
		
		for (int i = 0; i<copySize; i++) 
		{
			//EVRY VALUE/ORDER FROM ORDERARR IS COPY TO RESITARR AND PUT IN AN EMPTY INDEX OF THE ARRAY
        	resitArr[emtyIndex] = orderArr[i];
        	emtyIndex++;
   		}
   		
   		//EXPAND THE ARRAY SIZE OF RESITARR ADDING EVERY NEW ORDER ADDED
        copySize++;

		setPrice();	
	}
 	else //IF USER TYPE D(DONE) IT WILL STOP AND GO STRAIGHT TO RESIT
 	{
		setResit();
	}
}


//THIS PART USE ORDER ARR TO SET THE PRICE FOR EVERY ORDER
void CAFE::setPrice()
{	
	sumPrice=0;
	
	for (int i=0; i<size; i++)
	{     
		float price=0;
		
		//USE TO SET EVERY PRICE
	    switch (orderArr[i]) 
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
	    
	    //SUM EVERY ORDER 
		sumPrice += price;   
    }
	
	cout<<"\t\t\t\t\tPrice : RM"<<fixed<<setprecision(2)<<sumPrice;
	cout<<"\n";
    
    //TOTAL ALL ORDER THAT SET TO PRIVATE
    totPrice += sumPrice;
    
	setOrder();
	
}


//THIS PART IS USING RESITARR TO LIST DOWN THE ALL ORDER(HISTORY)
void CAFE::setResit()
{
    system("PAUSE");//to pause for the system
    system("CLS");//to clear the system
    cout<<"\n";
    
	for (int i=0; i<copySize; i++)
	{
		//USE TO LIST DOWN ALL ORDERr
		switch(resitArr[i])
		{
			case 1: cout<<"\t\t\t\t\tPizza\t\t\tRM18.00\n"; 
            break;
            
			case 2: cout<<"\t\t\t\t\tBurger\t\t\tRM15.00\n"; 
            break;
            
			case 3: cout<<"\t\t\t\t\tPasta\t\t\tRM12.00\n"; 
            break;
            
			case 4: cout<<"\t\t\t\t\tChoc Cake\t\tRM8.00\n"; 
            break; 
            	
			case 5: cout<<"\t\t\t\t\tIce Mocha\t\tRM10.00\n"; 
            break;
            
			case 6: cout<<"\t\t\t\t\tVanilla Latte\t\tRM10.00\n"; 
            break;
            
			case 7: cout<<"\t\t\t\t\tGreen Macha Tea\t\tRM12.00\n"; 
            break;
            
			case 8: cout<<"\t\t\t\t\tSparkling Water \tRM5.00\n";
            break;	
		}
	}
	//DISPLAY TOTAL PRICE BEFORE DISCOUNT
	cout<<"\n\n\t\t\t\t\tYour Total Price : \tRM"<<fixed<<setprecision(2)<<totPrice;	
}


//DISCOUNT SECTION 
void CAFE::setDiscount()
{
	string discount;
	float disPrice;
	char ans;
	
	//IF USER HAVE NO ORDER(TOTPRICE=0) IT WILL START THIS IF STATEMENT
	if (totPrice!=0)
	{
        cout<<"\n\n\t\t\t\t\tDo you have a discount code [Y/N]:  ";
        cin>>ans;
        
	    if (ans=='Y')
        {   
        
            do{
            cout<<"\n\n\t\t\t\t\tPlease key in your discount code : ";
            cin>>discount;
        
    			if (discount == "A12B")//FIRST DISCOUNT CODE 10%
    			{
    				cout<<"\n\t\t\t\t\tYou get 10% discount";
    				disPrice = totPrice * 0.1;
    				totPrice -= disPrice;
    				break;
    			}
    			else if (discount == "Huat2023")//SEC DISCOUNT CODE 20%
    			{
    				cout<<"\n\t\t\t\t\tYou get 20% discount";
    				disPrice = totPrice * 0.2;
    				totPrice -= disPrice;
    				break;
    			}
    			else
    			{
    				cout<<"\n\t\t\t\t\tINVALID CODE!!!";	;
    				cout<<"\n\n\t\t\t\t\tDo you want to try again [Y/N]: ";
    				cin>>ans;
                }   
            }while(ans=='Y');//IT WILL LOOP EVERYTIME USER INPUT Y(YES)
            
            //DISPLAY TOTAL DISCOUNT COUSTOMER GET
            cout<<"\n\t\t\t\t\tDiscounted price : RM"<<fixed<<setprecision(2)<<disPrice;    
        }
        //DISPLAY TOTAL PRICE AFTER DISCOUNT TO BE PAID
		cout<<"\n\t\t\t\t\tTotal Price to pay: RM"<<fixed<<setprecision(2)<<totPrice;		
	}		
}

//MAIN 
int main()
{
	//CF AS OBJECT 
	CAFE CF;

	cout<<"\n\t\t\t\t\t\t Welcome To 4Baris Cafe \n";

	CF.displayMenu();
	CF.setOrder();
	CF.setDiscount();
	
	cout << "\n\n\t\t\t\t\t================================="<<endl;
	cout << "\t\t\t\t\t   === THANKYOU FOR COMING ==="<<endl;
	cout << "\t\t\t\t\t================================="<<endl;

	return 0;
}