/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:17 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:17 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ClapTrap Sınıfı Header Dosyası
** Bu dosya, savaş robotunu temsil eden ClapTrap sınıfının tanımını içerir.
** Miras hiyerarşisinin tabanıdır: ScavTrap ve FragTrap bu sınıfı miras alır.
** Başlangıç değerleri: 10 HP, 10 Enerji, 0 Hasar
*/

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

/*
** ClapTrap Sınıfı
** Savaş robotu. HP, enerji ve saldırı hasarı vardır.
** ScavTrap ve FragTrap bu sınıftan türetilir (kalıtım/inheritance).
** protected üyeler alt sınıflara erişilebilir.
*/
class ClapTrap
{
private:
	std::string		_name;			/* Robotun adı */
	unsigned int	_hitPoints;		/* Can puanı (HP) - 10 ile başlar */
	unsigned int	_energyPoints;	/* Enerji puanı - 10 ile başlar */
	unsigned int	_attackDamage;	/* Saldırı hasarı - 0 ile başlar */

public:
	ClapTrap(); 					/* Varsayılan constructor */
	ClapTrap(const std::string& name);			/* İsimli constructor */
	ClapTrap(const ClapTrap& other);			/* Kopya constructor */
	ClapTrap& operator=(const ClapTrap& other);	/* Atama operatörü */
	~ClapTrap();									/* Destructor */

	void attack(const std::string& target);		/* Hedefe saldırır (1 enerji harcar) */
	void takeDamage(unsigned int amount);		/* Hasar alır */
	void beRepaired(unsigned int amount);		/* İyileşir (1 enerji harcar) */

	/* Getter Metodları */
	std::string getName() const;				/* Adı döndürür */
	unsigned int getHitPoints() const;			/* HP'yi döndürür */
	unsigned int getEnergyPoints() const;		/* Enerjiyi döndürür */
	unsigned int getAttackDamage() const;		/* Hasarı döndürür */
};

#endif
