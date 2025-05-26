#include "Bureaucrat.hpp"
// :: if to acess static class level operations, . is for objecxt level operations
int main()
{
	Bureaucrat	a("FOO", 4);
	Bureaucrat	b("BAR", 148);
	Bureaucrat	d("cioa", 148);
	std::cout << d.getName() << std::endl;
	d = b;
	std::cout << d.getName() << std::endl;

	a.Promotion();
	a.Promotion();
	a.Promotion();
	b.Demotion();
	b.Demotion();
	Bureaucrat  c("Test", 150);
	try
	{
		a.Promotion();
	}
	catch (const std::exception &e) // const assicura what sia chiamato correttamente what, funziona anche senz ma é una best bractice, se ci fossero stati piu metodi in exeption vrei potuto modificarli
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		b.Demotion();
	}
	catch (const  std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat  d("Pippo", 0);
	}
	catch (const Bureaucrat::GradeTooHighExeption& e)
	{
		std::cerr << "Exception grade too high catched: Pippo " << e.what() << std::endl;
	}
	try
	{
		c.Demotion();
	}
	catch (const Bureaucrat::GradeTooHighExeption& e)
	{
		std::cerr << "Exception grade too high catched: " << c.getName() << " " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowExeption& e)
	{
		std::cerr << "Exception grade too low catched: " << c.getName() << " " << e.what() << std::endl;
	}
	return (0);
}
