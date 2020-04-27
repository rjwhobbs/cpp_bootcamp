#ifndef SAMTHREE_CLASS_H
# define SAMTHREE_CLASS_H

class SamThree {
	private:
	int static _foo;

	public:
	SamThree();
	~SamThree();

	static int 	getFoo(void);
};

#endif