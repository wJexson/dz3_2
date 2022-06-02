#ifndef _Class6_H
#define _Class6_H
#include "Base.h"

class Class6 : public Base
{
public:
	Class6(Base* ptr, string name = "") : Base(ptr, name) {};
};

#endif