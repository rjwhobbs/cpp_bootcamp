#include <iostream>
#include "Pony.hpp"

void ponyOnStack(void) 
{
	Pony pony("Joe");
	std::cout <<  pony.getName() << std::endl;
	pony.feedPony("Hamburger"); 
}

void ponyOnHeap(void)
{
	Pony* pony  = new Pony("Stuart");
	std::cout <<  pony->getName() << std::endl;
	pony->feedPony("Cheese");
	delete pony;
}

int main(void)
{
	ponyOnStack();
	ponyOnHeap();
	
	return 0;
}