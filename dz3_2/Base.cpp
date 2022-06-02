#include "Base.h"
#include <iostream>
#include <string>

using namespace std;

Base::Base(Base* parent_ptr, string name)
{
	this->Parrent_ptr = parent_ptr;
	this->name = name;
	wrong = "";
	if (parent_ptr != nullptr) parent_ptr->child.push_back(this);
	else Current_obj = this;
}
void Base::SetName(string name)
{
	this->name = name;
}
string Base::GetName()
{
	return name;
}
void Base::ShowTree(string space)
{
	for (int i = 0; i < this->child.size(); i++)
	{
		cout << endl;
		if (child[i]->child.size() > 0)
		{
			cout << space + "    " << child[i]->GetName();
			((Base*)child[i])->ShowTree(space + "    ");
		}
		else
		{
			cout << space + "    " << child[i]->GetName();
		}
	}
}
Base* Base::FindPtr(string name, Base* ptr, bool fl)
{
	if (fl == false)
	{
		if (ptr != nullptr)
		{
			Base* temp;
			for (int i = 0; i < ptr->child.size(); i++)
			{
				temp = ptr->child[i];
				if (temp->GetName() == name) return temp;
				else if (temp->child.size() > 0)
				{
					if (FindPtr(name, temp) != nullptr)
					{
						return FindPtr(name, temp);
						break;
					}
				}
			}
			return nullptr;
		}
		return ptr;
	}
	else
	{
		for (int i = 0; i < ptr->child.size(); i++)
		{
			if (ptr->child[i]->GetName() == name) return ptr->child[i];;
		}
		return nullptr;
	}
}
Base* Base::DirectWayPtr(string directory, bool fl)
{
	string text = "";
	Base* temp = nullptr;
	
	if (directory == "/") return this;
	if (directory[0] == '/' && directory.size() == 2)
	{
		directory.erase(directory.begin());
		directory.erase(directory.begin());
		temp = FindPtr(directory, this);
		return temp;
	}
	if (directory[0] == '/' && directory[1] == '/')
	{
		directory.erase(directory.begin());
		directory.erase(directory.begin());
		temp = FindPtr(directory, this);
		return temp;
	}
	else
	{
		Base* temp2 = Current_obj;
		for (int i = 0; i < directory.size(); i++)
		{
			if (directory[i] == '/' || i == directory.size() - 1)
			{
				if (text != "")
				{
					if (directory[i] != '/') text += directory[i];
					temp2 = FindPtr(text, temp2, true);
					if (temp2 == nullptr)return temp2;
					if (i == directory.size() - 1) return temp2;
					text = "";
				}
			}
			else
			{
				text += directory[i];
			}
		}
		return nullptr;
	}
}
void Base::Set(string name)
{
	if (DirectWayPtr(name) != nullptr)
	{
		Current_obj = DirectWayPtr(name);
		cout << endl << "Object is set: " << this->Current_obj->GetName();
	}
	else
	{
		cout << endl << "Object is not found: " << name;
	}
}
void Base::Find(string directory)
{
	cout << endl << directory << "     ";
	if (directory != ".")
	{
		Base* temp = DirectWayPtr(directory);
		if (temp != nullptr)
			cout << "Object name: " << temp->GetName();
		else cout << "Object is not found";
	}
	else
		cout << "Object name: " << Current_obj->GetName();
}
