/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:22:04 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/16 18:52:49 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name (""), _grade(150) 
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException ());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException ());
	_grade = grade;	
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &frt)
{
	*this = frt;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &frt)
{
	this->_name = frt._name;
	this->_grade = frt._grade;
	return (*this);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void Bureaucrat::increase(void)
{
	if (this->_grade < 2)
		throw (Bureaucrat::GradeTooHighException ());
	this->_grade--;
}

void Bureaucrat::decrease(void)
{
	if (this->_grade > 149)
		throw(Bureaucrat::GradeTooLowException ());
	this->_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(void)  
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const &Ex)  
{
	*this = Ex; 
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const &)  
{
	return (*this); 
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw () 
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(void)  
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const &Ex)  
{
	*this = Ex; 
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw () 
{
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const &)  
{
	return (*this); 
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << "Bureaucrat " << rhs.getName() << " Grade " << rhs.getGrade() << std::endl;
	return o;
}