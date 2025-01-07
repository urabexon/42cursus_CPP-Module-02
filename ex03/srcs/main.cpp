/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:56 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/07 22:20:28 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void) {
	Point a(0, 0);
	Point b(0, 3);
	Point c(3, 0);
	Point point(1, 1);
	if (bsp(a, b, c, point))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	return 0;	
}
