#include <stdio.h>

#define AMOUNT 99.00
#define TAX 0.12
#define TIP1 0.15
#define TIP2 0.18
#define TIP3 0.20

//for computation
float computeTotal (int nOrders)
{
	float fTotal;
	fTotal = nOrders*AMOUNT;
	return fTotal;
}

float computeGross (float fTotal, float fTax)
{
	float fGross;
	fGross = fTotal / (1 + fTax);
	return fGross;
}

float computeTax (float fGross)
{
	float fTax;
	fTax = fGross*TAX;
	return fTax;
}

float computeGrand (float fGross, float fTax)
{
	float fGrand;
	fGrand = fGross+fTax;
	return fGrand;
}

float computeTip1 (float fGrand)
{
	float fTip1;
	fTip1 = fGrand*TIP1;
	return fTip1;
}

float computeTip2 (float fGrand)
{
	float fTip2;
	fTip2 = fGrand*TIP2;
	return fTip2;
}

float computeTip3 (float fGrand)
{
	float fTip3;
	fTip3 = fGrand*TIP3;
	return fTip3;
}

//for display
void displayTotal (float fTotal)
{
	printf("%28.2f\n", fTotal);
}

void displayGross (int nOrders, float fGross)
{
	printf("Total %d item(s) %24.2f\n", nOrders, fGross);
}

void displayTax (float fTax)
{
	printf("Sales Tax %30.2f\n", fTax);
}

void displayGrand (float fGrand)
{
	printf("Grand Total %28.2f\n", fGrand);
}

void displayTip(float fTip1, float fTip2, float fTip3) 
{
    printf("%-4s%5.2f       %-4s%5.2f      %-4s%5.2f\n", 
			"15%=",fTip1,
        	"18%=",fTip2,
        	"20%=",fTip3);
}


void displayHeader ()
{
	printf("%24s\n", "MyKitchen");
	printf("%29s\n", "Taft Avenue, Manila");
	printf ("%26s\n", "Your Receipt\n");
}

void displayDivider ()
{
	printf("%s%s%s%s\n", "----------", "----------", "----------", "----------");
}

void displayFooter ()
{
	printf("\n%30s\n", "Thank you very much!");
	printf("%27s\n", "See you again!");
}

//main
int main ()
{
	int nDate;
	int nOrders;
	float fTotal;
	float fGross;
	float fTax;
	float fGrand;
	float fTip1; 
	float fTip2;
	float fTip3;
	
	//ask for input
	printf("Date: ");
	scanf ("%d", &nDate);
	printf ("Orders: ");
	scanf("%d", &nOrders);
	
	//compute values
	fTotal = computeTotal(nOrders);
	fGross = computeGross(fTotal, TAX);
	fTax = computeTax(fGross);
	fGrand = computeGrand(fGross, fTax);
	fTip1 = computeTip1(fGrand);
	fTip2 = computeTip2(fGrand);
	fTip3 = computeTip3(fGrand);

	displayHeader();
	printf("Date: %d\n", nDate);	
	displayDivider();
	
	//1st section
	printf("Fried Chix Rice\n");
	printf("   %d x %.2f", nOrders, AMOUNT);
	displayTotal(fTotal);
	
	displayDivider();
	
	//2nd section
	displayGross(nOrders, fGross);
	displayTax(fTax);
	
	displayDivider();
	
	//3rd section
	displayGrand(fGrand);
	
	//tip guide
	printf("\n\nTip Guide: \n");
	displayTip(fTip1, fTip2, fTip3);
	
	//footer
	displayFooter();

	return 0;
}