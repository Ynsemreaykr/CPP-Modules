/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:33:20 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:33:20 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Sınıfı İmplementasyonu (ex00 - Canonical Form)
** Canonical Form 4 üye: Default Constructor, Copy Constructor,
** Atama Operatörü ve Destructor implementasyonları.
** getRawBits çağrıldığında mesaj yazdırır (egzersiz gereksinimi).
*/

#include "Fixed.hpp"

/*
** Fixed Varsayılan Constructor
** Ham değeri 0 olarak başlatır ve mesaj yazdırır.
*/
Fixed::Fixed()
{
    this->fixed = 0;
    std::cout << "Default constructor called" << std::endl;
}

/*
** Fixed Kopya Constructor
** @other: Kopyalanacak Fixed nesnesi
** Mevcut nesneye diğer nesnenin değerini kopyalar.
*/
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;	/* Atama operatörünü çağırır */
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Fixed nesnesi
** Return: Mevcut nesnenin referansı (*this)
**
** Kendine atama kontrolü yapılır (if this != &other).
** getRawBits ile ham değer alınır ve kopyalanır.
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
** Nesne yok edildiğinde mesaj yazdırır.
*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*
** getRawBits - Ham bit değerini döndürür
** Return: Saklanan ham integer değeri
**
** Bu egzersizde çağrıldığında mesaj yazdırır.
*/
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
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
