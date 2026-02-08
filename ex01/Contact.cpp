/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:11 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:12 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contact Sınıfı İmplementasyonu
** Bu dosya, Contact sınıfının getter ve setter metodlarının
** implementasyonlarını içerir.
*/

#include "Contact.hpp"

/* Getter Metodları - Üye değişkenlerin değerlerini döndürür */

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string	Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickname() const
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

/* Setter Metodları - Üye değişkenlerin değerlerini ayarlar */

void	Contact::setFirstName(const std::string& firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(const std::string& nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	_darkestSecret = darkestSecret;
}
