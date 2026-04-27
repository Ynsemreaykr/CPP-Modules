/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:53:51 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:53:51 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cat Sınıfı Header Dosyası
** Animal'dan türetilmiş kedi sınıfı.
** makeSound() override edilerek kedi sesini ("Meow!") çıkarır.
*/

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/*
** Cat Sınıfı
** Animal temel sınıfından türetilmiş.
** makeSound() "Meow! Meow!" çıkarır (polimorfik davranış).
** type = "Cat" olarak ayarlanır.
*/
class Cat : public Animal
{
public:
	Cat();									/* Varsayılan constructor */
	Cat(const Cat& other);					/* Kopya constructor */
	Cat& operator=(const Cat& other);		/* Atama operatörü */
	~Cat();									/* Destructor */

	void makeSound() const;					/* "Meow!" sesini çıkarır */
};

#endif
