/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 00:34:34 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 20:05:27 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#define MYRED "\033[1;31m"
#define MYEOF "\033[0m"
#define MYBLUE "\033[1;34m"
#define MYGREEN "\033[1;32m"
#define MYPURPLE "\033[1;35m"

class Bureaucrat;

class AForm {

	private:

		std::string const _name;
		bool	_signed;
		int const _gradeSign;
		int const _gradeExecute;
		static const int _minGrade = 150;
		static const int _maxGrade = 1;

	public:

		AForm ();
		AForm ( const std:: string &name );
		AForm( int const gradeSign, int const gradeExecute );
		AForm( const std:: string &name, int const gradeSign, int const gradeExecute );
		AForm ( const AForm &copy);
		AForm	&operator=( const AForm &rhs );
		virtual ~AForm();

		std::string const &getName() const;
		std::string getSigned() const;
		int const getGradeSign() const;
		int const getGradeExecute() const;
		bool	  getSignedBool() const;

		void			beSigned(Bureaucrat &copy);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			
			public:

				const char *what() const throw();

		};

		class GradeTooLowException : public std::exception {

			public:

				const char *what() const throw();

		};
		
		class FormNotSignedException : public std::exception {

			public:

				const char *what() const throw();
	
		};
};

std::ostream &operator<<( std::ostream &op, const AForm &copy);

#endif