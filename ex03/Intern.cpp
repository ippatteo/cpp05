// Intern.cpp
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <map>
#include <iostream>

int Intern::resolveForm(const std::string& formName)
{
    static std::map<std::string,int> formMap;
    if (formMap.empty()) {
        formMap.insert(std::make_pair("shrubbery creation", FORM_ID_SHRUBBERY));
        formMap.insert(std::make_pair("robotomy request",    FORM_ID_ROBOTOMY));
        formMap.insert(std::make_pair("presidential pardon", FORM_ID_PARDON));
    }

    std::map<std::string,int>::const_iterator it = formMap.find(formName);
    return (it != formMap.end()) ? it->second : FORM_ID_UNKNOWN;
}

Intern::Intern()
{
}
Intern::Intern(const Intern&)
{
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    AForm* form = NULL;
    switch ( resolveForm(formName) )
    {
      case FORM_ID_SHRUBBERY:
        form = new ShrubberyCreationForm(target);
        break;
      case FORM_ID_ROBOTOMY:
        form = new RobotomyRequestForm(target);
        break;
      case FORM_ID_PARDON:
        form = new PresidentialPardonForm(target);
        break;
      default:
        std::cerr << "Intern error: \"" << formName
                  << "\" is not a valid form name" << std::endl;
        return NULL;
    }

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}
