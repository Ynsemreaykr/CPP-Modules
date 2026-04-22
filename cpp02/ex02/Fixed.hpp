/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:35:12 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:35:12 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Noktalı Sayı Sınıfı Header (ex02 - Tam Operatör Aşırı Yükleme)
** ex01'e ek olarak: karşılaştırma, aritmetik ve artırma/azaltma operatörleri.
** Statik min/max fonksiyonları ile en büyük/küçük değer bulunur.
** Ön ve son artırma/azaltma (++a, a++, --a, a--) desteklenir.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*
** Fixed Sınıfı (ex02 - Kapsamlı Operatör Aşırı Yükleme)
** Tüm karşılaştırma operatörleri: >, <, >=, <=, ==, !=
** Tüm aritmetik operatörler: +, -, *, /
** Artırma/azaltma: ++a (ön), a++ (son), --a, a--
** Statik: min ve max (const ve non-const versiyonlar)
*/
class Fixed
{
private:
	int					fixed;			/* Ham bit değeri */
	static const int	fix = 8;		/* Kesir biti sayısı */

public:
	Fixed();									/* Varsayılan constructor */
	Fixed(const int intValue);					/* Int constructor */
	Fixed(const float floatValue);				/* Float constructor */
	Fixed(const Fixed& other);					/* Kopya constructor */
	Fixed& operator=(const Fixed& other);		/* Atama operatörü */
	~Fixed();									/* Destructor */

	int		getRawBits(void) const;				/* Ham bit değerini döndürür */
	void	setRawBits(int const raw);			/* Ham bit değerini ayarlar */
	float	toFloat(void) const;				/* Float'a dönüştürür */
	int		toInt(void) const;					/* Int'e dönüştürür */

	/* Karşılaştırma Operatörleri */
	bool	operator>(const Fixed& other) const;	/* Büyüktür */
	bool	operator<(const Fixed& other) const;	/* Küçüktür */
	bool	operator>=(const Fixed& other) const;	/* Büyük eşit */
	bool	operator<=(const Fixed& other) const;	/* Küçük eşit */
	bool	operator==(const Fixed& other) const;	/* Eşit */
	bool	operator!=(const Fixed& other) const;	/* Eşit değil */

	/* Aritmetik Operatörler */
	Fixed	operator+(const Fixed& other) const;	/* Toplama */
	Fixed	operator-(const Fixed& other) const;	/* Çıkarma */
	Fixed	operator*(const Fixed& other) const;	/* Çarpma */
	Fixed	operator/(const Fixed& other) const;	/* Bölme */

	/* Artırma ve Azaltma Operatörleri */
	Fixed&	operator++();		/* Ön artırma: değeri artırır, artırılmış değer döner */
	Fixed	operator++(int);	/* Son artırma: değeri artırır, eski değer döner */
	Fixed&	operator--();		/* Ön azaltma */
	Fixed	operator--(int);	/* Son azaltma */

	/* Statik Min/Max Fonksiyonları */
	static Fixed&		min(Fixed& a, Fixed& b);					/* İkisi arasından küçüğü */
	static const Fixed&	min(const Fixed& a, const Fixed& b);		/* Const versiyonu */
	static Fixed&		max(Fixed& a, Fixed& b);					/* İkisi arasından büyüğü */
	static const Fixed&	max(const Fixed& a, const Fixed& b);		/* Const versiyonu */
};

/* << operatörü: Fixed'ı float olarak stream'e yazar */
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
