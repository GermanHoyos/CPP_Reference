    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>
    using namespace std;

int main()
{
    int score;
    int range1 = 0, range2 = 0, range3 = 0,
        range4 = 0, range5 = 0, range6 = 0,
        range7 = 0, range8 = 0;

    ifstream inData;

    inData.open("Ch8_Ex4Data.txt");

    while(inData >> score) {
        if (score <= 25){
            range1++;
        } else if (score >= 25 && score <= 49) {
            range2++;
        } else if (score >= 50 && score <= 74) {
            range3++;
        } else if (score >= 75 && score <= 99) {
            range4++;
        } else if (score >= 100 && score <= 124) {
            range5++;
        } else if (score >= 125 && score <= 149) {
            range6++;
        } else if (score >= 150 && score <= 174) {
            range7++;
        } else if (score >= 175 && score <= 200) {
            range8++;
        } else {
            //null
        }
     }

     cout << "0 - 24 "    << range1++ <<  endl;
     cout << "25 - 49 "   << range2++ <<  endl;
     cout << "50 - 74 "   << range3++ <<  endl;
     cout << "75 - 99 "   << range4++ <<  endl;
     cout << "100 - 124 " << range5++ <<  endl;
     cout << "125 - 149 " << range6++ <<  endl;
     cout << "150 - 174 " << range7++ <<  endl;
     cout << "175 - 200 " << range8++ <<  endl;

     inData.close();

  return 0;
}
