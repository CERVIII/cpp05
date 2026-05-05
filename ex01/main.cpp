/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 16:13:11 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/05 16:24:35 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	// Test 1: Burocrata firma formulario válido
	std::cout << "TEST 1:" << std::endl;
	try
	{
		Bureaucrat b("Alice", 3);
		Form f("Tax Form", 5, 15);
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Burocrata con grado insuficiente
	std::cout << "\nTEST 2:" << std::endl;
	try
	{
		Bureaucrat b("Bob", 50);
		Form f("Secret Document", 30, 10);
		b.signForm(f);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Formulario con grado inválido
	std::cout << "\nTEST 3:" << std::endl;
	try
	{
		Form f("Invalid", 0, 150);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}