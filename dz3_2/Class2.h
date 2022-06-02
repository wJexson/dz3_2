#ifndef _Class2_H
#define _Class2_H
#include "Base.h"

class Class2 : public Base
{
public:
	Class2(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif