/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:55 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:55 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Zombie Sınıfı Header Dosyası
** Bu dosya, zombie nesnelerini temsil eden Zombie sınıfının tanımını içerir.
** Stack ve Heap allocation farklarını göstermek için kullanılır.
*/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

/*
** Zombie Sınıfı
** Bir zombie'nin adını saklar ve kendini duyurur.
** Stack veya Heap'te oluşturulabilir.
*/
class Zombie
{
private:
	std::string name;	/* Zombie'nin adı */

public:
	Zombie(std::string name);	/* Constructor - Zombie'yi isimle oluşturur */
	~Zombie();					/* Destructor - Zombie yok edildiğinde mesaj verir */
	void announce(void);		/* Zombie kendini duyurur */
};

/* Yardımcı Fonksiyonlar */
Zombie* newZombie(std::string name);		/* Heap'te yeni zombie oluşturur */
void randomChump(std::string name);			/* Stack'te geçici zombie oluşturur */

#endif

