/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 16:03:48 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

#define MYRED "\033[1;31m"
#define MYEOF "\033[0m"

class AForm;

class Bureaucrat {
	
	private:

		static const int _minGrade = 150;
		static const int _maxGrade = 1;
		std::string const _name;
		int _grade;

	public:

		Bureaucrat ();
		Bureaucrat( const std:: string &name );
		Bureaucrat( int grade );
		Bureaucrat( const std:: string &name, int grade );
		Bureaucrat ( const Bureaucrat &copy);
		Bureaucrat	&operator=( const Bureaucrat &rhs );
		~Bureaucrat();

		std::string const	&getName() const;
		int const getGrade() const;

		void	incrGrade();
		void	decrGrade();

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {

			public:

				const char *what() const throw();
		};

		void	signForm(AForm &formToSign);
		void	executeForm(AForm const & form);
		// 		Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
// it will print something like:
// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>

};

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy);

#endif