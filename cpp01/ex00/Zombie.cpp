/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:52 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:52 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Zombie Sınıfı İmplementasyonu
** Constructor, Destructor ve announce metodunun implementasyonları.
*/

#include "Zombie.hpp"

/*
** Zombie Constructor
** @Name: Zombie'nin adı
** Zombie nesnesini verilen isimle oluşturur.
*/
Zombie::Zombie(std::string Name)
{
    name = Name;
}

/*
** Zombie Destructor
** Zombie yok edildiğinde ekrana mesaj yazdırır.
** Stack'teki zombie'ler otomatik, Heap'tekiler delete ile yok edilir.
*/
Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

/*
** announce - Zombie kendini duyurur
** Zombie'nin adını ve "BraiiiiiiinnnzzzZ..." mesajını ekrana yazdırır.
*/
void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
