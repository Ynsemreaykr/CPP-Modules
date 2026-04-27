/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:48 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:48 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Animal Sınıfı Header (ex00 - Polimorfizm Temelleri)
** Bu dosya, tüm hayvan sınıflarının temel sınıfını tanımlar.
** makeSound() virtual: polimorfizm sağlar, doğru türetilmiş sınıf çağrılır.
** virtual destructor: Heap'te delete ile doğru destructor garantilenir.
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

/*
** Animal Sınıfı (Temel Sınıf)
** Tüm hayvanların ortak özelliklerini taşır.
** virtual makeSound(): Her türetilmiş sınıf kendi sesini çıkarır.
** virtual ~Animal(): Polimorfik kullanımda doğru destructor çağrısını sağlar.
** type: protected, alt sınıflara erişilebilir.
*/
class Animal
{
protected:
	std::string type;	/* Hayvanın türü (örn: "Cat", "Dog") */

public:
	Animal();									/* Varsayılan constructor */
	Animal(const Animal& other);				/* Kopya constructor */
	Animal& operator=(const Animal& other);		/* Atama operatörü */
	virtual ~Animal();							/* Virtual destructor (polimorfizm için zorunlu) */

	virtual void makeSound() const;				/* Sanal ses çıkarma (alt sınıflar override eder) */
	std::string getType() const;				/* Hayvan türünü döndürür */
};

#endif
