/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:14 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:14 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cat Sınıfı İmplementasyonu (ex01 - Brain ile Derin Kopyalama)
** Ex00'dan farklı: Heap'te Brain oluşturulur ve derin kopya uygulanır.
** Yüzeysel kopya (shallow copy) dangling pointer sorununa yol açardı.
*/

#include "Cat.hpp"

/*
** Cat Varsayılan Constructor
** Türü "Cat" ayarlar ve Heap'te yeni Brain oluşturur.
*/
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();	/* Brain Heap'te oluşturulur */
	std::cout << "Cat default constructor called" << std::endl;
}

/*
** Cat Kopya Constructor (Derin Kopya)
** @other: Kopyalanacak Cat nesnesi
**
** new Brain(*other.brain) ile bağımsız Brain kopyası oluşturulur.
** Shallow copy yapılsaydı iki Cat aynı Brain'e işaret ederdi.
*/
Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain); 	/* Derin kopya - bağımsız Brain */
}

/*
** operator= - Atama Operatörü (Derin Kopya)
** @other: Atanacak Cat nesnesi
** Return: Mevcut nesnenin referansı
**
** Önce eski Brain silinir, sonra yenisi oluşturulur.
*/
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete this->brain; 				/* Eski Brain silinir (bellek sızıntısı önlenir) */
		this->brain = new Brain(*other.brain); 	/* Yeni derin kopya Brain */
	}
	return *this;
}

/*
** Cat Destructor
** Brain pointer silinir (Heap belleği serbest bırakılır).
*/
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

/*
** makeSound - Kedi sesini çıkarır
*/
void Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

/*
** getBrain - Brain pointer'ını döndürür
** Return: Brain nesnesi pointer'ı
*/
Brain* Cat::getBrain() const
{
	return this->brain;
}
