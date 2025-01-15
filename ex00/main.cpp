/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:32:06 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/01/15 16:08:13 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Please note that exception classes don’t have to be designed in
// Orthodox Canonical Form. But every other class has to.

// Remember. Since grade 1 is the highest one and 150 the lowest,
// incrementing a grade 3 should give a grade 2 to the bureaucrat.

// Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception

int	main() {
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
  		
}
