/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:23:40 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 20:07:58 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
	
	private:

		const std::string _target;

	public:
	
		RobotomyRequestForm();
		RobotomyRequestForm ( const std:: string &target );
		RobotomyRequestForm ( const RobotomyRequestForm &copy);
		RobotomyRequestForm	&operator=( const RobotomyRequestForm &rhs );
		~RobotomyRequestForm();
		
		void	execute(Bureaucrat const & executor) const;

};

#endif