#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0)); // Seed random number generator
    
    std::cout << "=== TESTING FORM CREATION ===" << std::endl;
    
    try
    {
        // Create bureaucrats with different grades
        Bureaucrat highGrade("Alice", 1);
        Bureaucrat midGrade("Bob", 50);
        Bureaucrat lowGrade("Charlie", 150);
        
        std::cout << highGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << lowGrade << std::endl;
        
        // Create forms
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("target1");
        PresidentialPardonForm pardon("criminal");
        
        std::cout << "\n=== TESTING FORM SIGNING ===" << std::endl;
        
        // Test signing forms
        highGrade.signForm(shrub);
        midGrade.signForm(robot);
        lowGrade.signForm(pardon); // Should fail
        
        std::cout << "\n=== TESTING FORM EXECUTION ===" << std::endl;
        
        // Test executing signed forms
        std::cout << "Executing Shrubbery Form:" << std::endl;
        shrub.execute(highGrade);
        
        std::cout << "\nExecuting Robotomy Form:" << std::endl;
        robot.execute(midGrade);
        
        std::cout << "\nExecuting Presidential Pardon (unsigned):" << std::endl;
        pardon.execute(highGrade); // Should fail because not signed
        
        // Sign and execute pardon
        std::cout << "\nSigning and executing Presidential Pardon:" << std::endl;
        highGrade.signForm(pardon);
        pardon.execute(highGrade);
        
        std::cout << "\n=== TESTING EXECUTION WITH INSUFFICIENT GRADE ===" << std::endl;
        
        // Try to execute with insufficient grade
        try
        {
            shrub.execute(lowGrade); // Should throw exception
        }
        catch(const std::exception& e)
        {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        std::cout << "\n=== TESTING MULTIPLE ROBOTOMY ATTEMPTS ===" << std::endl;
        
        // Test robotomy randomness (C++98 compatible)
        for (int i = 0; i < 5; i++)
        {
            std::stringstream ss;
            ss << "test" << i;
            RobotomyRequestForm robotTest(ss.str());
            highGrade.signForm(robotTest);
            robotTest.execute(highGrade);
        }
        
        std::cout << "\n=== TESTING EDGE CASES ===" << std::endl;
        
        // Test unsigned form execution
        ShrubberyCreationForm unsignedShrub("unsigned");
        std::cout << "Trying to execute unsigned form:" << std::endl;
        unsignedShrub.execute(highGrade);
        
        // Test different form types with same bureaucrat
        std::cout << "\nTesting different forms with high grade bureaucrat:" << std::endl;
        ShrubberyCreationForm shrub2("test_garden");
        RobotomyRequestForm robot2("test_robot");
        PresidentialPardonForm pardon2("test_criminal");
        
        highGrade.signForm(shrub2);
        highGrade.signForm(robot2);
        highGrade.signForm(pardon2);
        
        shrub2.execute(highGrade);
        robot2.execute(highGrade);
        pardon2.execute(highGrade);
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}