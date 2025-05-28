
#ifndef FWOOSH_HPP
#define FWOOSH_HPP
#include "Warlock.hpp"

class Fwoosh : public ASpell
{
	public:
		virtual Fwoosh *clone() const;
		~Fwoosh();
		Fwoosh();
};

#endif