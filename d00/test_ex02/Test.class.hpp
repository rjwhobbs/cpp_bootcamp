#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP

class Test {
	public:

		typedef Test t;
		int y;
		int z;

		Test(void);
		Test(int x);
		Test(int x, int f);
		~Test(void);

		static int getNbInst(void);
	
	private:

		static int _nbInst;
};

#endif