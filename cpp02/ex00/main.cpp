/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:33:44 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:33:44 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex00 Test Programı - Sabit Noktalı Sayı (Temel Canonical Form)
** Fixed sınıfının canonical form üyelerini test eder.
** Constructor, kopya, atama ve destructor sırası gözlemlenir.
*/

#include <iostream>
#include "Fixed.hpp"

/*
** main - Program giriş noktası
**
** Üç Fixed nesnesi oluşturur: varsayılan, kopya ve atama.
** getRawBits ile ham değerleri yazdırır.
** Scopedan çıkınca destructor'lar otomatik çağrılır.
** Return: 0
*/
int main( void )
{
	Fixed a;					/* Varsayılan constructor */
	Fixed b( a );				/* Kopya constructor */
	Fixed c;					/* Varsayılan constructor */

	c = b;						/* Atama operatörü */
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;	
}
