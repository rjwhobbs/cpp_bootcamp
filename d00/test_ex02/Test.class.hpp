#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP

class Test {
	public:

		typedef Test t;
		int y;

		Test(void);
		Test(int x);
		~Test(void);

		static int getNbInst(void);
	
	private:

		static int _nbInst;
};

#endif