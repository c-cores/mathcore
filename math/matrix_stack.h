#pragma once

#include <math/matrix.h>
#include <vector>

using namespace core;

namespace core
{

template <class t, int s>
struct matrix_stack : vector<matrix<t, s, s> >
{
	matrix_stack()
	{
		vector<matrix<t, s, s> >::push_back(identity<t, s, s>());
		total = identity<t, s, s>();
		updated = true;
	}

	~matrix_stack()
	{

	}

	matrix<t, s, s> total;
	bool updated;

	matrix_stack<t, s> &operator=(matrix<t, s, s> m)
	{
		vector<matrix<t, s, s> >::clear();
		vector<matrix<t, s, s> >::push_back(m);
		total = m;
		updated = true;
		return *this;
	}

	matrix_stack<t, s> &operator+=(matrix<t, s, s> m)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() += m;
		return *this;
	}

	matrix_stack<t, s> &operator-=(matrix<t, s, s> m)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() += m;
		return *this;
	}

	matrix_stack<t, s> &operator*=(matrix<t, s, s> m)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() *= m;
		return *this;
	}

	matrix_stack<t, s> &operator/=(matrix<t, s, s> m)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() /= m;
		return *this;
	}

	matrix_stack<t, s> &operator+=(t v)
	{
		updated = false;
		return (vector<matrix<t, s, s> >::back() += v);
	}

	matrix_stack<t, s> &operator-=(t v)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() -= v;
		return *this;
	}

	matrix_stack<t, s> &operator*=(t v)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() *= v;
		return *this;
	}

	matrix_stack<t, s> &operator/=(t v)
	{
		updated = false;
		vector<matrix<t, s, s> >::back() /= v;
		return *this;
	}

	void push()
	{
		vector<matrix<t, s, s> >::push_back(identity<t, s, s>());
	}

	void drop()
	{
		updated = false;
		vector<matrix<t, s, s> >::drop_back();
	}

	void update()
	{
		total = identity<t, s, s>();
		for (int i = 0; i < vector<matrix<t, s, s> >::size(); i++)
			total *= vector<matrix<t, s, s> >::get(i);
		updated = true;
	}

	t *data()
	{
		if (!updated)
			update();

		return total.data();
	}

	matrix<t, s, s> value()
	{
		if (!updated)
			update();

		return total;
	}
};

}

