#include <iostream>
#include "App.h"

using namespace std;

int main()
{
	App obj(nullptr);
	obj.BuildTree();
	return obj.Exe();
}
