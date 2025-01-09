/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:59 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 20:40:38 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// デフォルトコンストラクタ
Point::Point() {}

// x, y座標を指定して点を初期化するコンストラクタ
Point::Point(const float num_x, const float num_y) : x(num_x), y(num_y) {} 

// コピーコンストラクタ: 別のPointオブジェクトをコピーして初期化
Point::Point(const Point & origin) : x(origin.getRawBitsX()), y(origin.getRawBitsY()) {}

// デストラクタ
Point::~Point() {}

// コピー代入演算子
Point& Point::operator = (const Point &origin) {
	if (this == &origin)
		return *this;
	return *this;
}

// ゲッター(Fixed型として取得し、x座標を返す)
Fixed Point::getRawBitsX() const {
	return (this->x);
}

// セッター(Fixed型として取得し、y座標を返す)
Fixed Point::getRawBitsY() const {
	return (this->y);
}
