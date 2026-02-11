/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:55 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:55 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << "=== DEBUG ===" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n=== INFO ===" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n=== WARNING ===" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n=== ERROR ===" << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\n=== INVALID ===" << std::endl;
	harl.complain("INVALID");
	
	return 0;
}

