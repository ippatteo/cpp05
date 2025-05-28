#ifndef ATARGET_HPP
#define ATARGET_HPP
#include "Warlock.hpp"

class ASpell;

class ATarget
{
	private:
		std::string _type;
	public:
		const std::string &getType() const;
		virtual ATarget *clone() const = 0;
		ATarget (std::string type);
		virtual ~ATarget();
		void getHitBySpell(const ASpell &obj);
};


#endif