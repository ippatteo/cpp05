#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137),  _target(target)
{

}
void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << "form is not signed!\n";
		return;
	}
	try
	{
		this->executable(executor);
		std::cout<<"mr "<<this->_target <<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "this form is not executable by " << executor.getName() << ": " << e.what() << '\n';
	}
}

