/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:21 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:21 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon &newWeapon) : weapon(newWeapon)
{
    name = newName;
}

void HumanA::attack() 
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}	

