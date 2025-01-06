/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:20:23 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/06 23:13:08 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();									// デフォルトコンストラクタ
		Fixed(const int num);						// 整数の引数をとるコンストラクタ
		Fixed(const float num);						// 浮動小数点数の引数をとるコンストラクタ
		Fixed(const Fixed &copy);					// コピーコンストラクタ
		Fixed& operator = (const Fixed &copy);		// コピー代入演算子
		~Fixed();									// デストラクタ
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int	_fixed_point_num;						// 固定小数点数の値を格納する変数
		static const int	_bit = 8;				// 小数ビット数を格納する静的定数整数
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
