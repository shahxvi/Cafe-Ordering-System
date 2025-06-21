#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

//function prototype
void menu();
void receipt(int countB, int countF, int countD, int menuQtyAll[], int countCust, int memSold, double totSales);
double Total(double, double, double, double);

int main (){
    //function call
    menu();
	// variable declaration    
	string codeB, codeF, codeD, catD;
	char catB, catF, newMem;
	char newCust = 'Y', ans_topping;
	int  countCust, memSold, countB = 0, countF = 0, countD = 0;
	double totalSales;
	
	double subtotal[100] = {};
	double total[100] = {};
    int menuQtyAll[21] = {};
    string nameB[6] = {"Latte", "Mocha", "Caramel Macchiato", "Green Tea", "Java Chip", "Mint Chocolate"};
    string nameF[6] = {"Spaghetti Bolognese", "Spaghetti Carbonara", "Lasagna", "Chicken Chop", "Cheeseburger", "Fish & Chips"};
    string nameD[9] = {"Croissant Chocolate", "Croissant Strawberry", "Croissant Matcha", "Cake Red Velvet", "Cake Chocolate Indulgence", "Cake Basque Cheesecake", "Ice Cream Vanilla", "Ice Cream Strawberry", "Ice Cream Chocolate"};
    string nameT[6] = {"Sprinkles", "HoneyComb", "Oreo Crumbs", "Whipped Cream", "Boba Pearls", "None"};

do
{
	//looping order for every new customer
    string name = " ", codeB, codeF, codeD;
	double rate = 0.0, tax = 0.0, memprice = 0.0;
	char order = 'Y', catB, catF, catD, memType, codeT, membership;
	int cat;
	int indexT[3] = {};
	int menuQty[21] = {};
	double menuPrice[21] = {};
	
	string pink = "\033[38;5;139m" ;
    string reset = "\033[0m";
    string blink = "\033[5m";
    string bg2 = "\033[48;5;67m";
    string underlined = "\033[4m";
	string bg = "\033[48;5;139m";
    string black = "\033[30m";
	
    cout << "\nPlease enter your name : ";
	cin.sync();
	cin.clear();
	getline(cin,name);
	cout << underlined << "\nWelcome " << pink << name << reset << underlined << " To Miracle Cafe" << reset << endl;
	
	do
	{
	//looping order for each customer
	int qty = 0;
    double price = 0.0, totT=0.0, totB=0.0, totF=0.0, totD=0.0;
    	    	
    cout << "\nPlease Choose your category (1)beverage | (2)food | (3)dessert : ";
    cin >> cat;  
	 
    	 if(cat == 1)
		{
    		cout << "\n" << "\t(C)coffee | (F)frappe  : ";
    	 	cin >> catB;
    	 	
    	 	//coffee
    		if(catB == 'C' || catB == 'c')
			{  	 			
    	 		cout << "\n\tEnter Coffee Code      : ";
    	 		cin >> codeB;
    	 		cout << "\n\tEnter quantity         : ";
    	 		cin >> qty;
    	 		
				//coffee selection
	    	 	if(codeB == "C01" || codeB == "c01")
				 {
	    			price = 9.50 * qty;
	    			menuQty[0] += qty;
	    			menuPrice[0] += price;
				}
	   			else if(codeB == "C02" || codeB == "c02")
				{
    				price = 11.50 * qty;	    					
					menuQty[1] += qty;
					menuPrice[1] += price;
					
	   			}
	   			else if(codeB == "C03" || codeB == "c03")
				{
    				price = 14.90 * qty;
	    			menuQty[2] += qty;
	    			menuPrice[2] += price;
	   			}	
	   			else
				{
	   			    price = 0;
				}		
    		}
    		//frappe 
    	 	else if(catB == 'F' || catB == 'f')
			{         
    	 		cout << "\n\tEnter Frappe Code      : ";
    			cin >> codeB;
   	 			cout << "\n\tEnter quantity         : ";
    	 		cin >> qty;
				
				//frappe selection
	   	 		if(codeB == "F01" || codeB == "f01")
				{   
	  	 			price = 15.90 * qty;
    	 			menuQty[3] += qty;
    	 			menuPrice[3] += price;
	    		}	     	 
	    		else if(codeB == "F02" || codeB == "f02")
				{
	   				price = 16.90 * qty;
	   				menuQty[4] += qty;
	   				menuPrice[4] += price;
	    		}		
	    		else if(codeB == "F03" || codeB == "f03"){
	    			price = 15.90 * qty;
					menuQty[5] += qty;
					menuPrice[5] += price;
	    		}
	    		else
				{
	    		    price = 0;
	    		}
    		}
    		totB += price;
	    	countB += qty;  	//total count of beverages sold (all customers)
    	}
    	else if(cat == 2)
		{
			cout << "\n" << "\t(I)italian | (W)western : ";
     		cin >> catF;
    		
    		//italian
     		if(catF == 'I' || catF == 'i')
		 	{	
    	 		cout << "\n\tEnter Italian Food Code : ";
	    		cin >> codeF;	 			
	     		cout << "\n\tEnter quantity          : ";
   	 			cin >> qty;
   	 			
				//italian selection
		    	if(codeF == "S1" || codeF == "s1")
				{
		    	 	price = 18.00 * qty;
		   			menuQty[6] += qty;
		   			menuPrice[6] += price;
		    	}	 
		    	else if(codeF == "S2" || codeF == "s2")
				{
		   			price = 21.00 * qty;
		    		menuQty[7] += qty;
		    		menuPrice[7] += price;
		   		}			
		    	else if(codeF == "S3" || codeF == "s3")
				{
		    		price = 16.00 * qty;
	 				menuQty[8] += qty;
	 				menuPrice[8] += price;
		    	}
		  		else
				{
		    		price = 0;
		   		}
			}
							
    		//western	 
    		else if(catF == 'W' || catF == 'w')
			{	
    	 		cout << "\n\tEnter Western Food Code : ";
    	 		cin >> codeF;
    			cout << "\n\tEnter quantity          : ";
  	 			cin >> qty;
  	 			
				//western selection
	     		if(codeF == "W1" || codeF == "w1")
				 {
	  	 			price = 21.90 * qty;
	  				menuQty[9] += qty;
	  				menuPrice[9] += price;
	   			}
	    		else if(codeF == "W2" || codeF == "w2"){
 					price = 18.90 * qty;
	    			menuQty[10] += qty;
	    			menuPrice[10] += price;
	    		}			
	    		else if(codeF == "W3" || codeF == "w3"){
	  				price = 16.00 * qty;
  					menuQty[11] += qty;
  					menuPrice[11] += price;
	    		}				
	    		else
				{
	    		    price = 0;
	    		} 
			}
			totF += price;
	    	countF += qty;		//total count of foods sold (all customers)
    	}
	 	else if(cat == 3)
		{
			cout << "\n" << "\t(FC)croissant | (CC)cake | (IC)ice cream : ";
    	 	cin >> catD;
    	 		
    	 	//croissant
    	 	if(catD == "FC" || catD == "fc")
			 {	    	 			
	    	 	cout << "\n\tEnter Croissant Code \t: ";
	    		cin >> codeD;
	    	 	cout << "\n\tEnter quantity \t\t: ";
	    		cin >> qty;

				//croissant selection
	    		if(codeD == "FC1" || codeD == "fc1")
				{
	    	 		price = 10.90 * qty;
	    	 		menuQty[12] += qty;
	    	 		menuPrice[12] += price;
	   			}	 
	    		else if(codeD == "FC2" || codeD == "fc2")
				{
 					price = 12.50 * qty;
	    			menuQty[13] += qty;
	    			menuPrice[13] += price;
	    		}
	    		else if(codeD == "FC3" || codeD == "fc3"){
					price = 10.40 * qty;
					menuQty[14] += qty;
					menuPrice[14] += price;
	    		}		
	    		else
				{
	    			price = 0;
	    		}
    		}    			 
    		//cake
    		else if(catD == "CC" || catD == "cc")
			{ 	 			
    	 		cout << "\n\tEnter Cake Code \t: ";
    	 		cin >> codeD;
    	 		cout << "\n\tEnter quantity \t\t: ";
    			cin >> qty;
    			
				//cake selection
	 			if(codeD == "CC1" || codeD == "cc1")
				 {
	    			price = 15.90 * qty;
	    			menuQty[15] += qty;
	    			menuPrice[15] += price;
	   			}	 
	    		else if(codeD == "CC2" || codeD == "cc2")
				{
	    			price = 17.90 * qty;
	    			menuQty[16] += qty;
	    			menuPrice[16] += price;
	   			}
	    		else if(codeD == "CC3" || codeD == "cc3")
				{
	    			price = 18.90 * qty;
	    			menuQty[17] += qty;
	    			menuPrice[17] += price;
	    		}	
	    		else
				{
	   			    price = 0;
				}
	    	}	 
    		//ice cream
    		else if(catD == "IC" || catD == "ic")
			{
				cout << "\n\tEnter Ice Cream Code \t: ";
    	 		cin >> codeD;	
    	 		cout << "\n\tEnter quantity \t\t: ";
    	 		cin >> qty;

				//ice cream selection
	   			if(codeD == "IC1" || codeD == "ic1")
				   {
	    	 		price = 3.00 * qty;
	    	 		menuQty[18] += qty;
	    	 		menuPrice[18] += price;
	    		}	 
	    		else if(codeD == "IC2" || codeD == "ic2")
				{
	    			price = 3.00 * qty;
	    			menuQty[19] += qty;
	    			menuPrice[19] += price;
	  			}
	    		else if(codeD == "IC3" || codeD == "ic3")
				{
	    			price = 3.00 * qty;
	    			menuQty[20] += qty;
	    			menuPrice[20] += price;
	    		}		
	    		else
				{
	    		    price = 0;
	   			}
	   			totD += price;
    			countD += qty;		//total count of desserts sold (all customers)
    			
	   			//codeT	
    			cout << underlined << "\n\nDo you want to add codeT? <Y/N>" << reset << " : ";
    			cin >> ans_topping;
    		
    			//sentinel loop : for customer to choose max 3 codeT
    			if(ans_topping == 'Y' || ans_topping == 'y')
				{
	            	cout << "\n\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "    Add-On codeT" << "\t" << "|" << "      Price (RM)"  << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "     Sprinkles " << bg2 << black << "(S)"  << reset << reset << "\t" << "|" << "\t  1.50" << "\t" << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "     Honeycomb " << bg2 << black << "(H)" << reset << reset << "\t" << "|" << "\t  4.00" << "\t" << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "    Oreo crumbs " << bg2 << black << "(O)" << reset << reset << "\t" << "|" << "\t  2.00" << "\t" << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "    Whipped cream " << bg2 << black << "(W)" << reset << reset << "\t" << "|" << "\t  1.00" << "\t" << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	cout << "\t\t|" << "    Boba pearls " << bg2 << black << "(B)" << reset << reset << "\t" << "|" << "\t  2.00" << "\t" << "\t|" << endl;
	            	cout << "\t\t ------------------------------------------------" << endl;
	            	
	            	cout << "\tPick any 3 codeT <N to stop> " << endl;
        			
        			int numtops=0;
        	    	for(int addtops = 0; addtops < 3; addtops++)
					{
            	    	numtops++;
            	    	cout << "\tTopping (" << numtops << ") : ";
            	    	cin >> codeT;
            	    	int indexT = 0;
            	    	
	            	    //codeT selection
	            	    if(codeT == 'S' || codeT == 's'){
	            	    	indexT[addtops] = 0;
	            	        price = 1.50 * qty;
	            	    }	            	    
	            	    else if(codeT == 'H' || codeT == 'h')
						{
	            	    	indexT[addtops] = 1;
	            	        price = 4.00 * qty;
	            	    }	            	    
	            	    else if(codeT == 'O' || codeT == 'o')
						{
	            	    	indexT[addtops] = 2;
	            	        price = 2.00 * qty;
	            	    }	            	    
	            	    else if(codeT == 'W' || codeT == 'w')
						{
	            	    	indexT[addtops] = 3;
	            	        price = 1.00 * qty;
	            	    }	            	    
	            	    else if(codeT == 'B' || codeT == 'b')
						{
	            	    	indexT[addtops] = 4;
	            	        price = 2.00 * qty;
	            	    }	            	    
	            	    else if(codeT == 'N' || codeT == 'n')
						{
	            	    	indexT[addtops] = 5;
	            	        price = 0;
	            	        addtops++;
	            	    }
	            	    else
						{
	            	    	cout << "Enter again." << endl;
	            	    	addtops--;
	            	    	numtops--;
						}
	            	    //calculation : total price for codeT
	            	    totT += price;
            		}
    			}
    		}
		}
    		
    	//array : to calculate subtotal for each customer
            subtotal[countCust] = Total(totB, totF, totD, totT);
            countCust++;
            
    	//array : to calculate the most chosen menu
    	for(int x = 0; x < 21; x++)
		{
        	menuQtyAll[x] += menuQty[x];
   		}
        cout << underlined << "\n\nDo you want to place another order? <(Y)yes | (N)no>" << reset << " : ";
    	cin >> order;
    }
	while(order == 'Y' || order == 'y');
    
    	//membership discount
        cout << "\n---------------------------------------------------------------------------" << endl;
        cout << "Do you have a membership? <Y/N> : ";
        cin >> membership;
        
        if(membership == 'Y' || membership == 'y')
		{            
            cout << "Membership Type (S)silver | (P)premium | (G)gold  : ";
            cin >> memType;
            
	            //discount rate
	            if(memType == 'S' || memType == 's')
				{
	                rate = 0.1 * subtotal[countCust];    
	            }
				else if(memType == 'P' || memType == 'p')
				{
	                rate = 0.15 * subtotal[countCust];
	            }
				else if(memType == 'G' || memType == 'g')
				{
	                rate = 0.2 * subtotal[countCust];
	            }    
				else{
	                rate = 0;
	                memprice = 0;
	            }
	    }                
        if(membership == 'N' || membership == 'n')
		{ 
            cout << "Do you want to buy a membership ? <Y/N> : ";
            cin >> membership;
            
            if(membership == 'Y' || membership == 'y')
			{            	
                cout << "\nChoose your membership <(S)silver | (P)premium | (G)gold> : ";
                cin >>  newMem;
                
	            //membership selection
	            if(newMem == 'S' || newMem == 's')
				{
                	memprice = 10.00;
	            }    
				else if(newMem == 'P' || newMem == 'p')
				{	
	         		memprice = 20.00;
	            }    
				else if(newMem == 'G' || newMem == 'g')
				{
	                memprice = 30.00;
	            }
	            else
				{
	                memprice = 0.00;
	            	rate = 0.00;
	            }
	                
             	memSold++;
	      		cout << "---------------------------------------------------------------------------" << endl;
                cout << pink << blink << "\n\t\tThank you for choosing to become a member!" << reset << reset <<endl;
				cout << "\n  Your membership price is RM" << memprice << " and it will be activated after 24 hours" << endl;
            }
        }
        
    //calculation : tax rate
    double const tax = 0.06 * subtotal[countCust];
  	    
	//output : customer receipt
        cout << "\n\n---------------------------------------------------------------------------" << endl;
    	cout << "\t\t\t" << "    CUSTOMER RECEIPT" << endl; 
    	cout << "--------------------------------------------------------------------------- " << endl;
    	
    	//date and time
		time_t now = time(0);
   		tm* localTime = localtime(&now);

   		cout << setfill('0') << setw(2) << localTime->tm_mday << "/"
        << setfill('0') << setw(2) << localTime->tm_mon + 1 << "/"
        << localTime->tm_year + 1900 << endl;

   		cout << setfill('0') << setw(2) << (localTime->tm_hour % 12 == 0 ? 12 : localTime->tm_hour % 12) << ":"
        << setfill('0') << setw(2) << localTime->tm_min << " "
        << (localTime->tm_hour < 12 ? "AM" : "PM") << endl;

		cout << "order for :" << name << endl;

		//receipt 
		cout << "\n\t" << "item" << "\t\t\t" << "quantity" << "\t\t" << "price (RM)" << endl;
		
		for(int i = 0; i < 21 ; i++)
		{
			if(i >= 0 && i <= 5)
			{
				if(menuQty[i] != 0){
				cout << "\n\t" << nameB[i] << "\t\t\t "  << menuQty[i] << "\t\t        " << menuPrice[i] << endl;
				}
			}
			else if(i >= 6 && i <= 11)
			{
				if(menuQty[i] != 0){
				cout << "\n\t" << nameF[i] << "\t\t\t "  << menuQty[i] << "\t\t        " << menuPrice[i] << endl;
				}
			}
			else if(i >= 12 && i < 21)
			{
				if(menuQty[i] != 0){
				cout << "\n\t" << nameD[i] << "\t\t\t "  << menuQty[i] << "\t\t        " << menuPrice[i] << endl;
				}
			}
		}
		for(int i = 0; i < 3; i++)
		{
			cout << "with tops " << "[" << nameT[indexT[i]] << "]" << endl;

		}
		cout << "\n--------------------------------------------------------------------------- " << endl;
    	cout << "Customer Name" << "\t\t" << " : " << name << endl;
        cout << fixed << setprecision(2) << showpoint;
        cout << "Total" << "\t\t\t" << " : RM" << subtotal[countCust] << endl;
        cout << "membership discount" << "\t" << " : RM" << rate << endl;
        cout << "Tax (6%)" << "\t\t" << " : RM" << tax << endl;
        
        //calculation : final total (amount due)
        total[countCust] = subtotal[countCust] - rate + tax + memprice;
        totSales += total[countCust];
        cout << "Amount Due"<< "\t\t" << " : RM" << total[countCust] << endl;
        cout << "\nThank you for ordering! please take a seat while we prepare your food. . ." << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        cout << "Insert another customer? <Y/N> : ";
        cin >> newCust;    	
		
		//function call
    receipt(countB, countF, countD, countCust, memSold, totSales);	
}
while(newCust == 'Y' || newCust == 'y');

return 0;

//function definition
void menu(){
    string pink = "\033[38;5;139m" ;
    string reset = "\033[0m";
    string blink = "\033[5m";
    string color = "\033[35;40m";
    string bg = "\033[48;5;139m";
    string black = "\033[30m";
    //header
	cout << pink << "***************************************************************************" << reset << endl;
    cout << pink << "*" << reset << blink << "\t\t\t       MIRACLE CAFE    \t\t\t  " << reset << pink << "        *" << reset << endl;
	cout << pink << "***************************************************************************" << reset << endl;
    
//BEVERAGE
	cout <<"\n" << "\t\t\t\t" << "BEVERAGE" << endl; 
	
	//coffee
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "C01" << "\t" << "|" << "\t" << "Latte" << "\t\t\t" << "|"<< " RM9.50  " << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << " Coffee " << bg << black << "(C)" << reset << reset << " " << "   |" << "\t" << "C02" << "\t" << "|" << "\t" << "Mocha" << "\t\t\t" << "|"<< " RM11.50 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "C03" << "\t" << "|"  << "\t" <<  "Caramel Macchiato"  <<  "\t" <<"|"  << " RM14.90 "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//frappe
	cout << "|" << "\t\t" << "|" << "\t" << "F01" << "\t" << "|" << "\t" << "Green Tea" << "\t\t" << "|" <<  " RM15.90 " << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << " Frappe " << bg << black << "(F)" << reset << reset << " " << "   |" << "\t" << "F02" << "\t" << "|" << "\t" << "Java Chip" << "\t\t" << "|"  << " RM16.90 " << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "F03" << "\t" << "|"  << "\t" <<  "Mint Chocolate"  <<  "\t\t" <<"|" <<  " RM15.90 "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
//FOOD
	cout <<"\n" << "\t\t\t\t" << "  FOOD" << endl; 
	
	//Italian
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "S1" << "\t" << "|" << "\t" << "Spaghetti Bolognese" << "\t" << "|"  << " RM18.00 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << " Italian " << bg << black << "(I)" << reset << reset << " " << "  |" << "\t" << "S2" << "\t" << "|" << "\t" << "Spaghetti Carbonara" << "\t" << "|" << " RM21.00 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "S3" << "\t" << "|"  << "\t" <<  "Lasagna"  <<  "\t\t\t" <<"|"  << " RM16.00 " << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//Western
	cout << "|" << "\t\t" << "|" << "\t" << "W1" << "\t" << "|" << "\t" << "Chicken Chop" << "\t\t" << "|"  << " RM21.90 " << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << " Western " << bg << black << "(W)" << reset << reset << " " << "  |" << "\t" << "W2" << "\t" << "|" << "\t" << "Cheeseburger" << "\t\t" << "|"  << " RM18.90 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "W3" << "\t" << "|"  << "\t" <<  "Fish & Chips"  <<  "\t\t" <<"|"  << " RM16.00 "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;	
	
//DESSERT
	cout <<"\n" << "\t\t\t\t" << " DESSERT" << endl; 
	
	//flavoured croissant
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "FC1" << "\t" << "|" << "\t" << "Chocolate" << "\t\t" << "|"  << " RM10.90 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "Croissant " << bg << black << "(FC)" << reset << reset << " " << "|" << "\t" << "FC2" << "\t" << "|" << "\t" << "Strawberry" << "\t\t" << "|" << " RM12.50 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "FC3" << "\t" << "|"  << "\t" <<  "Matcha"  <<  "\t\t\t" <<"|"  << " RM10.40 "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//cake
	cout << "|" << "\t\t" << "|" << "\t" << "CC1" << "\t" << "|" << "\t" << "Red Velvet" << "\t\t" << "|" << " RM15.90 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << " Cake " << bg << black << "(CC)" << reset << reset << " " << "\t" << "|" << "\t" << "CC2" << "\t" << "|" << "\t" << "Chocolate Indulgence"  << "\t" << "|"  << " RM17.90 "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "CC3" << "\t" << "|"  << "\t" <<  "Basque Cheesecake"  <<  "\t" <<"|" << " RM18.90 "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	
	//ice cream
	cout << "|" << "\t\t" << "|" << "\t" << "IC1" << "\t" << "|" << "\t" << "Vanilla" << "\t\t\t" << "|"  << " RM3.00  "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "Ice Cream " << bg << black << "(IC)" << reset << reset << " " << "|" << "\t" << "IC2" << "\t" << "|" << "\t" << "Strawberry" << "\t\t" << "|"  << " RM3.00  "  << "|" << endl;
	cout << "|" << "\t\t" << "|" << "----------------------------------------------------------" << endl;
	cout << "|" << "\t\t" << "|" << "\t" << "IC3" << "\t" << "|"  << "\t" <<  "Chocolate"  <<  "\t\t" <<"|"  << " RM3.00  "  << "|" << endl;
	cout << "---------------------------------------------------------------------------" << endl;	
	
}
void receipt(int countB, int countF, int countD, int menuQtyAll[], int countCust, int memSold, double totSales){
    
    string menuArr[21] = {"Latte", "Mocha", "Caramel Macchiato", "Green Tea", "Java Chip", "Mint Chocolate", "Spaghetti Bolognese", "Spaghetti Carbonara", "Lasagna", "Chicken Chop", "Cheesebuger", "Fish & Chips", "Croissant Chocolate", "Croissant Strawberry", "Croissant Matcha", "Cake Red Velvet", "Cake Chocolate Indulgence", "Cake Basque Cheesecake", "Ice Cream Vanilla", "Ice Cream Strawberry", "Ice Cream Chocolate"};
	int min = 1000, max = -1;
	string maxMenu, minMenu;
    
    //least chosen menu
    for(int x = 0; x < 21; x++)
	{
		if(min > menuQtyAll[x])
		{
			min = menuQtyAll[x];
			minMenu = menuArr[x];		
		}
   	}
   	
    //most chosen menu
    for(int x = 0; x < 21; x++)
	{
		if(max < menuQtyAll[x])
		{
			max = menuQtyAll[x];
			maxMenu = menuArr[x];		
		}
   	}
    
    //KITCHEN RECEIPT
    cout << "\n---------------------------------------------------------------------------" << endl;
	cout << "\t\t\t" << "KITCHEN RECEIPT" << endl; 
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "The most chosen menu\t\t: " << maxMenu << "- total " << max << endl;
    cout << "The least chosen menu\t\t: " << minMenu << "- total " << min << endl;
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "Total Beverage Sold\t\t: " << countB << endl;
	cout << "Total Food Sold\t\t\t: " << countF << endl;
	cout << "Total Dessert Sold\t\t: " << countD << endl;
	cout << "--------------------------------------------------------------------------- " << endl;
	cout << "Total Customer\t\t\t: " << countCust << endl;
	cout << "Total Membership Sold\t\t: " << memSold << endl;
	cout << "***************************************************************************" << endl;
	cout << "Total Sales\t\t\t: RM" << totSales << endl;
	cout << "***************************************************************************" << endl;
    
}
double Total(double totB, double totF, double totD, double totT){
    double total = 0.0;
    total = totB + totF + totD + totT;
    return total;
}

