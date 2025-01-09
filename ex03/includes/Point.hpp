/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:48 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 20:38:51 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

// 2D空間上の点を表現するクラス
class Point {
	public:
		Point();										// デフォルトコンストラクタ
		Point(const float num_x, const float num_y);	// x, y座標を指定して点を初期化するコンストラクタ
		Point(const Point & origin);					// コピーコンストラクタ: 別のPointオブジェクトをコピーして初期化
		~Point();										// デストラクタ
		Point& operator = (const Point &origin);		// コピー代入演算子
		Fixed getRawBitsX() const;						// ゲッター(Fixed型として取得し、x座標を返す)
		Fixed getRawBitsY() const;						// セッター(Fixed型として取得し、y座標を返す)
		
	private:
		const Fixed x;									// 点のx座標
		const Fixed y;									// 点のy座標 どちらもconstにする
};

// 点(point)が三角形(a, b, c)の内部にあるかどうかを判定する関数
// 引数:a,b,cがそれぞれの三角形の頂点、pointが判定対象の点
bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
