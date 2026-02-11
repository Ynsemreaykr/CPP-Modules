/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:31 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:31 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type)
{
    type = Type;
}

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string Type)
{
	type = Type;
}

