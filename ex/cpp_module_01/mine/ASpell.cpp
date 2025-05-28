#include "ASpell.hpp"

ASpell::Aspell(std::string name, std::string effects): _name(name), _effects(effects)
{

}

const std::string &ASpell::getName() const
{
	return(_name);
}

const std::string &ASpell::getEffects() const
{
	return(_effects);
}
void ASpell::launch(const ATarget &obj)
{
	obj.getHitBySpell(*this);
}

