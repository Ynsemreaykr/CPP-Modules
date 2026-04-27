/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:55 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:55 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Dog Sınıfı Header Dosyası
** Animal'dan türetilmiş köpek sınıfı.
** makeSound() override edilerek köpek sesini ("Woof!") çıkarır.
*/

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

/*
** Dog Sınıfı
** Animal temel sınıfından türetilmiş.
** makeSound() "Woof! Woof!" çıkarır (polimorfik davranış).
** type = "Dog" olarak ayarlanır.
*/
class Dog : public Animal
{
public:
	Dog();									/* Varsayılan constructor */
	Dog(const Dog& other);					/* Kopya constructor */
	Dog& operator=(const Dog& other);		/* Atama operatörü */
	~Dog();									/* Destructor */

	void makeSound() const;					/* "Woof!" sesini çıkarır */
};

#endif
