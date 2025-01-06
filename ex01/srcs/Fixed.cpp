/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:20:28 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/06 23:31:03 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// デフォルトコンストラクタ
Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_num = 0;
}

// 整数の引数をとるコンストラクタ
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_fixed_point_num = num << _bit; // ビットシフトを使って固定小数点表現に変換する
}

// 浮動小数点数の引数をとるコンストラクタ
Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_fixed_point_num = roundf(num * (1 << _bit));
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
	return this->_fixed_point_num;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixed_point_num = raw;
}

// 固定小数点数を浮動小数点数に変換する
float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixed_point_num) / (1 << _bit);
}

// 固定小数点数を整数に変換する
int		Fixed::toInt(void) const {
	return _fixed_point_num >> _bit;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
