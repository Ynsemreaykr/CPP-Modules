/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:23 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:23 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ex01 Test Programı - Brain ve Derin Kopyalama Testi
** Dog ve Cat nesnelerinin Brain'leri ile derin kopya çalışması test edilir.
** Hayvan dizisi ve derin kopya atama operatörü doğrulanır.
*/

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
** main - Program giriş noktası
**
** 1. Dog ve Cat nesneleri oluşturulur ve silinir (virtual destructor testi).
** 2. 10 elemanlı karışık dizi (5 Dog + 5 Cat) oluşturulur, sesler duyurulur.
** 3. Derin kopya testi: dog2 = dog1 atanır, Brain adresleri farklı olmalı.
** Return: 0
*/
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j; 	/* virtual destructor: Dog::~Dog() çağrılır */
	delete i;
	
	/* 10 hayvanlık karışık dizi */
	std::cout << "\nArray Test (Half Dog, Half Cat)" << std::endl;
	const int arraySize = 10;
	Animal* animals[arraySize];
	
	/* İlk 5 köpek */
	for (int idx = 0; idx < arraySize / 2; idx++)
	{
		animals[idx] = new Dog();
	}
	
	/* Son 5 kedi */
	for (int idx = arraySize / 2; idx < arraySize; idx++)
	{
		animals[idx] = new Cat();
	}
	
	/* Tüm hayvanların seslerini çıkar (polimorfizm) */
	std::cout << "\nTesting makeSound()" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
	}
	
	/* Dizideki tüm hayvanları sil */
	std::cout << "\nDeleting Array" << std::endl;
	for (int idx = 0; idx < arraySize; idx++)
	{
		delete animals[idx];
	}
	
	/* Derin kopya testi: dog2 = dog1 sonrası Brain adresleri farklı olmalı */
	std::cout << "\nDeep Copy Test (Assignment Operator)" << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea(0, "I love bones!");
	
	Dog dog2;
	dog2.getBrain()->setIdea(0, "I am dog2");
	
	dog2 = dog1;  	/* Derin kopya atama operatörü */
	
	/* Adresler farklı olmalı (bağımsız Brain'ler) */
	std::cout << "\nAfter assignment (dog2 = dog1):" << std::endl;
	std::cout << "dog1: " << dog1.getBrain()->getIdea(0) 
	          << " (Brain address: " << dog1.getBrain() << ")" << std::endl;
	std::cout << "dog2: " << dog2.getBrain()->getIdea(0) 
	          << " (Brain address: " << dog2.getBrain() << ")" << std::endl;
	
	
	
	return 0;
}
