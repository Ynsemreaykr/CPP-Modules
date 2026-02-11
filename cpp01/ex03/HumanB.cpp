/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:25 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:25 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
    name = newName;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon& Weapon)
{
	weapon = &Weapon;
}

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon" << std::endl;
}

