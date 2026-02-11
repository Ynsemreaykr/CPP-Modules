/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:04 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:04 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif

