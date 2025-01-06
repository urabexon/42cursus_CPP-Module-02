/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:42:54 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/06 22:10:53 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// デフォルトコンストラクタ
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_num = 0;
}

// コピーコンストラクタ
Fixed::Fixed(const Fixed &copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

// コピー代入演算子
Fixed& Fixed::operator = (const Fixed &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) // 自己代入を防ぐ
		this->_fixed_point_num = copy.getRawBits();
	return *this;
}

// デストラクタ
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_num;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed_point_num = raw;
}
