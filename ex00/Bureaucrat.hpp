#ifndef BUREAUCRAT_HPP
  #define BUREAUCRAT_HPP

	#include <string>
	#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		~Bureaucrat();
		Bureaucrat(const std::string grade, int name); // const costringe a usare una lista di inizializzazione, piu pulita
		Bureaucrat(const Bureaucrat &ins);
		Bureaucrat& operator = (const Bureaucrat &ins); //equal op overload
	class GradeTooHighExeption : public std::exception //public per ereditare tutto la exeption class
	{
			public:
			const char* what() const throw() //si scvrive cosi perche dichiarato cosi in exeption, stiamo facendo un override
			{
				return("Grade too hight!\n");
			}
	};
	class GradeTooLowExeption : public std::exception
	{
			public:
			const char* what() const throw()
			{
				return("grade too low!\n");
			}
	};
	int getGrade() const; //per esser chiamata in una funzione const bureaucrat &b
	std::string getName() const;
	void Promotion();
	void Demotion();
};

std::ostream &operator <<(std::ostream &out, const Bureaucrat &ins); // fuori perché il primo operando implicito se fosse in una classe sarebbe della classe stessa, ma in questo caso è &out
#endif