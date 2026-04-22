/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:14 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:14 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ClapTrap Sınıfı İmplementasyonu
** Savaş robotu davranışları: saldırı, hasar alma, iyileşme.
** Her işlem için enerji/HP kontrolü yapılır.
** Tüm constructor/destructor mesajları ile canonical form uygulanır.
*/

#include "ClapTrap.hpp"

/*
** ClapTrap Varsayılan Constructor
** Varsayılan değerlerle robotu oluşturur: "Default", 10 HP, 10 Enerji, 0 Hasar.
*/
ClapTrap::ClapTrap()
{
    _name = "Default";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;

    std::cout << "ClapTrap default constructor called" << std::endl;
}

/*
** ClapTrap İsimli Constructor
** @name: Robotun adı
** Verilen isimle robotu oluşturur: 10 HP, 10 Enerji, 0 Hasar.
*/
ClapTrap::ClapTrap(const std::string& name)
{
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

/*
** ClapTrap Kopya Constructor
** @other: Kopyalanacak ClapTrap nesnesi
*/
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak ClapTrap nesnesi
** Return: Mevcut nesnenin referansı
** Tüm üye değişkenleri kopyalar.
*/
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

/*
** ClapTrap Destructor
** Robot yok edildiğinde mesaj yazdırır.
*/
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

/*
** attack - Hedefe saldırır
** @target: Saldırılacak hedefin adı
**
** 1 enerji harcayarak hedefe _attackDamage kadar hasar verir.
** Enerji veya HP yoksa saldıramaz.
*/
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points left to attack!" << std::endl;
		return;
	}
	_energyPoints--;	/* Saldırı 1 enerji harcar */
	std::cout << "ClapTrap " << _name << " attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

/*
** takeDamage - Hasar alır
** @amount: Alınan hasar miktarı
**
** HP'den hasar çıkarır. HP 0'a düşerse robot yok edilir.
** Zaten yok edilmişse mesaj verir.
*/
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0) 
	{
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
		return;
	}
	if (amount >= _hitPoints) 
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage and is destroyed!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount 
				  << " points of damage! (" << _hitPoints << " HP remaining)" << std::endl;
	}
}

/*
** beRepaired - İyileşir
** @amount: İyileşme miktarı
**
** 1 enerji harcayarak HP'ye amount ekler.
** Enerji veya HP yoksa iyileşemez.
*/
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left to repair!" << std::endl;
		return;
	}
	if (_hitPoints == 0) 
	{
		std::cout << "ClapTrap " << _name << " is destroyed and cannot be repaired!" << std::endl;
		return;
	}
	_energyPoints--;	/* İyileşme 1 enerji harcar */
	_hitPoints += amount; 
	std::cout << "ClapTrap " << _name << " is repaired for " << amount 
			  << " hit points! (" << _hitPoints << " HP total)" << std::endl;
}

/* Getter Metodları */

/*
** getName - Robotun adını döndürür
*/
std::string ClapTrap::getName() const
{
	return _name;
}

/*
** getHitPoints - Mevcut HP'yi döndürür
*/
unsigned int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

/*
** getEnergyPoints - Mevcut enerjiyi döndürür
*/
unsigned int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

/*
** getAttackDamage - Saldırı hasarını döndürür
*/
unsigned int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}
