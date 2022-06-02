#include "App.h"
#include <string>
#include <iostream>
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"

using namespace std;

void App::BuildTree()
{
	string a, b;
	int c;
	cin >> a;
	this->SetName(a);
	while (true)
	{
		cin >> a;
		if (a == "endtree") break;
		if (a == "/") a = this->name;
		cin >> b >> c;
		if (this->GetName() == a)
		{
			if (c == 2) new Class2(this, b);
			if (c == 3) new Class3(this, b);
			if (c == 4) new Class4(this, b);
			if (c == 5) new Class5(this, b);
			if (c == 6) new Class6(this, b);
		}
		else
		{
			Base* temp = DirectWayPtr(a, true);
			if (temp != nullptr)
			{
				if (c == 2) new Class2(temp, b);
				if (c == 3) new Class3(temp, b);
				if (c == 4) new Class4(temp, b);
				if (c == 5) new Class5(temp, b);
				if (c == 6) new Class6(temp, b);
			}
			else
			{
				wrong = a;
				return;
			}
		}
	}
}
int App::Exe()
{
	cout << "Object tree" << endl;
	cout << this->GetName();
	ShowTree("");
	if (wrong != "")
	{
		cout << endl << "The head object " << wrong << " is not found";
		return 0;
	}
	string func, object;
	while (true)
	{
		cin >> func;
		if (func == "END") break;
		cin >> object;
		if (func == "SET") this->Set(object);
		if (func == "FIND") this->Find(object);
	}
	return 0;
}