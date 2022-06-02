#ifndef _Class3_H
#define _Class3_H
#include "Base.h"

class Class3 : public Base
{
public:
	Class3(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif