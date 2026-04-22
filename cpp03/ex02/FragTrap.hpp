/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:10:00 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:10:00 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FragTrap Sınıfı Header Dosyası
** ClapTrap'tan türetilmiş en güçlü savaş robotu.
** Başlangıç değerleri: 100 HP, 100 Enerji, 30 Hasar.
** highFivesGuys() özel yeteneği eklenir.
*/

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

/*
** FragTrap Sınıfı
** ClapTrap'tan türetilmiştir. En yüksek hasar değeriyle güçlü savaş robotu.
** highFivesGuys: Pozitif bir "çak beşlik" isteği gönderir.
*/
class FragTrap : public ClapTrap
{
public:
	FragTrap();											/* Varsayılan constructor */
	FragTrap(const std::string& name);					/* İsimli constructor */
	FragTrap(const FragTrap& other);					/* Kopya constructor */
	FragTrap& operator=(const FragTrap& other);			/* Atama operatörü */
	~FragTrap();										/* Destructor */

	void highFivesGuys(void);	/* Pozitif çak beşlik isteği (FragTrap'a özel) */
};

#endif
