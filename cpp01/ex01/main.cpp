/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:41:58 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:41:58 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "HordeZombie");
	
	std::cout << "Announcing the horde:" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\nDeleting the horde:" << std::endl;
	delete[] horde;
	
	return 0;
}

