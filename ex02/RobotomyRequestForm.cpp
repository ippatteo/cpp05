#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 145, 137),  _target(target)
{

}
void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << "form is not signed!\n";
		return;
	}
	try
	{
		this->executable(executor);
		if (rand() % 2)
			std::cout<<"The robotomy was failure you're now a cow 🐄"<<std::endl;
		else
			std::cout<<"The robotomy was a success you're ready to go"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "this form is not executable by " << executor.getName() << ": " << e.what() << '\n';
	}
}

