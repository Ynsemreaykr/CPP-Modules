/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:10:03 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:10:03 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FragTrap Sınıfı İmplementasyonu
** ClapTrap'tan türetilmiş, farklı başlangıç değerleri.
** 100 HP, 100 Enerji, 30 Hasar ile güçlü savaş robotu.
*/

#include "FragTrap.hpp"

/*
** FragTrap Varsayılan Constructor
** ClapTrap bazında oluşturulur, değerler FragTrap için ayarlanır.
** 100 HP, 100 Enerji, 30 Hasar.
*/
FragTrap::FragTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

/*
** FragTrap İsimli Constructor
** @name: Robotun adı
** ClapTrap(name) çağrılır, sonra FragTrap değerleri ayarlanır.
*/
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

/*
** FragTrap Kopya Constructor
** @other: Kopyalanacak FragTrap nesnesi
*/
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak FragTrap nesnesi
** ClapTrap'ın atama operatörü çağrılır (temel sınıf üyelerini kopyalar).
*/
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);	/* Temel sınıfın atama operatörünü çağır */
	}
	return *this;
}

/*
** FragTrap Destructor
** Önce FragTrap, sonra ClapTrap destructor'ı çağrılır.
*/
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

/*
** highFivesGuys - Pozitif çak beşlik isteği gönderir
**
** FragTrap'a özel yetenek. Ekrana pozitif bir istek mesajı yazdırır.
*/
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five! " << std::endl;
}
