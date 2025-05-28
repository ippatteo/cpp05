/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:57:19 by orekabe           #+#    #+#             */
/*   Updated: 2025/05/28 14:19:57 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void    SpellBook::learnSpell(ASpell *obj)
{
    book[obj->getName()] = obj;
}

void    SpellBook::forgetSpell(std::string const &name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        book.erase(name);
}

ASpell    *SpellBook::createSpell(std::string const &name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        return (it->second->clone());
    return (NULL);
}















