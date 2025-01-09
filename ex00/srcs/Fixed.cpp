/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:42:54 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 17:35:13 by hurabe           ###   ########.fr       */
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

// ゲッター(プライベート変数_fixed_point_numの値を外部から取得するための関数)
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_num;
}

// セッター(プライベート変数_fixed_point_numの値を外部から設定するための関数)
void	Fixed::setRawBits(int const raw) {
	this->_fixed_point_num = raw;
}
