/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:39 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:39 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cat Sınıfı İmplementasyonu (ex02 - Soyut Sınıf ile)
** Soyut Animal sınıfını implement eder.
** makeSound() zorunlu olarak implement edilir (pure virtual override).
** Brain derin kopyalaması ex01 ile aynıdır.
*/

#include "Cat.hpp"

/*
** Cat Varsayılan Constructor
** type = "Cat", yeni Brain Heap'te oluşturulur.
*/
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

/*
** Cat Kopya Constructor (Derin Kopya)
** @other: Kopyalanacak Cat nesnesi
*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain); /* Derin kopya */
}

/*
** operator= - Atama Operatörü (Derin Kopya)
** @other: Atanacak Cat nesnesi
*/
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain; 
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

/*
** Cat Destructor
** Brain Heap belleği serbest bırakılır.
*/
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

/*
** makeSound - Kedi sesini çıkarır (pure virtual implement)
** Soyut Animal sınıfının pure virtual fonksiyonunu implement eder.
*/
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

/*
** getBrain - Brain pointer'ını döndürür
*/
Brain* Cat::getBrain() const
{
	return this->brain;
}
