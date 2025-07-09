#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooLowExeption::what() const throw()
{
	return("grade too low!\n");
}


const char* Bureaucrat::GradeTooHighExeption::what() const throw()
{
	return("grade too High!\n");
} 
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << _name << " has been fired!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << _name <<   " has been hired!" << std::endl;
	if (_grade < 1)
		throw(GradeTooHighExeption());
	else if (_grade > 150)
		throw(GradeTooLowExeption());

}

Bureaucrat::Bureaucrat(const Bureaucrat &ins): _name(ins._name), _grade(ins._grade)
{
	std::cout << "Bureaucrat " << ins.getName() << " has been copied!" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &ins)
{
	if (this != &ins)
	{
		this->_grade = ins.getGrade(); //const &b basta per fermare modifiche dirette agli attributi, ma per essere sicuro che non cambi nulla c++ si aspetta funzioni const
	}
	return *this;
}

std::ostream& operator << (std::ostream &out, Bureaucrat const &ins)
{
	out << ins.getName() << ", Bureaucrat grade " << ins.getGrade() << std::endl;
	return out;
}

void Bureaucrat::Promotion()
{
	if (_grade - 1 < 1)
		throw(GradeTooHighExeption());
	else
		_grade--;
}

void Bureaucrat::Demotion()
{
	if (_grade + 1 > 150)
		throw(GradeTooLowExeption());
	else
		_grade++;
}

void Bureaucrat::signForm(AForm &obj)
{
	
	try
	{
		obj.beSigned(*this);
		std::cout << this->_name << " signed form " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " couldn’t sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}