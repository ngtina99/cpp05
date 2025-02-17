/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 18:37:40 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define MYRED "\033[1;31m"
#define MYEOF "\033[0m"
#define MYBLUE "\033[1;34m"


class Bureaucrat {
	
	private:

		static const int _minGrade;
		static const int _maxGrade;
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
		int const &getGrade() const;

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

};

std::ostream &operator<<( std::ostream &op, const Bureaucrat &copy);

#endif