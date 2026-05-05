/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:41:54 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/10 12:20:06 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream file((_target + "_shrubbery").c_str());
	file << "       _-_\n"
		 << "    /~~   ~~\\\n"
		 << " /~~         ~~\\\n"
		 << "{               }\n"
		 << " \\  _-     -_  /\n"
		 << "   ~  \\\\ //  ~\n"
		 << "_- -   | | _- _\n"
		 << "  _ -  | |   -_\n"
		 << "      // \\\\\n";
	file.close();
}