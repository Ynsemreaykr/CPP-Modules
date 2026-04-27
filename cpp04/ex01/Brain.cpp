/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:11 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:11 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Brain Sınıfı İmplementasyonu
** Derin kopyalama implementasyonu: kopyalamada yeni dizi oluşturulur.
** 100 fikir dizisi için setIdea/getIdea ile erişim sağlanır.
*/

#include "Brain.hpp"

/*
** Brain Varsayılan Constructor
** Tüm 100 fikri boş string ile başlatır.
*/
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "";
	}
}

/*
** Brain Kopya Constructor (Derin Kopya)
** @other: Kopyalanacak Brain nesnesi
**
** Her fikri teker teker kopyalar. Bu sayede iki Brain
** bağımsız bellek alanlarına sahip olur (derin kopya).
*/
Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i];
	}
}

/*
** operator= - Atama Operatörü (Derin Kopya)
** @other: Atanacak Brain nesnesi
** Return: Mevcut nesnenin referansı
**
** Her fikri teker teker kopyalar.
*/
Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

/*
** Brain Destructor
*/
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/*
** setIdea - Belirli indekse fikir yazar
** @index: 0-99 arası indeks
** @idea: Yazılacak fikir
**
** Geçerli indeks kontrolü yapılır (0-99 arası).
*/
void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

/*
** getIdea - Belirli indeksten fikir okur
** @index: 0-99 arası indeks
** Return: Fikir stringi, geçersiz indekste boş string
*/
std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}
