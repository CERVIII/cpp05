/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:43:20 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/10 12:23:23 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// Creamos un burócrata de máximo nivel (grado 1)
	Bureaucrat ceo("CEO", 1);

	// Test 1. Prueba con ShrubberyCreationForm
	std::cout << "TEST 1:" << std::endl;
	ShrubberyCreationForm shrub("homep");
	ceo.signForm(shrub);
	ceo.executeForm(shrub);

	// Test 2. Prueba con RobotomyRequestForm
	std::cout << "\nTEST 2:" << std::endl;
	RobotomyRequestForm robot("Bender");
	ceo.signForm(robot);
	ceo.executeForm(robot);
	
	// Test 3. Prueba con PresidentialPardonForm
	std::cout << "\nTEST 3:" << std::endl;
	PresidentialPardonForm pardon("Zoidberg");
	ceo.executeForm(pardon);
	ceo.signForm(pardon);
	ceo.executeForm(pardon);

	return 0;
}