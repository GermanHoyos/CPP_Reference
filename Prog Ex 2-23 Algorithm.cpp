#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{

    double purchasePrice, sellingPrice, serviceFee,
    tAmountInv, tAmountRec, tServCharge, PosOrNegGain;

    int numBoughtOrSold;

    serviceFee = 1.5;

    cout << "\nPlease enter purchase price of each share: \n" ;
    cin >> purchasePrice;

    cout << "\nPlease enter how much you are going to sell each share for: \n";
    cin >> sellingPrice;

    cout << "\nPlease enter the number of shares sold: \n";
    cin >> numBoughtOrSold;

    tAmountInv = ((purchasePrice * numBoughtOrSold) * serviceFee / 100) + (purchasePrice * numBoughtOrSold);
    cout << "\nThe total amount invested: " << tAmountInv;

    tAmountRec = (sellingPrice * numBoughtOrSold) - ((sellingPrice * numBoughtOrSold) * serviceFee / 100);
    cout << "\nThe total amount received: " << tAmountRec;

    tServCharge = ((purchasePrice * numBoughtOrSold) * serviceFee / 100) + ((sellingPrice * numBoughtOrSold) * serviceFee / 100);
    cout << "\nThe total amount of service charges: " << tServCharge;

    PosOrNegGain = (sellingPrice * numBoughtOrSold) - (purchasePrice * numBoughtOrSold) - (tServCharge);
    cout << "\nAmount gained or lost: " << PosOrNegGain;

return 0;
}
/*
****************************************************************************
 C++ Programming - From Problem Analysis to Program Design 6th Edition
 Chapter 2 - Exercise 25
 markdhoad@gmail.com

 Cindy uses the services of a brokerage firm to buy and sell stocks.
 The firm charges 1.5% service charges on the total amount for each transaction,
 buy or sell. When Cindy sells stocks, she would like to know if she gained or
 lost on a particular investment. Write a program that allows Cindy to input
 the number of shares sold, the purchase price of each share, and the selling
 price of each share. The program outputs the amount invested, the total
 service charges, amount gained or lost, and the amount received after selling the stock.

 ****************************************************************************
 */

/*
#include <iostream>
#include <iomanip>


using namespace std;

int main(){
    const double BROKERAGE_FEE = 0.015;
    double purchasePrice, salePrice, netAmount, originalInvestment, totalFees;
    int sharesSold;

    cout << "How many shares did you sell? ";
    cin >> sharesSold;
    cout << "What was the sale price: $";
    cin >> salePrice;
    cout << "What was the purchase price: $";
    cin >> purchasePrice;

    originalInvestment = sharesSold * purchasePrice;
    totalFees = (sharesSold * salePrice) * BROKERAGE_FEE;
    netAmount = (sharesSold * salePrice) - totalFees;

    cout << fixed << showpoint << setprecision(2);

    cout << "Amount invested: $" << originalInvestment << endl;
    cout << "Service charges: $" << totalFees << endl;
    cout << "Profit / Loss: $" << netAmount - originalInvestment << endl;
    return 0;
}*/
