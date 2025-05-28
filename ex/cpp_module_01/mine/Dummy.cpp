#include "Dummy.hpp"

Dummy *Dummy::clone() const
{
	Dummy *obj = new Dummy;
	return(obj);
}

Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}
Dummy::~Dummy()
{

}