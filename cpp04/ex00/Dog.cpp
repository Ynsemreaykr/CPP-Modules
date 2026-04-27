/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:53 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:53 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Dog Sınıfı İmplementasyonu
** Animal'dan türetilmiş köpek sınıfının implementasyonu.
** type = "Dog", makeSound() override edilmiş.
*/

#include "Dog.hpp"

/*
** Dog Varsayılan Constructor
** Türü "Dog" olarak ayarlar. Animal constructor önce çağrılır.
*/
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/*
** Dog Kopya Constructor
** @other: Kopyalanacak Dog nesnesi
*/
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Dog nesnesi
*/
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

/*
** Dog Destructor
*/
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

/*
** makeSound - Köpek sesini çıkarır
** virtual fonksiyon override edildi.
** Animal pointer üzerinden çağrıldığında bu versiyon çalışır.
*/
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
