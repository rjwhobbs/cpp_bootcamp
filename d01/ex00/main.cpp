#include "Pony.hpp"

void ponyOnStack(void) 
{
	Pony pony("Joe");
	pony.getName();
}

void ponyOnHeap(void)
{
	Pony* pony  = new Pony("Stuart");
	pony->getName(); 
	delete pony;
}

int main(void)
{
	ponyOnStack();
	ponyOnHeap();
	
	return 0;
}