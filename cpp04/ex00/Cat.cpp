/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:49 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:49 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cat Sınıfı İmplementasyonu
** Animal'dan türetilmiş kedi sınıfının implementasyonu.
** type = "Cat", makeSound() override edilmiş.
*/

#include "Cat.hpp"

/*
** Cat Varsayılan Constructor
** Türü "Cat" olarak ayarlar. Animal constructor önce çağrılır.
*/
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/*
** Cat Kopya Constructor
** @other: Kopyalanacak Cat nesnesi
** Animal'ın kopya constructorını çağırır.
*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

/*
** operator= - Atama Operatörü
** @other: Atanacak Cat nesnesi
** Animal'ın atama operatörünü çağırır.
*/
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

/*
** Cat Destructor
** Kedi yok edildiğinde mesaj yazdırır.
*/
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

/*
** makeSound - Kedi sesini çıkarır
** virtual fonksiyon override edildi.
** Animal pointer üzerinden çağrıldığında bu versiyon çalışır.
*/
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
