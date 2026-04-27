/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:45 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:45 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Animal Sınıfı İmplementasyonu (ex00)
** Temel hayvan sınıfının canonical form implementasyonu.
** makeSound() varsayılan mesaj verir, alt sınıflar override eder.
*/

#include "Animal.hpp"

/*
** Animal Varsayılan Constructor
** Türü "Animal" olarak ayarlar.
*/
Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

/*
** Animal Kopya Constructor
** @other: Kopyalanacak Animal nesnesi
** Türü kopyalar.
*/
Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Animal nesnesi
** Return: Mevcut nesnenin referansı
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
** Virtual olduğu için polimorfik silmede doğru destructor çağrılır.
*/
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** makeSound - Hayvanın sesi (varsayılan)
** Alt sınıflar (Cat, Dog) bu metodu override eder.
** WrongAnimal ile karşılaştırıldığında virtual farkı görülür.
*/
void Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound!" << std::endl;
}

/*
** getType - Hayvan türünü döndürür
** Return: Hayvanın tür ismi
*/
std::string Animal::getType() const
{
	return this->type;
}
