/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:34 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:35 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PhoneBook Sınıfı İmplementasyonu
** Bu dosya, PhoneBook sınıfının tüm metodlarının implementasyonlarını içerir.
** Kişi ekleme, arama, listeleme ve görüntüleme işlevlerini sağlar.
*/

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

/*
** PhoneBook Constructor
** Telefon rehberini başlatır. Kişi sayısını ve en eski indeksi 0'a ayarlar.
*/
PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0)
{
}

/*
** addContact - Yeni kişi ekler
** 
** Kullanıcıdan 5 bilgi alır: ad, soyad, takma ad, telefon, sır.
** Rehber doluysa (8 kişi) en eski kişiyi siler (FIFO).
** Boş alan kabul edilmez, her alan için validasyon yapılır.
*/
void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	while (true)
	{
		std::cout << "First name: ";
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty())
			break;
		std::cout << "First name cannot be empty!" << std::endl;
	}
	newContact.setFirstName(input);

	while (true)
	{
		std::cout << "Last name: ";
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty())
			break;
		std::cout << "Last name cannot be empty!" << std::endl;
	}
	newContact.setLastName(input);

	while (true)
	{
		std::cout << "Nickname: ";
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty())
			break;
		std::cout << "Nickname cannot be empty!" << std::endl;
	}
	newContact.setNickname(input);

	while (true)
	{
		std::cout << "Phone number: ";
		if (!std::getline(std::cin, input))
			return;
		if (!input.empty())
			break;
		std::cout << "Phone number cannot be empty!" << std::endl;
	}
	newContact.setPhoneNumber(input);

	while (true)
	{
		std::cout << "Darkest secret: ";
		if (!std::getline(std::cin, input)){
			return;
		}
		if (!input.empty()){
			break;
		}
		std::cout << "Darkest secret cannot be empty!" << std::endl;
	}
	newContact.setDarkestSecret(input);

	if (_contactCount < 8)
	{
		_contacts[_contactCount] = newContact;
		_contactCount++;
	}
	else
	{
		_contacts[_oldestIndex] = newContact;
		_oldestIndex = (_oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

/*
** searchContact - Kişi arama ve görüntüleme
** 
** Önce tüm kişileri tablo halinde gösterir.
** Kullanıcıdan indeks ister ve seçilen kişinin detaylarını gösterir.
** Geçersiz indeks girilirse hata mesajı verir.
*/
void	PhoneBook::searchContact() const
{
	if (_contactCount == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}

	displayContacts();

	std::cout << "Enter index: ";
	std::string	input;
	if(!std::getline(std::cin, input))
		return;



	int	index = std::atoi(input.c_str());
	
	if (input == "0" || (index > 0 && index < _contactCount))
		displayContact(index);
	else
		std::cout << "Invalid index." << std::endl;
}

/*
** displayContacts - Tüm kişileri tablo halinde gösterir
** 
** İndeks, ad, soyad ve takma ad sütunlarından oluşan bir tablo çizer.
** Her sütun 10 karakter genişliğindedir.
** 10 karakterden uzun metinler kırpılır ve son karakteri '.' olur.
*/
void	PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	int i = 0;
	while (i < _contactCount)
	{
		std::cout << std::setw(10) << i << "|";
		
		std::string firstName = _contacts[i].getFirstName();
		if (firstName.length() > 10)
		{
			firstName = firstName.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << firstName << "|";

		std::string lastName = _contacts[i].getLastName();
		if (lastName.length() > 10)
		{
			lastName = lastName.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << lastName << "|";

		std::string nickname = _contacts[i].getNickname();
		if (nickname.length() > 10)
		{
			nickname = nickname.substr(0, 9) + ".";
		}
		std::cout << std::setw(10) << nickname << std::endl;
		i++;
	}
}

/*
** displayContact - Belirli bir kişinin tüm bilgilerini gösterir
** @index: Görüntülenecek kişinin indeksi
** 
** Seçilen kişinin ad, soyad, takma ad, telefon ve sırrını ekrana yazdırır.
*/
void	PhoneBook::displayContact(int index) const
{
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
