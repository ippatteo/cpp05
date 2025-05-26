#ifndef FORM_HPP
	#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exe_grade;
	public:
	Form(std::string name, bool is_sign, int sign, int exe);
	Form(const Form &obj);
	Form &operator =(const Form &obj);
	~Form();
	std::string getName();
	bool getSigned();
	int getSignGrade();
	int getExeGrade();
	void beSigned(const Bureaucrat &ins);
	class GradeTooLowExeption : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade too low\n");
		}
	};
	class GradeTooHighExeption : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Grade too high\n");
		}
	};

};

std::ostream &operator <<(std::ostream &out, const Form &obj);
#endif