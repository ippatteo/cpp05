#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) , _target(target)
{

}
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned() == false)
	{
		std::cout << "form is not signed!\n";
		return;
	}
	try
	{
		std::string nameFile;
		const char* trueNameFile;
		this->executable(executor);
		nameFile = this->_target + "_shruberry";
		trueNameFile = nameFile.c_str();
		std::ofstream file(trueNameFile);
			if (file.is_open())
			{
				file <<"          .     .  .   ^^^    .          .         "<<std::endl;
				file <<"          .     .  .  ^^^^^    .          .         "<<std::endl;
				file <<"          .     .  .^^^^^^^^^^   .          .         "<<std::endl;
				file <<"          .     .  .   ^^^    .          .         "<<std::endl;
				file <<"          .     .  .   ^^^    .          .         "<<std::endl;
				
				file.close();
			}
			else
				std::cout<<"Error the file can't be opened"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "this form is not executable by " << executor.getName() << ": " << e.what() << '\n';
	}
}

