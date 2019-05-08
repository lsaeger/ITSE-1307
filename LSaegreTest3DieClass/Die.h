#pragma once
#include  <random>
#include <time.h>

class Die
{
public:
	Die();
	Die(int intpSides);
	~Die();
private:
	int intSides;
	int intValue;
	void setSides(int intpSides);
public:
	int roll();
	int get();
};

