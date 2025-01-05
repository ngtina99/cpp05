/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 01:12:13 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/05 23:31:38 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	
	private:
	
		std::string const _name;
		int grade;

	public:

		getName();
		getGrade();
		increment
		decrement
 
}

Remember. Since grade 1 is the highest one and 150 the lowest,
incrementing a grade 3 should give a grade 2 to the bureaucrat.


Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception

#endif