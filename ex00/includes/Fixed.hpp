/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:42:48 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/06 21:56:11 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();									// デフォルトコンストラクタ
		Fixed(const Fixed &copy);					// コピーコンストラクタ
		Fixed& operator = (const Fixed &copy);		// コピー代入演算子
		~Fixed();									// デストラクタ
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	
	private:
		int	_fixed_point_num;						// 固定小数点数の値を格納する変数
		static const int	bit = 8;				// 小数ビット数を格納する静的定数整数
};

#endif
