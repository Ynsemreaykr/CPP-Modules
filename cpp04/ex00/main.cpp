/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:57 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:57 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex00 Test Programı - Virtual Fonksiyon ve Polimorfizm
** Animal/Cat/Dog ile WrongAnimal/WrongCat karşılaştırması yapılır.
** virtual anahtar kelimesinin polimorfik davranış üzerindeki etkisi gözlemlenir.
*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
** main - Program giriş noktası
**
** Animal* pointer üzerinden Dog ve Cat sesleri çalışır (virtual sayesinde).
** WrongAnimal* pointer üzerinden WrongCat sesi ÇALIŞMAZ (virtual yok).
** Return: 0
*/
int main()
{
	/* Polimorfik kullanım: Animal* pointer ile Cat ve Dog */
	const Animal* meta = new Animal();
	const Animal* j = new Dog();		/* Dog nesnesi, Animal pointer */
	const Animal* i = new Cat();		/* Cat nesnesi, Animal pointer */
	
	std::cout << "\nType: " << j->getType() << " " << std::endl;
	std::cout << "Type: " << i->getType() << " " << std::endl;
	
	i->makeSound(); 	/* Cat::makeSound() çalışır (virtual sayesinde) */
	j->makeSound(); 	/* Dog::makeSound() çalışır (virtual sayesinde) */
	meta->makeSound(); 	/* Animal::makeSound() çalışır */
	
	delete meta;
	delete j;
	delete i;
	
	/* Hatalı kullanım: WrongAnimal* pointer ile WrongCat */
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();	/* WrongCat nesnesi */
	
	std::cout << "\nType: " << wrongCat->getType() << " " << std::endl;
	
	wrongCat->makeSound(); 		/* WrongAnimal::makeSound() çalışır (YANLIŞ - virtual yok) */
	wrongMeta->makeSound();		/* WrongAnimal::makeSound() çalışır */
	
	delete wrongMeta;
	delete wrongCat;
	
	/* Doğrudan WrongCat nesnesi üzerinden ses çalışır */
	std::cout << "\n=== Testing WrongCat directly ===" << std::endl;
	WrongCat directWrongCat;
	std::cout << "Type: " << directWrongCat.getType() << std::endl;
	directWrongCat.makeSound();	/* WrongCat::makeSound() çalışır (doğrudan nesne) */
	

	return 0;
}
