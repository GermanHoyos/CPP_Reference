//include statement(s)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

//using namespace statement
using namespace std;

int main()
{

int xount = 1;
int num = 25;
while (xount < 25)
{
  num = num - 1;
  xount++;
}
cout << xount << " " << num << endl;

 return 0;
}

/*
double sroot;

int num = 101;
sroot = sqrt(num);

cout << fixed << showpoint;
cout << setprecision(3);
cout << sroot;


return 0;
}


/*
//variable declaration

  int a, b, c, average;
  int x, y, z, sum, answer;

  a = 125;
  b = 28;
  c = -25;
  x = 33;
  y = 10;
  z = 3;

//executable statements
  average = (a + b + c)/3;
  cout << "average of a, b and c is "<< average <<"\n";

  sum = x + y + z;
  cout << "sum of x, y and z is " << sum <<"\n";

  answer =  a + b;
  //cout << answer <<"\n";

  std::string str ("computer science");
  std::cout << "The size of str is " << str.length() << " bytes.\n";

  cout << x/y <<"\n";

  cout << static_cast<int>(6.9) + static_cast<int>(7.9) <<" in static \n";

  cout << static_cast<int>(9.9) <<" in static \n";

//equiv examples
    // x = x+5   OR   x += 5
    // x = 2 * x * y   OR  x *= 2 *y
    // totalPay = totalPay + currentPay;  OR  totalPay += currentPay;
    // z = z * x + 2 * z  OR  z *= (x + 2);
    // y = y / (x + 5) or y /= x + 5;



int x; double y; char ch;
cin >> x >> ch >> y;
cout << x << ch << y;



double x, y, z;
x = 55.68;
y = 476.859;
z = 23.8216;
cout << fixed << showpoint;
cout << setprecision(3);
cout << x << ' ' << y << ' ' << setprecision(2) << z << endl;



char ch1, ch2;
int alpha;
//cin.ignore();
cin.get(ch1);
cin.get(ch2);
cin >> alpha;
cout << ch1 << " " << ch2 << " " << alpha;



int alpha, beta, gamma;
cin >> alpha;
cin.ignore(100, '\n');
cin >> beta;
cin.ignore(100,'\n');
cin >> gamma;
cout << gamma;


char ch1, ch2;
cin.get(ch1);
cin.putback(ch1);
cin >> ch2;

cout << ch2;


int count = 1;
int num = 25;
while (count < 25)
{
  num = num - 1;
  count++;
}
cout << count << " " << num << endl;


int x = 5;
int y = 30;

do{x = x * 2;} while (x < y);
cout << x;


int num = 10;

while (num > 10){num = num - 2;}
cout << num << endl;
*/
