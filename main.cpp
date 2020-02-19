#include <iostream>
#include <conio.h>
//first git commit
using namespace std;

class RatNum {
public :
    int num;
    int denum;


    RatNum (int n, int d) {
	   try { num = n;
             denum = d;
	    if (d == 0){

        throw 823;
    }
}
	catch(int a) {
		cout << a;
		exit(EXIT_FAILURE);
	}
    }

    RatNum (){
	    num  = 0 ;
	    denum = 1;
    }





    RatNum socr (RatNum &x)//Сокращение дроби
	{
		int zn = 1;
		if (x.num < 0)
			zn = -1;
		for (int i = 2; i <= zn*x.num; i++)
			if (!(x.num%i) && !(x.denum%i))
			{
				x.num /= i;
				x.denum /= i;
				return socr(x);
			}
		return x;
	}



 friend bool operator + (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum + x.denum*y.num;
}
 friend bool operator - (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum - x.denum*y.num;
}
friend bool operator * (const RatNum &x, const RatNum &y)
{
    return x.num*y.num * x.denum*y.denum;
}
friend bool operator / (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum / x.denum*y.num;
}





    friend bool operator > (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum > x.denum*y.num;
}

	friend bool operator < (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum < x.denum*y.num;
}

	friend operator == (const RatNum &x, const RatNum &y)
{
    return x.num*y.denum == x.denum*y.num;
}

};



ostream& operator<<(ostream& stream, const RatNum& rt) {
    if (rt.num > rt.denum) {
    	stream <<  rt.num / rt.denum << " " << rt.num % rt.denum << "/" << rt.denum << " " << "\n";
    } else
	    stream <<  rt.num << "/" << rt.denum << " " << "\n";
    return stream;
}

istream& operator>>(istream& stream, RatNum& rt) {
    stream >> rt.num >> rt.denum;
    return stream;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    RatNum n, d, c;

    cout << "Введите 2 числа :";
    cin >> n >> d;

    int routnumber;
    do {

        cout << "1. Сложение" << endl;
        cout << "2. Вычитание" << endl;
        cout << "3. Умножение" << endl;
        cout << "4. Деление" << endl;
        cout << "0. Выход" << endl;
        cin >> routnumber;

switch (routnumber){

     case 1 :
     cout << n+d;
     break;

     case 2 :
     cout << n-d;
     break;

     case 3 :
     cout << n*d;
     break;

     case 4 :
     cout << n/d;
     break;}

} while (routnumber != 0);

    getch();
    return 0;
}

