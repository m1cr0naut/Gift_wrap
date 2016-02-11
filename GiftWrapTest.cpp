/* BENJAMIN PLOTKIN
   CSIS 135
   Spring 2012
   Homework #7, Program #3
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "GiftWrap.h"
using namespace std;

int main()
{	
	string shopName = "Sally's Gifts";  // store name for this test program
	char userChoice;
	float boxLen;
	float boxWid;
	float boxHigh;
	
	// instantiate a GiftWrap object with tax rate of 9.25% and paper cost of 0.25 cents per inch
	GiftWrap sallys(0.0925f, 0.0025f); 

	// main loop
	do
	{
		// display user menu
		cout << "GIFT WRAP INVOICE GENERATOR\n"
			 << "-------------------------------\n"
			 << "a) Generate Gift Wrap Invoice\n"
			 << "q) Quit\n" << endl;

		cin >> userChoice;

		if (userChoice == 'a' || userChoice == 'A')
		{
			// get box length from user
			cout << "Please enter the length of the box to be wrapped: ";
			cin >> boxLen;

			while (sallys.setLength(boxLen) == false)
			{
				cout << "\n\nBox length cannot be less than zero--please enter the length of the box to be wrapped: ";
				cin >> boxLen;
			}

			// get box width from user
			cout << "Please enter the width of the box to be wrapped: ";
			cin >> boxWid;

			while (sallys.setWidth(boxWid) == false)
			{
				cout << "\n\nBox width cannot be less than zero--please enter the width of the box to be wrapped: ";
				cin >> boxWid;
			}

			// get box height from user
			cout << "Please enter the height of the box to be wrapped: ";
			cin >> boxHigh;

			while (sallys.setHeight(boxHigh) == false)
			{
				cout << "\n\nBox height cannot be less than zero--please enter the height of the box to be wrapped: ";
				cin >> boxHigh;
			}

			// print gift wrap invoice
			cout << "\nGIFT WRAP INVOICE - " << shopName << "\n"
				 << "----------------------------------\n"
				 << "Box Length: " << fixed << setprecision(1) << sallys.getLength() << "\n"
				 << "Box Width:  " << sallys.getWidth() << "\n"
				 << "Box Height: " << sallys.getHeight() << "\n"
				 << "Price Per Inch: " << setprecision(4) << sallys.getPricePerInch() << "\n\n"
				 << "SUBTOTAL:" << setw(12) << setprecision(2) << sallys.calcSubtotal() << "\n"
				 << "TAX:" << setw(17) << sallys.calcTax() << endl
				 << "           ----------\n"
				 << "TOTAL:" << setw(15) << sallys.calcTotal() << "\n" << endl;
		}

		else if (userChoice != 'q' && userChoice != 'Q')
		{
			cout << "Invalid Selection\n" << endl;
		}

		else
		{	
			cout << "You have quit the Invoice Generator--goodbye!\n" << endl;
		}
	}
	while (userChoice != 'q' && userChoice != 'Q');

	system("PAUSE");
	return 0;
}