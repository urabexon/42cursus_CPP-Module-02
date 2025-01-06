/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:20:28 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/06 23:02:24 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// デフォルトコンストラクタ
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_num = 0;
}


Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_num = num << _
}

Fixed(const float num);
Fixed(const Fixed &copy);
Fixed& operator = (const Fixed &copy);
~Fixed();
int		getRawBits(void) const;
void	setRawBits(int const raw);
float	toFloat(void) const;
int		toInt(void) const;

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);