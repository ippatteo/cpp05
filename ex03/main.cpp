#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::cout << "=== Testing Bureaucrat operator<< ===" << std::endl;
    try {
        Bureaucrat high("HighGrade", 1);
        Bureaucrat low("LowGrade", 150);
        std::cout << high << std::endl;
        std::cout << low << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing AForm operator<< on derived forms ===" << std::endl;
    try {
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Trillian");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        // Sign forms to change their state
        Bureaucrat signer("Signer", 1);
        shrub.beSigned(signer);
        robot.beSigned(signer);
        pardon.beSigned(signer);

        std::cout << "\nAfter signing:" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
