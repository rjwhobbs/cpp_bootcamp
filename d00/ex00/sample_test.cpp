#include <iostream>
#include "Sample.class.hpp"
#include "SampleTwo.class.hpp"

// void test3(SampleTwo*** obj) {
// 	std::cout << (**obj)->bar << std::endl;
// 	(**obj)->bar = 9000;

// 	return ;
// }

// void test2(SampleTwo** obj) {
// 	std::cout << (*obj)->bar << std::endl;
// 	(*obj)->bar = 147;
// 	test3(&obj);
// 	return ;
// }

// void test(SampleTwo* obj) {
// 	std::cout << obj->bar << std::endl;
// 	obj->bar = 93;
// 	test2(&obj);

// 	return ;
// }

int main(void) {
	Sample sample(7, 'y', 2.3);
	std::cout << sample.i << sample.c << sample.f << std::endl;
	sample.i = 42;
	std::cout << sample.i << std::endl;
	std::cout << sample.getj() << std::endl;
	sample.bar();
	// SampleTwo sample(7);
	// SampleTwo sampleTwo(7);

	// if (sample.compare(&sampleTwo) == 0) {
	// 	std::cout << "Yo" << std::endl;
	// }	else {
	// 	std::cout << "No" << std::endl;
	// }

	return 0;
}