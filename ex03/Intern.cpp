/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:29:48 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/10 12:50:43 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

struct FormCreator
{
	std::string name;
	AForm *(*create)(const std::string &target);
};

namespace
{
	AForm *createShrubbery(const std::string &target)
	{
		return new ShrubberyCreationForm(target);
	}
	
	AForm *createRobotomy(const std::string &target)
	{
		return new RobotomyRequestForm(target);
	}

	AForm *createPardon(const std::string &target)
	{
		return new PresidentialPardonForm(target);
	}
}

const FormCreator formCreators[] = {
	{"shrubbery creation", createShrubbery},
	{"robotomy request", createRobotomy},
	{"presidential pardon", createPardon}
};

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (size_t i = 0; i < sizeof(formCreators) / sizeof(FormCreator); ++i)
	{
		if (formCreators[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i].create(target);
		}
	}
	std::cerr << "Error: Unknown form " << formName << "'" << std::endl;
	return NULL;
}