/* BENJAMIN PLOTKIN
   CSIS 135
   Spring 2012
   Homework #7, Program #3
*/

#ifndef GIFTWRAP_H
#define GIFTWRAP_H

// GiftWrap Class Declaration

class GiftWrap
{
	private:					// these private data members constitute a complete GiftWrap object state
	 float length;				// box length--must not be less than 0
	 float width;				// box width--must not be less than 0
	 float height;				// box height--must not be less than 0
	 float taxRate;				// tax rate--must be in range of 0 to 1 (inclusive)
	 float pricePerInch;		// paper price--must not be less than 0

    public:						// class function prototypes
	 GiftWrap();				// default (no-arg) constructor--all box dimensions set to 1.0, pricePerInch set to 0.0036, taxRate set to 0.08
	 GiftWrap(float, float);	// constructor that takes taxRate (between 0 and 1) and PricePerInch args (>= 0)--all box dimensions set to 1.0, illegal args cause default val overrides
	 bool setLength(float);		// sets box length based on passed arg--value must be >=0, func returns true on success and false on bad input
	 bool setWidth(float);		// sets box width based on passed arg--value must be >=0, func returns true on success and false on bad input
	 bool setHeight(float);		// sets box height based on passed arg--value must be >=0, func returns true on success and false on bad input
	 bool setPricePerInch(float);// sets paper price per inch based on passed arg--value must be >=0, func returns true on success and false on bad input
	 bool setTaxRate(float);	// sets sales tax based on passed arg--value must be in range 0 to 1 (inclusive), func returns true on success and false on bad input
	 float getLength()const;	// returns box length
	 float getWidth()const;		// returns box width
	 float getHeight()const;	// returns box height
	 float getTaxRate()const;	// returns sales tax rate
	 float getPricePerInch()const;// returns paper price per inch
	 float calcSubtotal()const;	// returns price of gift wrap before taxes
	 float calcTax()const;		// returns price of tax on gift wrap
	 float calcTotal()const;	// returns total price of gift wrap (subtotal plus tax)
};

#endif