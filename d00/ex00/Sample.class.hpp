#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class Sample {
	public:
	Sample(int i, char c, float f);
	~Sample(void);

	int i;
	char c;
	float const f;

	void bar(void) const;

	private:

	int _j;

	void _pbar(void) const;
};

#endif