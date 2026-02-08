/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:17 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:18 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PhoneBook Ana Program
** Bu dosya, telefon rehberi uygulamasının giriş noktasını içerir.
** Kullanıcıdan komut alır ve ilgili işlemleri gerçekleştirir.
*/

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

/*
** main - Program giriş noktası
** 
** Sonsuz döngüde kullanıcıdan komut alır:
** - ADD: Yeni kişi ekler
** - SEARCH: Kişi arar ve gösterir
** - EXIT: Programdan çıkar
** Geçersiz komut girilirse uyarı verir.
** Return: Her zaman 0
*/
int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

	while (true)
	{
		std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "> ";
		if(!std::getline(std::cin, command)){
			std::cout<<"\n";
			break;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command. ";
	}

	return (0);
}
