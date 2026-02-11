/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:47 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:47 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** newZombie - Heap'te Zombie Oluşturma
** Bu fonksiyon, Heap'te (dinamik bellekte) yeni bir zombie oluşturur.
** Oluşturulan zombie'nin pointer'ı döndürülür ve manuel olarak delete edilmelidir.
*/

#include "Zombie.hpp"

/*
** newZombie - Heap'te yeni zombie oluşturur
** @name: Zombie'nin adı
** Return: Yeni oluşturulan zombie'nin pointer'ı
** 
** new operatörü ile Heap'te zombie oluşturur.
** Çağıran fonksiyon delete ile belleği temizlemekten sorumludur.
*/
Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

