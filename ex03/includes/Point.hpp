/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:48 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/07 22:03:18 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float num_x, const float num_y);
		Point(const Point & origin);
		~Point();
		Point& operator = (const Point &origin);
		Fixed getRawBitsX() const;
		Fixed getRawBitsY() const;
	private:
		const Fixed x;
		const Fixed y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
