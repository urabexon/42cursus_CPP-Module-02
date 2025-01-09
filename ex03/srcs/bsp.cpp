/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:51 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 22:35:29 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 点(point)が三角形(a,b,c)の内部にあるかを判定する
bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	// 各点のx座標とy座標を取得し、Fixed型として格納
	Fixed ax(a.getRawBitsX());
	Fixed ay(a.getRawBitsY());
	Fixed bx(b.getRawBitsX());
	Fixed by(b.getRawBitsY());
	Fixed cx(c.getRawBitsX());
	Fixed cy(c.getRawBitsY());
	Fixed px(point.getRawBitsX());
	Fixed py(point.getRawBitsY());

	// ベクトルのクロス積を計算する
	// pa->pb
	Fixed cross_ab = (ax - px) * (by - py) - (ay - py) * (bx - px);
	// pb->pc
	Fixed cross_bc = (bx - px) * (cy - py) - (by - py) * (cx - px);
	// pc->pa
	Fixed cross_ca = (cx - px) * (ay - py) - (cy - py) * (ax - px);
	
	/* 
	　・true : 点が三角形の内部にある場合
	　・false: 点が三角形の外部または返上にある場合 
	*/
	return ((cross_ab.toFloat() > 0 && cross_bc.toFloat() > 0 && cross_ca.toFloat() > 0) 
		|| (cross_ab.toFloat() < 0 && cross_bc.toFloat() < 0 && cross_ca.toFloat() < 0));
}
