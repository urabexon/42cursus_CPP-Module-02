/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:46 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/08 18:58:30 by hurabe           ###   ########.fr       */
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
		~Fixed();									// デストラクタ

		// 自身を返す演算子では，これを実現するために，値返しでなく参照返しが用いられる
		Fixed&	operator = (const Fixed &copy);		// コピー代入演算子
		bool	operator > (const Fixed &right) const;
		bool	operator < (const Fixed &right) const;
		bool	operator >= (const Fixed &right) const;
		bool	operator <= (const Fixed &right) const;
		bool	operator == (const Fixed &right) const;
		bool	operator != (const Fixed &right) const;
		
		Fixed	operator + (const Fixed &right) const;
		Fixed	operator - (const Fixed &right) const;
		Fixed	operator * (const Fixed &right) const;
		Fixed	operator / (const Fixed &right) const;
		
		Fixed	&operator++();						//  前置インクリメント
		Fixed	operator++(int);					//  後置インクリメント
		Fixed	&operator--();						//  前置デクリメント
		Fixed	operator--(int);					//  後置デクリメント

		static Fixed &min(Fixed &left, Fixed &right);
		static const Fixed &min(const Fixed &left, const Fixed &right);
		static Fixed &max(Fixed &left, Fixed &right);
		static const Fixed &max(const Fixed &left, const Fixed &right);
		
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
