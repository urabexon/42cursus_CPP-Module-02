/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:40:40 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/07 19:09:04 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// デフォルトコンストラクタ
Fixed::Fixed() {
	this->_fixed_point_num = 0;
}

// 整数の引数を取るコンストラクタ
Fixed::Fixed(const int num) {
	_fixed_point_num = num << _bit; // ビットシフトを使って固定小数点表現に変換する
}

// 浮動小数点数の引数をとるコンストラクタ
Fixed::Fixed(const float num) {
	_fixed_point_num = roundf(num * (1 << _bit));
}

//　コピーコンストラクタ
Fixed::Fixed(const Fixed &copy) {
	*this = copy;
}

// デストラクタ
Fixed::~Fixed() {};

// コピー代入演算子
Fixed&	operator = (const Fixed &copy) {
	if (this != &copy)
		this->_fixed_point_num = copy.getRawBits();
	return *this;
}

