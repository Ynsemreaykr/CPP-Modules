/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:32 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:32 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Animal Sınıfı İmplementasyonu (ex02 - Soyut Sınıf)
** ex01'den farklı: makeSound() = 0 (pure virtual) olduğu için
** Animal nesnesi doğrudan oluşturulamaz.
** makeSound() implement edilmediğinden bu dosyada tanımlanamaz.
*/

#include "Animal.hpp"

/*
** Animal Varsayılan Constructor
** Türü "Animal" olarak ayarlar.
** Soyut sınıf olduğu için bu constructor sadece alt sınıflar çağırabilir.
*/
Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/*
** Animal Kopya Constructor
** @other: Kopyalanacak Animal nesnesi
*/
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Animal nesnesi
*/
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

/*
** Animal Destructor (virtual)
** Soyut sınıfta da virtual destructor zorunludur.
*/
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** getType - Hayvan türünü döndürür
*/
std::string Animal::getType() const
{
	return this->type;
}
