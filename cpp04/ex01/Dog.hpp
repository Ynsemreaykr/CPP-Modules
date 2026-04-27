/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:21 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:21 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Dog Sınıfı Header (ex01 - Brain ile Derin Kopyalama)
** Cat ile aynı yapı, köpek versiyonu.
** Brain*, Heap'te oluşturulur ve destructor'da delete edilir.
*/

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/*
** Dog Sınıfı (ex01)
** Animal'dan türetilmiş, Brain pointer'a sahip köpek.
** Brain*, Heap'te oluşturulur ve destructor'da delete edilir.
** Derin kopyalama uygulanır: new Brain(*other.brain)
*/
class Dog : public Animal
{
private:
	Brain* brain;	/* Heap'te oluşturulan beyin nesnesi */

public:
	Dog();									/* Varsayılan constructor - Brain oluşturur */
	Dog(const Dog& other);					/* Kopya constructor - derin kopya (new Brain) */
	Dog& operator=(const Dog& other);		/* Atama operatörü - derin kopya */
	~Dog();									/* Destructor - Brain'i siler */

	void makeSound() const;					/* Köpek sesi çıkarır */
	Brain* getBrain() const;				/* Brain pointer'ını döndürür */
};

#endif
