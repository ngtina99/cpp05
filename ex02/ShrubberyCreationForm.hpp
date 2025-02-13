/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:40 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 20:02:30 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

const std::string TREE =
"      /\\\n"
"     /  \\\n"
"    /    \\\n"
"   /      \\\n"
"  /        \\\n"
" /          \\\n"
"/____________\\\n"
"      ||\n"
"      ||\n"
"      ||\n"
"      ||\n";

class ShrubberyCreationForm : public AForm {
	
	private:

		const std::string _target;

	public:
	
		ShrubberyCreationForm();
		ShrubberyCreationForm ( const std::string &target );
		ShrubberyCreationForm ( const ShrubberyCreationForm &copy);
		ShrubberyCreationForm	&operator=( const ShrubberyCreationForm &rhs );
		~ShrubberyCreationForm();
		
		void	execute(Bureaucrat const & executor) const;

};

#endif
