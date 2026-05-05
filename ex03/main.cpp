/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:43:46 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/10 12:43:48 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Creamos un Intern (el becario que puede crear formularios)
	Intern intern;

	// Creamos un Bureaucrat de máximo rango (puede firmar y ejecutar cualquier formulario)
	Bureaucrat ceo("CEO", 1);

	
	// Test 1. El Intern crea un RobotomyRequestForm
	std::cout << "TEST 1:" << std::endl;
	AForm *form1 = intern.makeForm("robotomy request", "Bender");
	if (form1)
	{
		ceo.signForm(*form1);
		ceo.executeForm(*form1);
		delete form1;
	}


	// Test 2. El Intern intenta crear un formulario desconocido
	std::cout << "\nTEST 2:" << std::endl;
	AForm *form2 = intern.makeForm("unknown form", "Target");
	if (!form2)
	{
		std::cout << "Form2 is NULL" << std::endl;
	}

	// Test 3. El Intern crea un ShrubberyCreationForm
	std::cout << "\nTEST 3:" << std::endl;
	AForm *form3 = intern.makeForm("shrubbery creation", "garden");
	if (form3)
	{
		ceo.signForm(*form3);
		ceo.executeForm(*form3);
		delete form3;
	}

	// Test 4. El Intern crea un PresidentialPardonForm
	std::cout << "\nTEST 4:" << std::endl;
	AForm *form4 = intern.makeForm("presidential pardon", "Zoidberg");
	if (form4)
	{
		ceo.signForm(*form4);
		ceo.executeForm(*form4);
		delete form4;
	}

	return 0;
}