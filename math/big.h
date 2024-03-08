#pragma once

#include <vector>
#include <iostream>

using namespace std;

namespace core
{

struct Integer
{
	Integer();
	Integer(int i);
	Integer(unsigned int i);
	Integer(long i);
	Integer(unsigned long i);
	Integer(long long i);
	Integer(unsigned long long i);
	Integer(float i);
	Integer(double i);
	Integer(const char *s);
	~Integer();

	int sign;
	std::vector<int> data;

	static Integer rand(int width);
	
	operator double();

	template <class t>
	operator t()
	{
		return (t)((double)*this);
	}

	int size();

	Integer &operator=(Integer i);

	Integer &operator+=(Integer i);
	Integer &operator-=(Integer i);
	Integer &operator*=(Integer i);
	Integer &operator/=(Integer i);
	Integer &operator%=(Integer i);
	Integer &operator&=(Integer i);
	Integer &operator|=(Integer i);
	Integer &operator^=(Integer i);
	Integer &operator<<=(Integer i);
	Integer &operator>>=(Integer i);
};

ostream &operator<<(ostream &f, Integer i);

Integer operator-(Integer i);

Integer operator+(Integer i1, Integer i2);
Integer operator-(Integer i1, Integer i2);
Integer operator*(Integer i1, Integer i2);
Integer operator/(Integer i1, Integer i2);
Integer operator%(Integer i1, Integer i2);
Integer operator&(Integer i1, Integer i2);
Integer operator|(Integer i1, Integer i2);
Integer operator^(Integer i1, Integer i2);
Integer operator>>(Integer i1, int i2);
Integer operator<<(Integer i1, int i2);

bool operator==(Integer i1, Integer i2);
bool operator!=(Integer i1, Integer i2);
bool operator>(Integer i1, Integer i2);
bool operator<(Integer i1, Integer i2);
bool operator>=(Integer i1, Integer i2);
bool operator<=(Integer i1, Integer i2);

Integer abs(Integer i);
Integer pow(Integer i, int p);
Integer sqrt(Integer i);
Integer root(Integer i, int r);

struct Real
{
	Real();
	Real(int f);
	Real(unsigned int f);
	Real(long long f);
	Real(unsigned long long f);
	Real(float f);
	Real(double f);
	~Real();

	int exp;
	int limit;
	Integer num;

	operator double();

	template <class t>
	operator t()
	{
		return (t)((double)*this);
	}

	void realign();

	Real &operator=(Real f);

	Real &operator=(double f);

	Real &operator+=(Real f);
	Real &operator-=(Real f);
	Real &operator*=(Real f);
	Real &operator/=(Real f);
};

ostream &operator<< (ostream &fin, Real f);

Real operator-(Real f);

Real operator+(Real f1, Real f2);
Real operator-(Real f1, Real f2);
Real operator*(Real f1, Real f2);
Real operator/(Real f1, Real f2);

bool operator==(Real f1, Real f2);
bool operator!=(Real f1, Real f2);
bool operator>(Real f1, Real f2);
bool operator<(Real f1, Real f2);
bool operator>=(Real f1, Real f2);
bool operator<=(Real f1, Real f2);

Real abs(Real f);
Real pow(Real f, int p);
Real sqrt(Real f);
Real root(Real f, int r);

}

