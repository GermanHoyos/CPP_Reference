/**********************************
**   WHY USE TEMPLATES           ** 
**                               **
**                               **
**                               **
**********************************/
#include <iostream>

//not needed becuase of template...
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//not needed becuase of template...
void Swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// NOW the problem is what if i wanted to swap bools and floats and doubls... etc..
// Heres the solution! with generics
template<typename T> // or template<class Type>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int a=5, b=7;
    cout << a << " - " << b << endl;
    Swap(a, b);  // or Swap<int>(a,b);
    cout << a << " - " << b << endl;

    char c='c', d='d';
    cout << c << " - " << d << endl;
    Swap(c, d); // or Swap<char>(a,b);
    cout << c << " - " << d << endl;



    return 0;
}
