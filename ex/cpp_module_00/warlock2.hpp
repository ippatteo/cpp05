#ifndef WARLOCK2_HPP
	#define WARLOCK2_HPP

#include <iostream>
#include <string>

class Warlock2
{
	private:
	std::string _name;
	std::string _title;
	public:
	std::string &getName() const;
	std::string &getTitle() const;
	void setTitle(const std::string &title);
	Warlock2(std::string name, std::string title);
	~Warlock2();
	void introduce() const;
};
#endif