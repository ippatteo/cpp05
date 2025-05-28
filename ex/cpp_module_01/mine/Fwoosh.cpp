#include "Fwoosh.hpp"

Fwoosh *Fwoosh::clone() const
{
	Fwoosh *obj = new Fwoosh;
	return(obj);
}

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}
Fwoosh::~Fwoosh()
{
	
}
