#ifndef DUMMY_HPP
#define DUMMY_HPP
#include "Warlock.hpp"

class Dummy : public ATarget
{
	public:
		virtual Dummy *clone() const;
		~Dummy();
		Dummy();
};

#endif