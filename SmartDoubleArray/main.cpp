#include <iostream>
#include "SmartDoubleArray.h"

using namespace std;
using namespace MyArray;

int main()
{

    SmartDoubleArray<char> a2;
    a2.add('a');
    a2.add('d');
    a2.add('f');
    a2.add('t');
    a2.add('m');
	a2.remove(1);
	
	char a = a2[2];
	cout << "Overload ["<<2<<"] :" << a << endl;
	cout << a2 << endl;

	SmartDoubleArray<int> a3;
    a3.add(4);
    a3.add(777);
    a3.add(3277);
    a3.add(88);
	cout << a3 << endl;
	a3.insert(2, 1);
	cout << a3 << endl;
	cout << "Size: " << a3.getSize() << endl;



	SmartDoubleArray<double> a4;
	a4.add(3.3);
	a4.add(5.3);
	a4.add(1.44);
	a4.add(7.54);
	a4.add(34.5);
	cout << a4 << endl;
	a4.remove(1);
	cout << a4 << endl;


    cin.get();
    cin.get();

}