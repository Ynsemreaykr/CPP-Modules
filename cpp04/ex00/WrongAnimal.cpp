/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:59 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:59 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WrongAnimal Sınıfı İmplementasyonu
** makeSound() virtual olmadığı için WrongAnimal pointer üzerinden
** WrongCat::makeSound() çalışmaz, WrongAnimal::makeSound() çalışır.
** Bu durum yanlış uygulama örneği olarak gösterilir.
*/

#include "WrongAnimal.hpp"

/*
** WrongAnimal Varsayılan Constructor
** Türü "WrongAnimal" olarak ayarlar.
*/
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/*
** WrongAnimal Kopya Constructor
*/
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
*/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

/*
** WrongAnimal Destructor (virtual DEĞİL)
** virtual olmadığı için Heap'te delete yanlış destructor çağırabilir.
*/
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*
** makeSound - Yanlış hayvan sesi (virtual olmayan)
** WrongAnimal pointer üzerinden her zaman bu versiyon çağrılır.
** WrongCat nesnesi bile olsa WrongCat::makeSound() değil bu çağrılır.
*/
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a wrong sound!" << std::endl;
}

/*
** getType - Hayvan türünü döndürür
*/
std::string WrongAnimal::getType() const
{
	return this->type;
}
