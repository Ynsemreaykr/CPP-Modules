/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:44 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:44 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ScavTrap Sınıfı İmplementasyonu
** ClapTrap'tan türetilmiş, başlangıç değerleri farklı.
** Constructor sırası: önce ClapTrap önce çağrılır.
** Destructor sırası: önce ScavTrap, sonra ClapTrap yıkılır.
*/

#include "ScavTrap.hpp"

/*
** ScavTrap Varsayılan Constructor
** ClapTrap'ın değerlerini ScavTrap değerleriyle ezer.
** 100 HP, 50 Enerji, 20 Hasar.
*/
ScavTrap::ScavTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

/*
** ScavTrap İsimli Constructor
** @name: Robotun adı
** ClapTrap(name) çağrılır, sonra ScavTrap değerleri ayarlanır.
*/
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

/*
** ScavTrap Kopya Constructor
** @other: Kopyalanacak ScavTrap nesnesi
*/
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak ScavTrap nesnesi
** Return: Mevcut nesnenin referansı
*/
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
	}
	return *this;
}

/*
** ScavTrap Destructor
** Önce ScavTrap, sonra ClapTrap destructor'ı çağrılır.
*/
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

/*
** attack - Hedefe saldırır (ScavTrap versiyonu)
** @target: Saldırılacak hedefin adı
**
** ClapTrap'ın attack metodunun override edilmiş versiyonu.
** "fiercely" ifadesi ile daha güçlü saldırı mesajı verir.
*/
void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " has no hit points left to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " fiercely attacks " << target 
			  << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

/*
** guardGate - Kapı bekçisi moduna geçer
**
** ScavTrap'a özel fonksiyon. Kapı bekçisi modunu aktive eder.
*/
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
