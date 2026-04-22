/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:34:10 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:34:10 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Sınıfı İmplementasyonu (ex01 - Dönüşüm Constructorları)
** int'den Fixed: değer << 8 ile 256 ile çarpılır (bit kaydırma).
** float'dan Fixed: roundf(değer * 256) ile sabit noktaya çevrilir.
** toFloat: raw / 256.0f
** toInt: raw >> 8 (sağa kaydırma)
*/

#include "Fixed.hpp"
#include <cmath>

/*
** Fixed Varsayılan Constructor
** Ham değeri 0 olarak başlatır.
*/
Fixed::Fixed()
{
    this->fixed = 0; 
    std::cout << "Default constructor called" << std::endl;
}

/*
** Fixed Int Constructor
** @intValue: Dönüştürülecek tam sayı değeri
**
** intValue'yu 2^8 = 256 ile çarpar (bit kaydırma ile).
** Örnek: 3 -> 3 * 256 = 768 (ham değer)
*/
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	fixed = intValue << fix;	/* intValue * 2^8 */
}

/*
** Fixed Float Constructor
** @floatValue: Dönüştürülecek ondalıklı değer
**
** floatValue * 2^8 hesaplanır ve yuvarlanır (roundf).
** Örnek: 3.14 -> round(3.14 * 256) = 804 (ham değer)
*/
Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	fixed = roundf(floatValue * (1 << fix));
}

/*
** Fixed Kopya Constructor
** @other: Kopyalanacak Fixed nesnesi
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Fixed nesnesi
** Return: Mevcut nesnenin referansı
*/
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed = other.getRawBits();
	return *this;
}	

/*
** Fixed Destructor
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** getRawBits - Ham bit değerini döndürür
*/
int Fixed::getRawBits(void) const
{
	return this->fixed;
}

/*
** setRawBits - Ham bit değerini ayarlar
** @raw: Atanacak ham değer
*/
void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

/*
** toFloat - Sabit noktalı sayıyı float'a dönüştürür
** Return: Ham değer / 2^8 = gerçek ondalıklı değer
*/
float Fixed::toFloat(void) const
{
	return (float)(fixed) / (1 << fix);
}

/*
** toInt - Sabit noktalı sayıyı int'e dönüştürür
** Return: Ham değer >> 8 (kesir kısmı atılır)
*/
int Fixed::toInt(void) const
{
	return fixed >> fix;
}

/*
** operator<< - Fixed nesnesi stream'e yazılır
** @out: Çıkış stream'i
** @fixed: Yazdırılacak Fixed nesnesi
** Return: Çıkış stream'i
**
** toFloat() ile dönüştürür ve stream'e yazar.
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
