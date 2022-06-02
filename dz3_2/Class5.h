#ifndef _Class5_H
#define _Class5_H
#include "Base.h"

class Class5 : public Base
{
public:
	Class5(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif