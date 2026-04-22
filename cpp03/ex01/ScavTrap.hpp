/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:47 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:47 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ScavTrap Sınıfı Header Dosyası
** ClapTrap'tan türetilmiş (kalıtım) gelişmiş savaş robotu.
** Başlangıç değerleri: 100 HP, 50 Enerji, 20 Hasar (ClapTrap'tan farklı).
** attack() override edilir. guardGate() özel yeteneği eklenir.
*/

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

/*
** ScavTrap Sınıfı
** ClapTrap'tan türetilmiştir (public kalıtım).
** Daha fazla HP ve hasar ile gelişmiş savaş robotu.
** guardGate: Kapı bekçisi moduna geçer.
*/
class ScavTrap : public ClapTrap
{
public:
	ScavTrap();													/* Varsayılan constructor */
	ScavTrap(const std::string& name);							/* İsimli constructor */
	ScavTrap(const ScavTrap& other);							/* Kopya constructor */
	ScavTrap& operator=(const ScavTrap& other);					/* Atama operatörü */
	~ScavTrap();												/* Destructor */

	void attack(const std::string& target);	/* ClapTrap'ın attack'ını override eder */
	
	void guardGate();				/* Kapı bekçisi moduna geçer (ScavTrap'a özel) */
};

#endif
