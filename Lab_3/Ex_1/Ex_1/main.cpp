#include <iostream>
#include "Math.h"

using namespace std;

int main()
{
	cout << "---------------------------------------" << endl;
	cout << "45 + 65 =  " << Math::Add(45, 65) << endl;
	cout << "45 + 65 + 3 =  " << Math::Add(45, 65, 3) << endl;
	cout << "3.4 + 18.6 =  " << Math::Add(3.4, 18.6) << endl;
	cout << "3.4 + 18.6 + 5.55 =  " << Math::Add(3.4, 18.6, 5.55) << endl;
	
	cout << "45 * 65 =  " << Math::Mul(45, 65) << endl;
	cout << "45 * 65 * 3 =  " << Math::Mul(45, 65, 3) << endl;
	cout << "3.4 * 18.6 =  " << Math::Mul(3.4, 18.6) << endl;
	cout << "3.4 * 18.6 * 5.55 =  " << Math::Mul(3.4, 18.6, 5.55) << endl;

	cout << "10 + 20 + 13 + 10 + 5 = " << Math::Add(5, 10, 20, 13, 10, 5) << endl;
	cout << "\"Hello \" + \"World\" = " << "\""<< Math::Add("Hello ", "World") << "\"" << endl;
	cout << "---------------------------------------" << endl;
	
	return 0;
}