/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:34:55 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 02:34:55 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Fixed Noktalı Sayı Sınıfı Header (ex01 - Dönüşüm Constructorları)
** ex00'ı genişletir: int ve float'dan Fixed oluşturma eklenir.
** toFloat() ve toInt() dönüşüm metodları ile << operatörü tanımlanır.
** 8 bitlik kesir kısmı ile çalışır: değer = raw / 2^8
*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/*
** Fixed Sınıfı (ex01)
** ex00'a ek olarak: int ve float constructorları, toFloat, toInt eklendi.
** Sabit noktalı sayı dönüşümlerini gösterir.
** << operatörü ile doğrudan std::cout'a yazdırılabilir.
*/
class Fixed
{
private:
	int					fixed;			/* Ham bit değeri */
	static const int	fix = 8;		/* Kesir biti sayısı */

public:
	Fixed();								/* Varsayılan constructor - 0 */
	Fixed(const int intValue);				/* int'den Fixed oluşturur */
	Fixed(const float floatValue);			/* float'dan Fixed oluşturur */
	Fixed(const Fixed& other);				/* Kopya constructor */
	Fixed& operator=(const Fixed& other);	/* Atama operatörü */
	~Fixed();								/* Destructor */

	int		getRawBits(void) const;			/* Ham bit değerini döndürür */
	void	setRawBits(int const raw);		/* Ham bit değerini ayarlar */
	float	toFloat(void) const;			/* Float'a dönüştürür */
	int		toInt(void) const;				/* Int'e dönüştürür (kesir kısmı düşer) */
};

/* << operatörü: Fixed'ı float olarak stream'e yazar */
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
