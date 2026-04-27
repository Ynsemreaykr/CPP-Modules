/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:12 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:12 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Brain Sınıfı Header Dosyası (ex01 - Derin Kopyalama)
** 100 fikir saklayan beyin sınıfı.
** Cat ve Dog'da Brain* pointer olarak tutulur.
** Derin kopyalama (deep copy): Kopya yapıldığında yeni Brain nesnesi oluşturulur.
** Yüzeysel kopyalama (shallow copy) bellek sorunlarına yol açar.
*/

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

/*
** Brain Sınıfı
** 100 elemanlı fikir dizisi tutar.
** Cat ve Dog nesneleri Heap'te Brain pointer saklar.
** Derin kopyalama zorunludur: Aksi hâlde iki nesne aynı Brain'e işaret eder,
** birini silerken diğeri dangling pointer kalır.
*/
class Brain
{
private:
	std::string ideas[100];		/* 100 fikir dizisi */

public:
	Brain();									/* Varsayılan constructor - fikirleri boşaltır */
	Brain(const Brain& other);					/* Kopya constructor - derin kopya */
	Brain& operator=(const Brain& other);		/* Atama operatörü - derin kopya */
	~Brain();									/* Destructor */

	void setIdea(int index, const std::string& idea);	/* Belirli indekse fikir yazar */
	std::string getIdea(int index) const;				/* Belirli indeksten fikir okur */
};

#endif
