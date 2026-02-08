/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:14 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:15 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Contact Sınıfı Header Dosyası
** Bu dosya, telefon rehberinde saklanacak kişi bilgilerini temsil eden
** Contact sınıfının tanımını içerir.
*/

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

/*
** Contact Sınıfı
** Bir kişinin bilgilerini (ad, soyad, takma ad, telefon, sır) saklar.
** Encapsulation prensibi gereği tüm üye değişkenler private'dır.
** Getter ve setter metodları ile erişim sağlanır.
*/
class Contact
{
private:
	std::string	_firstName;		/* Kişinin adı */
	std::string	_lastName;		/* Kişinin soyadı */
	std::string	_nickname;		/* Kişinin takma adı */
	std::string	_phoneNumber;	/* Telefon numarası */
	std::string	_darkestSecret;	/* En büyük sırrı */

public:
	/* Getter metodları - Üye değişkenleri okumak için */
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	/* Setter metodları - Üye değişkenleri ayarlamak için */
	void		setLastName(const std::string& lastName);
	void		setNickname(const std::string& nickname);
	void		setPhoneNumber(const std::string& phoneNumber);
	void		setDarkestSecret(const std::string& darkestSecret);
};

#endif
