/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:53 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 22:38:19 by hurabe           ###   ########.fr       */
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
Fixed::~Fixed() {}

// コピー代入演算子
Fixed&	Fixed::operator = (const Fixed &copy) {
	if (this != &copy)
		this->_fixed_point_num = copy.getRawBits();
	return *this;
}

// 大なり比較
bool	Fixed::operator > (const Fixed &right) const {
	return this->_fixed_point_num > right.getRawBits();
}

// 小なり比較
bool	Fixed::operator < (const Fixed &right) const {
	return this->_fixed_point_num < right.getRawBits();
}

// 大なりイコール比較
bool	Fixed::operator >= (const Fixed &right) const {
	return this->_fixed_point_num >= right.getRawBits();
}

// 小なりイコール比較
bool	Fixed::operator <= (const Fixed &right) const {
	return this->_fixed_point_num <= right.getRawBits();
}

// 等価比較
bool	Fixed::operator == (const Fixed &right) const {
	return this->_fixed_point_num == right.getRawBits();
}

// 非等価比較
bool	Fixed::operator != (const Fixed &right) const {
	return this->_fixed_point_num != right.getRawBits();
}

// 加算
Fixed	Fixed::operator + (const Fixed &right) const {
	return Fixed(this->toFloat() + right.toFloat());
}

// 減算
Fixed	Fixed::operator - (const Fixed &right) const {
	return Fixed(this->toFloat() - right.toFloat());
}

// 乗算
Fixed	Fixed::operator * (const Fixed &right) const {
	return Fixed(this->toFloat() * right.toFloat());
}

// 除算
Fixed	Fixed::operator / (const Fixed &right) const {
	return Fixed(this->toFloat() / right.toFloat());	
}

/**前置インクリメント
 * 1．オブジェクトの値をインクリメントする
 * 2．インクリメント後のオブジェクトを返す
 */
Fixed	&Fixed::operator++() {
	_fixed_point_num++;
	return *this;
}

/**後置インクリメント
 * 1．インクリメント前のオブジェクトを返す
 * 2．オブジェクトの値をインクリメントする
 * *引数に取られたint型は，後置インクリメントが前置──と区別して識別されるようにするためのもの．
 * *int型の引数は，一般的には，引数の受け渡しには使用されない
 */
Fixed	Fixed::operator++(int) {
	Fixed res = *this->_fixed_point_num++;
	return res;
}

/**前置デクリメント
 * 1．オブジェクトの値をデクリメントする
 * 2．デクリメント後のオブジェクトを返す
 */
Fixed	&Fixed::operator--() {
	_fixed_point_num--;
	return *this;
}

/**後置デクリメント
 * 1．デクリメント前のオブジェクトを返す
 * 2．オブジェクトの値をデクリメントする
 * *引数に取られたint型は，後置デクリメントが前置──と区別して識別されるようにするためのもの．
 * *int型の引数は，一般的には，引数の受け渡しには使用されない
 */
Fixed	Fixed::operator--(int) {
	Fixed res = *this->_fixed_point_num--;
	return res;
}

// 最小値を返す(非const参照用)
Fixed &Fixed::min(Fixed &left, Fixed &right) {
	return (left < right) ? left : right;
}

// 最小値を返す(const参照用)
const Fixed &Fixed::min(const Fixed &left, const Fixed &right) {
	return (left < right) ? left : right;
}

// 最大値を返す(非const参照用)
Fixed &Fixed::max(Fixed &left, Fixed &right) {
	return (left > right) ? left : right;
}

// 最大値を返す(const参照用)
const Fixed &Fixed::max(const Fixed &left, const Fixed &right) {
	return (left > right) ? left : right;
}

// ゲッター(プライベート変数_fixed_point_numの値を外部から取得するための関数)
int		Fixed::getRawBits(void) const {
	return this->_fixed_point_num;
}

// セッター(プライベート変数_fixed_point_numの値を外部から設定するための関数)
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

// 出力ストリーム演算子のオーバーロード
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat(); // 浮動小数点表現を出力
	return out;
}
