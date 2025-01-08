/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:59 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/08 19:04:36 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}

Point::Point(const float num_x, const float num_y) : x(num_x), y(num_y) {}

Point::Point(const Point & origin) : x(origin.getRawBitsX()), y(origin.getRawBitsY()) {}

Point::~Point() {}

Point& Point::operator = (const Point &origin) {
	if (this == &origin)
		return *this;
	return *this;
}

Fixed Point::getRawBitsX() const {
	return (this->x);
}

Fixed Point::getRawBitsY() const {
	return (this->y);
}
