#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

#define FORM_ID_UNKNOWN    0
#define FORM_ID_SHRUBBERY  1
#define FORM_ID_ROBOTOMY   2
#define FORM_ID_PARDON     3

class Intern {
public:
    Intern();
    Intern(const Intern&);
    ~Intern();
    Intern& operator=(const Intern&);

    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    static int resolveForm(const std::string& formName);
};

#endif
