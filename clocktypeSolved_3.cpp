#include <iostream>
class clockType
{
public:
 void set_hour(int h);
 int get_hour();
 void set_minut(int m);
 int get_minut();
 void set_second(int s);
 int get_second();
 clockType() {};
 clockType(int h,int m,int s)
 {
 h = ((h < 0) ? 0 : (h > 23) ? 23 : h);
 m = ((m < 0) ? 0 : ( m> 59) ? 59 : m);
 s = ((s< 0) ? 0 : (s > 59) ? 59 : s);
 hour = h;
 minut = m;
 second = s;
 }
private:
 int hour{ 0 };
 int minut{ 0 };
 int second{ 0 };
};


inline void clockType::set_hour(int h)
{
 h = ((h < 0) ? 0 : (h > 23) ? 23 : h);
 hour = h;
}
inline void clockType::set_minut(int m)
{
 m = ((m < 0) ? 0 : (m > 59) ? 59 : m);
 minut = m;
}
inline void clockType::set_second(int s)
{
 s = ((s < 0) ? 0 : (s > 59) ? 59 : s);
 second = s;
}
inline int clockType::get_minut()
{
 return minut;
}
inline int clockType::get_second()
{
 return second;
}
inline int clockType::get_hour()
{
 return hour;
}


int main()
{
 // example test program
 // set time 22:54:12
 clockType test(22, 54, 12);
 std::cout << "Set time :" << test.get_hour() << "h" << test.get_minut() << "m" << test.get_second() << "s" << std::endl;
 // set time 18:18:54
 test.set_hour(18);
 test.set_minut(18);
 test.set_second(54);
 std::cout << "Set time :" << test.get_hour() << "h" << test.get_minut() << "m" << test.get_second() << "s" << std::endl;
 system("pause");
 return 0;
}
