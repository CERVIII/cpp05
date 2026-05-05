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

	// ==========================================
	// 1. El Intern crea un RobotomyRequestForm
	// ==========================================
	// El Intern recibe el nombre del formulario y el objetivo como strings
	AForm *form1 = intern.makeForm("robotomy request", "Bender");
	// Si la creación fue exitosa (form1 no es NULL)
	if (form1)
	{
		// El CEO firma el formulario (si tiene el rango suficiente)
		ceo.signForm(*form1);
		// El CEO ejecuta el formulario (si está firmado y tiene el rango suficiente)
		ceo.executeForm(*form1);
		// Liberamos la memoria del formulario creado dinámicamente
		delete form1;
	}

	// ==========================================
	// 2. El Intern intenta crear un formulario desconocido
	// ==========================================
	// Intentamos crear un formulario que no existe
	AForm *form2 = intern.makeForm("unknown form", "Target");
	// Como el formulario no existe, makeForm devuelve NULL
	if (!form2)
	{
		std::cout << "Form2 is NULL (correcto)" << std::endl;
	}

	// ==========================================
	// 3. El Intern crea un ShrubberyCreationForm
	// ==========================================
	AForm *form3 = intern.makeForm("shrubbery creation", "garden");
	if (form3)
	{
		ceo.signForm(*form3);
		ceo.executeForm(*form3);
		delete form3;
	}

	// ==========================================
	// 4. El Intern crea un PresidentialPardonForm
	// ==========================================
	AForm *form4 = intern.makeForm("presidential pardon", "Zoidberg");
	if (form4)
	{
		ceo.signForm(*form4);
		ceo.executeForm(*form4);
		delete form4;
	}

	return 0;
}