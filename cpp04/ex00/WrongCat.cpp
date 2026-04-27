/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:02 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:02 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WrongCat Sınıfı İmplementasyonu
** WrongAnimal pointer üzerinden makeSound() çağrıldığında
** bu sınıfın makeSound() değil WrongAnimal'ın makeSound() çalışır.
*/

#include "WrongCat.hpp"

/*
** WrongCat Varsayılan Constructor
** Türü "WrongCat" olarak ayarlar.
*/
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

/*
** WrongCat Kopya Constructor
*/
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
*/
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

/*
** WrongCat Destructor
*/
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

/*
** makeSound - Yanlış kedi sesi
** Doğrudan WrongCat nesnesi üzerinden çağrıldığında çalışır.
** Ancak WrongAnimal pointer üzerinden çağrılamaz (virtual yok).
*/
void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}
