/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:36:44 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/05 11:40:07 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test 1: Crear con grado válido y mostrar
	try
	{
		Bureaucrat b1("Alice", 3);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Grado demasiado alto al crear
	try
	{
		Bureaucrat b2("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Decrementar hasta excepción
	try
	{
		Bureaucrat b3("Charlie", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;

	try
	{
		Bureaucrat b4("Dave", 151); // This should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}