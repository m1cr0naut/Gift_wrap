/* BENJAMIN PLOTKIN
   CSIS 135
   Spring 2012
   Homework #7, Program #3
*/

// File GiftWrap.cpp -- Function Implementation File
// Contains function definitions for GiftWrap class functions

#include "GiftWrap.h"

/*GIFTWRAP MEMBER FUNCTION DEFINITIONS
******************************************************************************
                            GiftWrap::GiftWrap
Default constructor, takes no arguments, initializes all box dimensions to 1.0 
Sets paper price per inch to 0.0036, sales tax rate to 0.08
******************************************************************************/

GiftWrap::GiftWrap()
{
	length = 1.0f;
	width = 1.0f;
	height = 1.0f;
	taxRate = 0.08f;
	pricePerInch = 0.0036f;
}

/*****************************************************************************
                            GiftWrap::GiftWrap(float, float)
Constructor that takes tax rate and paper price per inch as arguments
Tax must be in range of 0 to 1, price per inch must be >= 0
Box dimensions default to 1.0, illegal inputs default to default values
******************************************************************************/

GiftWrap::GiftWrap(float taxIn, float inchPriceIn)
{
	length = 1.0f;
	width = 1.0f;
	height = 1.0f;
	if (taxIn >= 0.0 && taxIn <= 1.0)
	{
		taxRate = taxIn;
	}
	else
	{
		taxRate = 0.08f;
	}

	if (inchPriceIn >= 0.0)
	{
		pricePerInch = inchPriceIn;
	}
	else
	{
		pricePerInch = 0.0036f;
	}
}

/******************************************************************************
                         GiftWrap::setLength(float)
Set function that takes float value input for box length and sets member
variable length.

If the argument passed to the function is zero or greater it is copied
into the member variable length and true is returned.  If the argument is 
negative, the value of length remains unchanged and false is returned
*******************************************************************************/
bool GiftWrap::setLength(float lengthIn)
{
	bool validData;			// local variable

	if (lengthIn >= 0.0)	// test for valid value input
	{
		length = lengthIn;	// set member variable
		validData = true;
	}

	else					// input value is negative, return false
	{
		validData = false;
	}

	return validData;
}

/******************************************************************************
                         GiftWrap::setWidth(float)
Set function that takes float value input for box width and sets member
variable width.

If the argument passed to the function is zero or greater it is copied
into the member variable width and true is returned.  If the argument is 
negative, the value of width remains unchanged and false is returned
*******************************************************************************/
bool GiftWrap::setWidth(float widthIn)
{
	bool validData;			// local variable

	if (widthIn >= 0.0)		// test for valid value input
	{
		width = widthIn;	// set member variable
		validData = true;
	}

	else					// input value is negative, return false
	{
		validData = false;
	}

	return validData;
}

/******************************************************************************
                         GiftWrap::setHeight(float)
Set function that takes float value input for box height and sets member
variable height.

If the argument passed to the function is zero or greater it is copied
into the member variable height and true is returned.  If the argument is 
negative, the value of height remains unchanged and false is returned
*******************************************************************************/
bool GiftWrap::setHeight(float heightIn)
{
	bool validData;			// local variable

	if (heightIn >= 0.0)	// test for valid value input
	{
		height = heightIn;	// set member variable
		validData = true;
	}

	else					// input value is negative, return false
	{
		validData = false;
	}

	return validData;
}

/******************************************************************************
                         GiftWrap::setPricePerInch(float)
Set function that takes float value input for paper price per inch and sets 
member variable pricePerInch.

If the argument passed to the function is zero or greater it is copied
into the member variable pricePerInch and true is returned.  If the argument is 
negative, the value of pricePerInch remains unchanged and false is returned
*******************************************************************************/
bool GiftWrap::setPricePerInch(float priceIn)
{
	bool validData;				// local variable

	if (priceIn >= 0.0)			// test for valid value input
	{
		pricePerInch = priceIn; // set member variable
		validData = true;
	}

	else						// input value is negative, return false
	{
		validData = false;
	}

	return validData;
}

/******************************************************************************
                         GiftWrap::setTaxRate(float)
Set function that takes float value input for sales tax rate and sets member
variable taxRate.

If the argument passed to the function is between zero and 1 (inclusive) it is 
copied into the member variable taxRate and true is returned.  If the argument is 
out of range, the value of taxRate remains unchanged and false is returned
*******************************************************************************/
bool GiftWrap::setTaxRate(float rateIn)
{
	bool validData;						// local variable

	if (rateIn >= 0.0 && rateIn <= 1.0)	// test for valid value input
	{
		taxRate = rateIn;				// set member variable
		validData = true;
	}

	else								// input value is negative, return false
	{
		validData = false;
	}

	return validData;
}

/******************************************************************************
                         GiftWrap::getLength()
This function returns the float value that is in the private member length
*******************************************************************************/
float GiftWrap::getLength()const
{
	return length;
}

/******************************************************************************
                         GiftWrap::getWidth()
This function returns the float value that is in the private member width
*******************************************************************************/
float GiftWrap::getWidth()const
{
	return width;
}

/******************************************************************************
                         GiftWrap::getHeight()
This function returns the float value that is in the private member height
*******************************************************************************/
float GiftWrap::getHeight()const
{
	return height;
}

/******************************************************************************
                         GiftWrap::getTaxRate()
This function returns the float value that is in the private member taxRate
*******************************************************************************/
float GiftWrap::getTaxRate()const
{
	return taxRate;
}

/******************************************************************************
                         GiftWrap::getPricePerInch()
This function returns the float value that is in the private member pricePerInch
*******************************************************************************/
float GiftWrap::getPricePerInch()const
{
	return pricePerInch;
}

/******************************************************************************
                         GiftWrap::calcSubtotal()
This function returns the BASE price of gift wrap for an instance of GiftWrap
*******************************************************************************/
float GiftWrap::calcSubtotal()const
{
	float boxArea = 0.0;		// local variables
	float basePrice = 0.0;

	// calc surface area of box using member variables
	boxArea = (2 * length * width) + (2 * length * height) + (2 * width * height);
	basePrice = boxArea * pricePerInch;
	
	return basePrice;
}

/******************************************************************************
                         GiftWrap::calcTax()
This function returns the TAX due on gift wrap for an instance of GiftWrap
*******************************************************************************/
float GiftWrap::calcTax()const
{
	float taxCost = 0.0;		// local variable

	// call calcSubtotal to get base price, and multiply by member variable taxRate
	taxCost = calcSubtotal() * taxRate;
	
	return taxCost;
}

/******************************************************************************
                         GiftWrap::calcTotal()
This function returns the TOTAL due (base + tax) on gift wrap for an instance 
of GiftWrap
*******************************************************************************/
float GiftWrap::calcTotal()const
{
	float wrapTotal = 0.0;		// local variable

	// call calcSubtotal and calcTax and add them together to get total price
	wrapTotal = calcSubtotal() + calcTax();
	
	return wrapTotal;
}