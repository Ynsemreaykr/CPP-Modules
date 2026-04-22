/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:35:09 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:35:09 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Sınıfı İmplementasyonu (ex02 - Tam Operatör Aşırı Yükleme)
** Karşılaştırma: ham bit değerleri karşılaştırılır.
** Aritmetik: toam sayı işlemi yapılır, bazıları bit kaydırma gerektirir.
** Artırma/azaltma: 1 birim = en küçük kesir birimi (1/256).
*/

#include "Fixed.hpp"
#include <cmath>

/*
** Fixed Varsayılan Constructor
** Ham değeri 0 olarak başlatır (mesaj yok, ex02'de mesajlar kaldırıldı).
*/
Fixed::Fixed()
{
    this->fixed = 0;
}

/*
** Fixed Int Constructor
** @intValue: Dönüştürülecek tam sayı
** Bit kaydırma ile sabit noktaya çevirir.
*/
Fixed::Fixed(const int intValue)
{
	fixed = intValue << fix;
}

/*
** Fixed Float Constructor
** @floatValue: Dönüştürülecek ondalıklı sayı
** Çarpma ve yuvarlama ile sabit noktaya çevirir.
*/
Fixed::Fixed(const float floatValue)
{
	fixed = roundf(floatValue * (1 << fix));
}

/*
** Fixed Kopya Constructor
** @other: Kopyalanacak Fixed nesnesi
*/
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Fixed nesnesi
** Return: Mevcut nesnenin referansı
*/
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->fixed = other.getRawBits();
	return *this;
}

/*
** Fixed Destructor
*/
Fixed::~Fixed()
{
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
*/
void Fixed::setRawBits(int const raw)
{
	this->fixed = raw;
}

/*
** toFloat - Float'a dönüştürür
** Return: ham / 2^8 = gerçek değer
*/
float Fixed::toFloat(void) const
{
	return (float)(fixed) / (1 << fix);
}

/*
** toInt - Int'e dönüştürür
** Return: ham >> 8 (kesir kısmı atılır)
*/
int Fixed::toInt(void) const
{
	return fixed >> fix;
}

/* Karşılaştırma Operatörleri - Ham bit değerleri karşılaştırılır */

/*
** operator> - Büyüktür karşılaştırması
*/
bool Fixed::operator>(const Fixed& other) const
{
	return this->fixed > other.fixed;
}

/*
** operator< - Küçüktür karşılaştırması
*/
bool Fixed::operator<(const Fixed& other) const
{
	return this->fixed < other.fixed;
}

/*
** operator>= - Büyük eşit karşılaştırması
*/
bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixed >= other.fixed;
}

/*
** operator<= - Küçük eşit karşılaştırması
*/
bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixed <= other.fixed;
}

/*
** operator== - Eşitlik karşılaştırması
*/
bool Fixed::operator==(const Fixed& other) const
{
	return this->fixed == other.fixed;
}

/*
** operator!= - Eşitsizlik karşılaştırması
*/
bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixed != other.fixed;
}

/* Aritmetik Operatörler */

/*
** operator+ - Toplama operatörü
** @other: Toplanacak Fixed değer
** Return: Ham değerlerin toplamı
*/
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixed + other.fixed);
	return result;
}

/*
** operator- - Çıkarma operatörü
** @other: Çıkarılacak Fixed değer
** Return: Ham değerlerin farkı
*/
Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->fixed - other.fixed);
	return result;
}

/*
** operator* - Çarpma operatörü
** @other: Çarpılacak Fixed değer
** Return: Çarpım (bit kaydırma ile normalize edilir)
** Not: (a*b) >> fix çünkü çarpma iki kez fix bit kayar
*/
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->fixed * other.fixed) >> fix);
	return result;
}

/*
** operator/ - Bölme operatörü
** @other: Bölen Fixed değer
** Return: Bölüm (bit kaydırma ile normalize edilir)
** Not: (a << fix) / b çünkü bölme fix bit azaltır
*/
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->fixed << fix) / other.fixed);
	return result;
}

/* Artırma ve Azaltma Operatörleri */

/*
** operator++ (ön) - Ön artırma
** Ham değeri 1 artırır (1/256 artışı) ve güncel değeri döndürür.
*/
Fixed& Fixed::operator++()
{
	++this->fixed;
	return *this;
}

/*
** operator++ (son) - Son artırma
** Eski değeri saklar, ham değeri artırır, eski değeri döndürür.
*/
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

/*
** operator-- (ön) - Ön azaltma
** Ham değeri 1 azaltır ve güncel değeri döndürür.
*/
Fixed& Fixed::operator--()
{
	--this->fixed;
	return *this;
}

/*
** operator-- (son) - Son azaltma
** Eski değeri saklar, ham değeri azaltır, eski değeri döndürür.
*/
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--this->fixed;
	return temp;
}

/* Statik Min/Max Fonksiyonları */

/*
** min - İki değerin küçüğünü döndürür (non-const)
*/
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

/*
** min - İki değerin küçüğünü döndürür (const)
*/
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

/*
** max - İki değerin büyüğünü döndürür (non-const)
*/
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

/*
** max - İki değerin büyüğünü döndürür (const)
*/
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

/*
** operator<< - Fixed'ı stream'e yazar
** @out: Çıkış stream'i
** @fixed: Yazdırılacak Fixed nesnesi
** Return: Çıkış stream'i
*/
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
