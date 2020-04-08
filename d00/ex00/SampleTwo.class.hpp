#ifndef SAMPLETWO_CLASS_H
# define SAMPLETWO_CLASS_H

class SampleTwo {
	private:
	int _foo;

	public:
	SampleTwo(int foo);
	~SampleTwo();

	int bar;

	int getFoo(void) const;
	int compare(SampleTwo* other) const;
};

#endif
