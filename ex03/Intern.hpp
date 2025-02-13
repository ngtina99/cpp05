/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:05:07 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/13 22:24:34 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTER_HPP
#define INTERN_HPP

#include <iostream>

class Intern {

	public:

		Intern();
		~Intern();
		Intern(Intern &copy);
		Intern &operator=(Intern &rhs);

		AForm	*makeForm(std::string &formName, std::string &formTarget);

};

#endif