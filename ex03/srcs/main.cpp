/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurabe <hurabe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:53:56 by hurabe            #+#    #+#             */
/*   Updated: 2025/01/09 20:40:56 by hurabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void) {
	// 三角形の頂点を定義する
	// a(0, 0), b(0, 3), c(3, 0) はそれぞれ三角形の頂点
	Point a(0, 0);
	Point b(0, 3);
	Point c(3, 0);

	// 判定する点を定義する
	// point(1, 1) は三角形内にあるかどうかを判定する点
	Point point(1, 1);

	// bsp 関数を使用して、点が三角形の内部にあるかを判定する
	if (bsp(a, b, c, point))
		std::cout << "true" << std::endl; // 点は三角形の内部にある
	else
		std::cout << "false" << std::endl; // 点は三角形の外部または辺上にある

	return 0;	
}
