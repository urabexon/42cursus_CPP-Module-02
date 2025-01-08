/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:51 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/08 17:57:13 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed ax(a.getRawBitsX());
	Fixed ay(a.getRawBitsY());
	Fixed bx(b.getRawBitsX());
	Fixed by(b.getRawBitsY());
	Fixed cx(c.getRawBitsX());
	Fixed cy(c.getRawBitsY());
	Fixed px(point.getRawBitsX());
	Fixed py(point.getRawBitsY());

	// pa->pb
	Fixed cross_ab = (ax - px) * (by - py) - (ay - py) * (bx - px);
	// pb->pc
	Fixed cross_bc = (bx - px) * (cy - py) - (by - py) * (cx - px);
	// pc->pa
	Fixed cross_ca = (cx - px) * (ay - py) - (cy - py) * (ax - px);

	return ((cross_ab.toFloat() > 0 && cross_bc.toFloat() > 0 && cross_ca.toFloat() > 0) 
		|| (cross_ab.toFloat() < 0 && cross_bc.toFloat() < 0 && cross_ca.toFloat() < 0)) ? true : false;
}
