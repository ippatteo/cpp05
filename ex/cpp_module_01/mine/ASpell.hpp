#ifndef ASPELL_HPP
#define ASPELL_HPP
#include "Warlock.hpp"

class ASpell
{
	private:
		std::string _name;
		std::string _effects;
	public:
		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual ASpell *clone() const = 0;
		ASpell (std::string name, std::string effects);
		virtual ~ASpell();
		void launch(const ATarget &obj);
};
#endif