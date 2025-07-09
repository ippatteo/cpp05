#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0)); // Seed random number generator
    
    std::cout << "=== TESTING INTERN CLASS ===" << std::endl;
    
    try
    {
        // Create bureaucrats and intern
        Bureaucrat highGrade("Alice", 1);
        Bureaucrat midGrade("Bob", 50);
        Intern someRandomIntern;
        
        std::cout << highGrade << std::endl;
        std::cout << midGrade << std::endl;
        
        std::cout << "\n=== TESTING INTERN FORM CREATION ===" << std::endl;
        
        // Test creating valid forms
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "garden");
        AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "criminal");
        
        std::cout << "\n=== TESTING CREATED FORMS ===" << std::endl;
        
        if (shrubForm)
        {
            std::cout << *shrubForm << std::endl;
            highGrade.signForm(*shrubForm);
            shrubForm->execute(highGrade);
        }
        
        if (robotForm)
        {
            std::cout << *robotForm << std::endl;
            midGrade.signForm(*robotForm);
            robotForm->execute(midGrade);
        }
        
        if (pardonForm)
        {
            std::cout << *pardonForm << std::endl;
            highGrade.signForm(*pardonForm);
            pardonForm->execute(highGrade);
        }
        
        std::cout << "\n=== TESTING INVALID FORM NAMES ===" << std::endl;
        
        // Test creating invalid forms
        AForm* invalidForm1 = someRandomIntern.makeForm("invalid form", "target");
        AForm* invalidForm2 = someRandomIntern.makeForm("wrong name", "another target");
        AForm* invalidForm3 = someRandomIntern.makeForm("", "empty name");
        
        if (!invalidForm1)
            std::cout << "Correctly returned NULL for invalid form 1" << std::endl;
        if (!invalidForm2)
            std::cout << "Correctly returned NULL for invalid form 2" << std::endl;
        if (!invalidForm3)
            std::cout << "Correctly returned NULL for empty form name" << std::endl;
        
        std::cout << "\n=== TESTING MULTIPLE INTERNS ===" << std::endl;
        
        // Test multiple interns
        Intern intern1;
        Intern intern2;
        Intern intern3(intern1); // Copy constructor
        intern2 = intern1;       // Assignment operator
        
        AForm* form1 = intern1.makeForm("shrubbery creation", "forest");
        AForm* form2 = intern2.makeForm("robotomy request", "target2");
        AForm* form3 = intern3.makeForm("presidential pardon", "prisoner");
        
        std::cout << "\n=== TESTING FORM EXECUTION WITH DIFFERENT GRADES ===" << std::endl;
        
        if (form1)
        {
            highGrade.signForm(*form1);
            form1->execute(highGrade);
        }
        
        if (form2)
        {
            try
            {
                midGrade.signForm(*form2);
                form2->execute(midGrade);
            }
            catch(const std::exception& e)
            {
                std::cout << "Exception: " << e.what() << std::endl;
            }
        }
        
        if (form3)
        {
            highGrade.signForm(*form3);
            form3->execute(highGrade);
        }
        
        std::cout << "\n=== TESTING CASE SENSITIVITY ===" << std::endl;
        
        // Test case sensitivity
        AForm* caseTest1 = someRandomIntern.makeForm("Shrubbery Creation", "test");
        AForm* caseTest2 = someRandomIntern.makeForm("ROBOTOMY REQUEST", "test");
        AForm* caseTest3 = someRandomIntern.makeForm("Presidential Pardon", "test");
        
        if (!caseTest1)
            std::cout << "Case sensitivity test 1 passed (NULL returned)" << std::endl;
        if (!caseTest2)
            std::cout << "Case sensitivity test 2 passed (NULL returned)" << std::endl;
        if (!caseTest3)
            std::cout << "Case sensitivity test 3 passed (NULL returned)" << std::endl;
        
        std::cout << "\n=== TESTING MULTIPLE FORMS OF SAME TYPE ===" << std::endl;
        
        // Create multiple forms of the same type
        for (int i = 0; i < 3; i++)
        {
            std::cout << "\n--- Creating robotomy form " << i + 1 << " ---" << std::endl;
            AForm* robotTest = someRandomIntern.makeForm("robotomy request", "robot_target");
            if (robotTest)
            {
                highGrade.signForm(*robotTest);
                robotTest->execute(highGrade);
                delete robotTest;
            }
        }
        
        // Clean up dynamically allocated forms
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
        delete form1;
        delete form2;
        delete form3;
        
        std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}