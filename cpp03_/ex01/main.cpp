/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:41 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:41 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex01 Test Programı - ScavTrap (Kalıtım)
** ClapTrap ve ScavTrap'ı karşılaştırır.
** Constructor/destructor sırasını gözlemler (polimorfizm için hazırlık).
** ScavTrap'ın guardGate özelliği test edilir.
*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
** main - Program giriş noktası
**
** ClapTrap ve ScavTrap nesneleri oluşturur.
** Temel saldırı/hasar/iyileşme döngüsünü her iki sınıf için test eder.
** Return: 0
*/
int main()
{
	ClapTrap y("Yunus");	/* ClapTrap: 10 HP, 10 Enerji, 0 Hasar */
	ScavTrap x("Emre");	/* ScavTrap: 100 HP, 50 Enerji, 20 Hasar */
	
	/* ClapTrap testi */
	y.attack("one");
	y.takeDamage(10);
	y.beRepaired(10);

	std::cout << "------------------------" << std::endl;
	
	/* ScavTrap testi */
	x.attack("two");		/* ScavTrap'ın override ettiği attack */
	x.takeDamage(10);
	x.beRepaired(10);
	x.guardGate();			/* ScavTrap'a özel yetenek */
	
	return 0;
}
