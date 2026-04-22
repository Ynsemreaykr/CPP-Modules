/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:36:17 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:36:17 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex02 Test Programı - Kapsamlı Operatör Aşırı Yükleme
** Artırma, çarpma ve max fonksiyonlarını test eder.
** ++a (ön artırma) ve a++ (son artırma) farkını gösterir.
*/

#include <iostream>
#include "Fixed.hpp"

/*
** main - Program giriş noktası
**
** a ve b nesneleri oluşturur.
** Ön ve son artırma operatörlerini test eder.
** max ile büyük değeri bulur.
** Return: 0
*/
int main( void )
{
	Fixed		a;									/* a = 0 */
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );	/* b = 5.05 * 2 = 10.1 */

	std::cout << a << std::endl;		/* 0 */
	std::cout << ++a << std::endl;		/* Ön artırma: önce artır sonra yazdır */
	std::cout << a << std::endl;		/* Artırılmış değer */
	std::cout << a++ << std::endl;		/* Son artırma: önce yazdır sonra artır */
	std::cout << a << std::endl;		/* Artırılmış değer */

	std::cout << b << std::endl;		/* b'nin değeri */

	std::cout << Fixed::max( a, b ) << std::endl;	/* a ve b'nin büyüğü */

	return 0;
}

