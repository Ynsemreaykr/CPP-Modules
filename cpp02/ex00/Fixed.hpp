/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:33:24 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:33:24 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Noktalı Sayı Sınıfı Header (ex00 - Temel Canonical Form)
** Bu dosya, sabit noktalı (fixed-point) sayı sistemini temsil eden
** Fixed sınıfının tanımını içerir.
** Canonical Form: Default Constructor, Copy Constructor, Atama Operatörü, Destructor.
** 8 bitlik kesir kısmı ile çalışır.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*
** Fixed Sınıfı (ex00)
** Sabit noktalı sayı gösterimi. İkiye tümleyen formatında saklanır.
** fix = 8 bit kesir kısmı anlamına gelir (2^8 = 256 hassasiyet).
** Bu egzersizde sadece temel canonical form uygulanır.
*/
class Fixed
{
private:
	int					fixed;			/* Ham bit değeri */
	static const int	fix = 8;		/* Kesir biti sayısı (değiştirilemez) */

public:
	Fixed();							/* Varsayılan constructor - 0 ile başlar */
	Fixed(const Fixed& other);			/* Kopya constructor */
	Fixed& operator=(const Fixed& other);	/* Atama operatörü */
	~Fixed();							/* Destructor */

	int		getRawBits(void) const;		/* Ham bit değerini döndürür */
	void	setRawBits(int const raw);	/* Ham bit değerini ayarlar */
};
   
#endif
