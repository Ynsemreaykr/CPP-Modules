/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:01 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:02 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout<<"constructor"<<std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string Name)
{
	name = Name;
}

