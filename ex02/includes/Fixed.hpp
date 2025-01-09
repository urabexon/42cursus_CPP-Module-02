/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:40:36 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 19:49:10 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();														// デフォルトコンストラクタ
		Fixed(const int num);											// 整数の引数をとるコンストラクタ
		Fixed(const float num);											// 浮動小数点数の引数をとるコンストラクタ
		Fixed(const Fixed &copy);										// コピーコンストラクタ
		~Fixed();														// デストラクタ

		// 自身を返す演算子では，これを実現するために，値返しでなく参照返しが用いられる
		Fixed&	operator = (const Fixed &copy);							// コピー代入演算子
		bool	operator > (const Fixed &right) const;					// 大なり比較
		bool	operator < (const Fixed &right) const;					// 小なり比較
		bool	operator >= (const Fixed &right) const;					// 大なりイコール比較
		bool	operator <= (const Fixed &right) const; 				// 小なりイコール比較
		bool	operator == (const Fixed &right) const; 				// 等価比較
		bool	operator != (const Fixed &right) const; 				// 非等価比較

		// 算術演算子(2つのFixedオブジェクト間で算術演算を行う)
		Fixed	operator + (const Fixed &right) const;					// 加算
		Fixed	operator - (const Fixed &right) const;					// 減算
		Fixed	operator * (const Fixed &right) const;					// 乗算
		Fixed	operator / (const Fixed &right) const;					// 除算

		// インクリメント/デクリメント演算子(Fixedオブジェクトの値を増減する)
		Fixed	&operator++();											// 前置インクリメント
		Fixed	operator++(int);										// 後置インクリメント
		Fixed	&operator--();											// 前置デクリメント
		Fixed	operator--(int);										// 後置デクリメント

		// 静的メソッド(2つのFixedオブジェクトのうち最小/最大値を返す)
		static Fixed &min(Fixed &left, Fixed &right);					// 最小値を返す(非const参照用)
		static const Fixed &min(const Fixed &left, const Fixed &right);	// 最小値を返す(const参照用)
		static Fixed &max(Fixed &left, Fixed &right);					// 最大値を返す(非const参照用)
		static const Fixed &max(const Fixed &left, const Fixed &right);	// 最大値を返す(const参照用)
		
		int		getRawBits(void) const;									// ゲッター(プライベート変数_fixed_point_numの値を外部から取得するための関数)
		void	setRawBits(int const raw);								// セッター(プライベート変数_fixed_point_numの値を外部から設定するための関数)
		float	toFloat(void) const;									// 固定小数点数を浮動小数点数に変換する
		int		toInt(void) const;										// 固定小数点数を整数に変換する

	private:
		int	_fixed_point_num;											// 固定小数点数の値を格納する変数
		static const int	_bit = 8;									// 小数ビット数を格納する静的定数整数
};

// 出力ストリーム演算子のオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
