/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:20:23 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 18:55:42 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/*
　ゲッターとセッターを使うことで、クラスのカプセル化を保ちつつデータ操作できる。
　固定小数点数の内部整数値を取得、設定する。
*/

class Fixed {
	public:
		Fixed();									// デフォルトコンストラクタ
		Fixed(const int num);						// 整数の引数をとるコンストラクタ
		Fixed(const float num);						// 浮動小数点数の引数をとるコンストラクタ
		Fixed(const Fixed &copy);					// コピーコンストラクタ
		Fixed& operator = (const Fixed &copy);		// コピー代入演算子
		~Fixed();									// デストラクタ
		int		getRawBits(void) const;				// ゲッター(プライベート変数_fixed_point_numの値を外部から取得するための関数)
		void	setRawBits(int const raw);			// セッター(プライベート変数_fixed_point_numの値を外部から設定するための関数)
		float	toFloat(void) const;				// 固定小数点数を浮動小数点数に変換する
		int		toInt(void) const;					// 固定小数点数を整数に変換する

	private:
		int	_fixed_point_num;						// 固定小数点数の値を格納する変数
		static const int	_bit = 8;				// 小数ビット数を格納する静的定数整数
};

// 出力ストリーム演算子のオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
