#ifndef _Base_H
#define _Base_H

#include <string>
#include <vector>

using namespace std;

class Base
{
protected:
	string wrong;
	string name;
	Base* Parrent_ptr;
	Base* Current_obj;
public:
	Base(Base* parent_ptr, string name = "");
	void SetName(string name);
	string GetName();
	void ShowTree(string space);
	vector <Base*> child;
	Base* FindPtr(string name, Base* ptr = nullptr, bool fl = false);
	Base* DirectWayPtr(string directory, bool fl = false);
	void Set(string name);
	void Find(string directory);
};

#endif