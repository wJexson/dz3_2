#ifndef _APP_H
#define _APP_H

#include "Base.h"

class App : public Base
{
public:
	App(Base* oldParent_tpr, string name = "") : Base(oldParent_tpr, name)
	{};
	void BuildTree();
	int Exe();
};

#endif