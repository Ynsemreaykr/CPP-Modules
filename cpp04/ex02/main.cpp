/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:48 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:48 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex02 Test Programı - Soyut Sınıf (Abstract Class) Testi
** Animal soyut sınıfa dönüştürüldü: makeSound() = 0 (pure virtual).
** Animal nesnesi doğrudan oluşturulamaz.
** Dog ve Cat hâlâ oluşturulabilir (makeSound() implement ettiler).
*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
** main - Program giriş noktası
**
** ex01 ile aynı testler uygulanır.
** Fark: Animal nesnesi oluşturmak derleme hatası verir (soyut sınıf).
** Return: 0
*/
int main()
{
	/* Animal* pointer ile polimorfik ses testi */
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	j->makeSound();	/* Dog::makeSound() - virtual */
	i->makeSound();	/* Cat::makeSound() - virtual */
	
	delete j;  	/* Dog virtual destructor */
	delete i;
	
	/* 10 hayvanlık karışık dizi */
	std::cout << "\n=== Array Test (Half Dog, Half Cat) ===" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];
	
	for (int idx = 0; idx < arraySize / 2; idx++)
	{
		animals[idx] = new Dog();
	}
	
	for (int idx = arraySize / 2; idx < arraySize; idx++)
	{
		animals[idx] = new Cat();
	}
	
	/* Polimorfik ses çıkarma */
	std::cout << "\n=== Testing makeSound() ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}
	
	/* Dizi temizleme */
	std::cout << "\n=== Deleting Array ===" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		delete animals[idx];
	}
	
	/* Derin kopya testi */
	std::cout << "\n=== Deep Copy Test (Assignment Operator) ===" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love bones!");
	
	Dog dog2;
	dog2.getBrain()->setIdea(0, "I am dog2");
	
	dog2 = dog1;  	/* Derin kopya - Brain adresleri farklı olmalı */
	
	std::cout << "\nAfter assignment (dog2 = dog1):" << std::endl;
	std::cout << "dog1: " << dog1.getBrain()->getIdea(0) 
	          << " (Brain address: " << dog1.getBrain() << ")" << std::endl;
	std::cout << "dog2: " << dog2.getBrain()->getIdea(0) 
	          << " (Brain address: " << dog2.getBrain() << ")" << std::endl;
	
	
	
	return 0;
}
