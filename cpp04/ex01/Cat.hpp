/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:17 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:17 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cat Sınıfı Header (ex01 - Brain ile Derin Kopyalama)
** ex00'a ek olarak Brain* pointer eklendi.
** getBrain() ile Brain nesnesine erişilir.
** Derin kopya: Kopyalamada yeni Brain nesnesi oluşturulur.
*/

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/*
** Cat Sınıfı (ex01)
** Animal'dan türetilmiş, Brain pointer'a sahip kedi.
** Brain*, Heap'te oluşturulur ve destructor'da delete edilir.
** Derin kopyalama uygulanır: new Brain(*other.brain)
*/
class Cat : public Animal
{
private:
	Brain* brain;	/* Heap'te oluşturulan beyin nesnesi */

public:
	Cat();									/* Varsayılan constructor - Brain oluşturur */
	Cat(const Cat& other);					/* Kopya constructor - derin kopya (new Brain) */
	Cat& operator=(const Cat& other);		/* Atama operatörü - derin kopya */
	~Cat();									/* Destructor - Brain'i siler */

	void makeSound() const;					/* Kedi sesi çıkarır */
	Brain* getBrain() const;				/* Brain pointer'ını döndürür */
};

#endif
