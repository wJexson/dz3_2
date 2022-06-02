#ifndef _Class4_H
#define _Class4_H
#include "Base.h"

class Class4 : public Base
{
public:
	Class4(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif