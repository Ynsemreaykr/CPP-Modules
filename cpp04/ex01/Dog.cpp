/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:19 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:19 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Dog Sınıfı İmplementasyonu (ex01 - Brain ile Derin Kopyalama)
** Cat ile aynı derin kopyalama mantığı, köpek versiyonu.
*/

#include "Dog.hpp"

/*
** Dog Varsayılan Constructor
** Türü "Dog" ayarlar ve Heap'te yeni Brain oluşturur.
*/
Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();	/* Brain Heap'te oluşturulur */
	std::cout << "Dog default constructor called" << std::endl;
}

/*
** Dog Kopya Constructor (Derin Kopya)
** @other: Kopyalanacak Dog nesnesi
**
** new Brain(*other.brain) ile bağımsız Brain kopyası oluşturulur.
*/
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);  	/* Derin kopya */
}

/*
** operator= - Atama Operatörü (Derin Kopya)
** @other: Atanacak Dog nesnesi
*/
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain; 					/* Eski Brain silinir */
		this->brain = new Brain(*other.brain); 	/* Yeni derin kopya Brain */
	}
	return *this;
}

/*
** Dog Destructor
** Brain pointer silinir.
*/
Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

/*
** makeSound - Köpek sesini çıkarır
*/
void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

/*
** getBrain - Brain pointer'ını döndürür
** Return: Brain nesnesi pointer'ı
*/
Brain* Dog::getBrain() const
{
	return this->brain;
}
