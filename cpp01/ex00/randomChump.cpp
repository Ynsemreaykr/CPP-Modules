/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:50 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:50 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** randomChump - Stack'te Geçici Zombie Oluşturma
** Bu fonksiyon, Stack'te (otomatik bellekte) geçici bir zombie oluşturur.
** Zombie fonksiyon bittiğinde otomatik olarak yok edilir.
*/

#include "Zombie.hpp"

/*
** randomChump - Stack'te geçici zombie oluşturur ve duyurur
** @name: Zombie'nin adı
** 
** Stack'te zombie oluşturur, announce çağırır ve fonksiyon bitince otomatik yok edilir.
** Destructor otomatik çağrılır, manuel delete gerekmez.
*/
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

