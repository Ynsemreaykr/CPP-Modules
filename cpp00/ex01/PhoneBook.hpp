/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:38 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:39 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** PhoneBook Sınıfı Header Dosyası
** Bu dosya, maksimum 8 kişi saklayabilen telefon rehberi sınıfının
** tanımını içerir. FIFO (First In First Out) mantığıyla çalışır.
*/

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

/*
** PhoneBook Sınıfı
** Maksimum 8 Contact nesnesi saklayabilen telefon rehberi.
** 8 kişi dolduğunda en eski kişi silinir (FIFO).
** ADD, SEARCH ve EXIT komutlarını destekler.
*/
class PhoneBook
{
private:
	Contact	_contacts[8];		/* Maksimum 8 kişilik dizi */
	int		_contactCount;		/* Mevcut kişi sayısı (0-8) */
	int		_oldestIndex;		/* En eski kişinin indeksi (FIFO için) */

public:
	PhoneBook();				/* Constructor - Başlangıç değerlerini ayarlar */
	void	addContact();		/* Yeni kişi ekler (ADD komutu) */
	void	searchContact() const;/* Kişi arar ve gösterir (SEARCH komutu) */
	void	displayContacts() const;/* Tüm kişileri tablo halinde gösterir */
	void	displayContact(int index) const;/* Belirli bir kişinin detaylarını gösterir */
};

#endif
