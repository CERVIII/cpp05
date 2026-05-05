/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 12:28:40 by pcervill          #+#    #+#             */
/*   Updated: 2026/02/05 16:27:44 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName()
		<< " | Signed: " << (form.isSigned() ? "Yes" : "No") 
		<< " | Grade to sign: " << form.getGradeToSign()
		<< " | Grade to execute: " << form.getGradeToExecute();
	return os;
}