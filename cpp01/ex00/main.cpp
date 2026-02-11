/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:43 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:43 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex00 Test Programı - Stack vs Heap Allocation
** Bu program, Stack ve Heap'te zombie oluşturmanın farklarını gösterir.
** Heap'teki zombie'ler manuel delete gerektirir, Stack'tekiler otomatik yok edilir.
*/

#include "Zombie.hpp"

/*
** main - Program giriş noktası
** 
** Stack ve Heap allocation farklarını test eder:
** - newZombie: Heap'te zombie oluşturur (manuel delete gerekir)
** - randomChump: Stack'te zombie oluşturur (otomatik yok edilir)
** Return: 0
*/
int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	
	heapZombie->announce();
	delete heapZombie;
	
	std::cout << std::endl;
	
	randomChump("StackZombie");
	
	std::cout << std::endl;
	
	Zombie* zombie1 = newZombie("Foo");
	zombie1->announce();


	randomChump("Bar");

	delete zombie1;
	
	
	
	return 0;
}

