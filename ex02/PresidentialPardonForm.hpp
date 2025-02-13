/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:21:55 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 20:07:40 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	
	private:

		const std::string _target;

	public:
	
		PresidentialPardonForm();
		PresidentialPardonForm ( const std:: string &ntarget );
		PresidentialPardonForm ( const PresidentialPardonForm &copy);
		PresidentialPardonForm	&operator=( const PresidentialPardonForm &rhs );
		~PresidentialPardonForm();
		
		void	execute(Bureaucrat const & executor) const;
		
};

#endif