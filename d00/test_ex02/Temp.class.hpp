#ifndef _TEMP_CLASS_HPP_
#define _TEMP_CLASS_HPP_


template<class T>
class Temp {
	public:
	T a;
	T b;

	Temp(T i, T j) { // This allowed by 42!!!!! only incase of templates
		this->a = i;
		this->b = j;
	};
	// Temp(void);
	~Temp(void);
};

#endif