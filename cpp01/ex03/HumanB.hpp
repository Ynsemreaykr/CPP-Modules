/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:26 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:26 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
	void attack();
};

#endif

