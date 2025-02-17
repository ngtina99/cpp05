/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:34 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/17 18:40:58 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#define MYRED "\033[1;31m"
#define MYEOF "\033[0m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"

class Bureaucrat;

class Form {

	private:

		std::string const _name;
		bool	_signed;
		int const _gradeSign;
		int const _gradeExecute;
		static const int _minGrade;
		static const int _maxGrade;

	public:

		Form ();
		Form ( const std:: string &name );
		Form( int const gradeSign, int const gradeExecute );
		Form( const std:: string &name, int const gradeSign, int const gradeExecute );
		Form ( const Form &copy);
		Form	&operator=( const Form &rhs );
		~Form();

		std::string const &getName() const;
		std::string getSigned() const;
		int const &getGradeSign() const;
		int const &getGradeExecute() const;

		void	beSigned(Bureaucrat &copy);

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {

			public:

				const char *what() const throw();
		};
};

std::ostream &operator<<( std::ostream &op, const Form &copy);

#endif
