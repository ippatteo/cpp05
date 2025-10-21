# cpp05

C++ exercises - Exceptions, Inheritance, and Forms (42 school)

## Project Structure

- **ex00**: Bureaucrat
  - Implementation of the `Bureaucrat` class with exception handling.
- **ex01**: Form
  - Introduction of the `Form` class and interaction with `Bureaucrat`.
- **ex02**: AForm & Derived Forms
  - Abstract class `AForm` and implementation of specific forms (`PresidentialPardonForm`, `RobotomyRequestForm`, `ShrubberyCreationForm`).
- **ex03**: Intern
  - `Intern` class for dynamic form creation via string.

Each exercise contains:
- Source and header files for the classes
- `main.cpp` to test functionalities
- `Makefile` for compilation

## Compilation

To compile each exercise:

```sh
cd ex00 && make
cd ex01 && make
cd ex02 && make
cd ex03 && make
```

## Execution

Each executable is in its respective folder. Example:

```sh
./ex00/bureaucrat
./ex01/form
./ex02/aform
./ex03/intern
```

## Author
Project developed for 42 school.
