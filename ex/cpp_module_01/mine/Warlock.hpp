/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 20:54:05 by orekabe           #+#    #+#             */
/*   Updated: 2025/05/28 18:43:22 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"



class   Warlock
{
    private:
        std::string _name;
        std::string _title;
		std::map<std::string, ASpell *>_book;
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        const std::string &getName() const;
        const std::string &getTitle() const;
        void  setTitle(const std::string &title);
        void introduce() const;
		void learnSpell(ASpell *obj);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget &obj);
};

#endif