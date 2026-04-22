/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 05:09:20 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/24 05:09:20 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex00 Test Programı - ClapTrap Savaş Robotu
** İki ClapTrap nesnesinin saldırı, hasar ve iyileşme döngüsünü test eder.
** Constructor ve destructor çağrı sırasını gözlemlemek için kullanılır.
*/

#include "ClapTrap.hpp"

/*
** main - Program giriş noktası
**
** İki robot oluşturur, birbirlerine saldırır ve iyileşir.
** Scope bittikten sonra destructor'lar ters sırada çağrılır.
** Return: 0
*/
int main()
{
	ClapTrap robot1("Alpha");	/* Alpha robotu oluştur */
	ClapTrap robot2("Beta");	/* Beta robotu oluştur */
	
	robot1.attack(robot2.getName());	/* Alpha, Beta'ya saldırır */
	robot2.takeDamage(5);				/* Beta 5 hasar alır */
	robot2.beRepaired(3);				/* Beta 3 HP iyileşir */
	robot2.attack(robot1.getName());	/* Beta, Alpha'ya saldırır */
	
	return 0;
}
