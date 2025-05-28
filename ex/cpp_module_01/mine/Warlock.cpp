/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:53:56 by orekabe           #+#    #+#             */
/*   Updated: 2025/05/28 20:00:46 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title)
{
    _name = name;
    _title = title;
    std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!\n";
}

const std::string &Warlock::getName() const
{
    return (_name);
}

const std::string &Warlock::getTitle() const
{
    return (_title);
}

void  Warlock::setTitle(const std::string &title)
{
    _title = title;
}

void Warlock::introduce() const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *obj)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(obj->getName());
	if (it == _book.end())
		_book[obj->getName()] = obj;
}
void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(name);
	if (it != _book.end())
		_book.erase(name);
}

void Warlock::launchSpell(std::string name, ATarget &obj)
{
	std::map<std::string, ASpell *>::iterator it = _book.find(name);
	if (it != _book.end())
		_book[name]->launch(obj);
}