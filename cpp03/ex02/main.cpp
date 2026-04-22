/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:10:06 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:10:06 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex02 Test Programı - FragTrap (Kalıtım Devamı)
** FragTrap nesneleri oluşturur, saldırı ve highFivesGuys test eder.
** Constructor/destructor sırası gözlemlenir (ClapTrap -> FragTrap).
*/

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/*
** main - Program giriş noktası
**
** İki FragTrap nesnesi oluşturur.
** Saldırı, hasar ve highFivesGuys metodlarını test eder.
** Return: 0
*/
int main()
{
	FragTrap x("Yunus");	/* FragTrap: 100 HP, 100 Enerji, 30 Hasar */
	FragTrap y("Emre");	/* FragTrap: 100 HP, 100 Enerji, 30 Hasar */
	
	y.attack("FİRE!");		/* y, FİRE! hedefine saldırır */
	y.takeDamage(10);		/* y 10 hasar alır */
	y.beRepaired(1000);		/* y 1000 HP iyileşir */

	y.highFivesGuys();		/* y çak beşlik ister */
	x.highFivesGuys();		/* x çak beşlik ister */
	
	return 0;
}
