#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "MyString.h"
#include<string>
using namespace std;




void test(BitString str)
{
	cout << str << endl;
}


void main()
{
	setlocale(0, "");
	/*String name;*/
	//String name2;
	//String ourName;
	//

	//char* buff = new char[20];
	//buff[0] = 'A';
	//buff[1] = '\0';
	//cin >> name >> name2;

	//char buffer[] = "hello World";

	//ourName += name + buff/* + name2*/;
	//cout << ourName/* + buff*/;


	//cin >> name;
	//StringBuilder tmp(name);
	//tmp.Append(name);
	//tmp.Print();
	//cout << "\n\n\n";


	//String res = tmp.ToString();

	//cout << res;

	

	//tmp = str;
	/*test(str);*/

	BitString str1("0110111");
	BitString str2("10111");
	
	/*cout << " ==: " << (str1 == str2) << endl;
	cout << " !=: " << (str1 != str2) << endl << endl;
	cout << str1.c_str() <<  " to decimal: "<< str1.to_decimal() << endl;*/


	cout << (str1 += str2);




}



