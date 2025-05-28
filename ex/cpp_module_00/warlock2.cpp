#include "warlock2.hpp"

std::string &Warlock2::getName() const
{
	return(this->_title);
}

const std::string &Warlock2::getTitle() const
{
	return(_title);
}

void setTitle(cont std::string &title)
{
	this->_title = title;
}

Warlock2::Warlock2(std::string name, std::string title): _name(name),  _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock2::~Warlock2()
{
	std::cout << _name << ": My job here is done!\n";
}

void Warlock2::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}
