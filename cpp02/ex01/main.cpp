/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:34:53 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:34:53 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex01 Test Programı - Sabit Noktalı Sayı Dönüşümleri
** int ve float'dan Fixed oluşturmayı, toInt ve toFloat dönüşümlerini test eder.
** << operatörü ile Fixed nesneleri doğrudan std::cout'a yazdırılır.
*/

#include <iostream>
#include "Fixed.hpp"

/*
** main - Program giriş noktası
**
** Farklı kaynaklardan (varsayılan, int, float, kopya) Fixed oluşturur.
** Atama ve dönüşümleri test eder.
** Return: 0
*/
int main( void )
{
	Fixed		a;						/* Varsayılan: 0 */
	Fixed const	b( 10 );				/* Int constructor: 10 */
	Fixed const	c( 42.42f );			/* Float constructor: 42.42 */
	Fixed const	d( b );				/* Kopya constructor */

	a = Fixed( 1234.4321f );			/* Geçici nesne atanıyor */

	/* << operatörü ile float değerleri göster */
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	/* toInt ile tam sayı değerlerini göster (kesir düşer) */
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

