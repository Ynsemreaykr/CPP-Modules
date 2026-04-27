/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:04 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:04 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WrongCat Sınıfı Header Dosyası
** WrongAnimal'dan türetilmiş, polimorfizmin çalışmadığını gösteren kedi sınıfı.
** makeSound() override eder ama WrongAnimal pointer üzerinden çağrılamaz (virtual yok).
*/

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

/*
** WrongCat Sınıfı (Yanlış Uygulama - Karşılaştırma Amaçlı)
** WrongAnimal'dan türetilmiş. makeSound() override eder.
** Ancak WrongAnimal* pointer üzerinden bu versiyon çağrılamaz!
** Animal/Cat ile karşılaştırıldığında virtual'ın önemi anlaşılır.
*/
class WrongCat : public WrongAnimal
{
public:
	WrongCat();										/* Varsayılan constructor */
	WrongCat(const WrongCat& other);				/* Kopya constructor */
	WrongCat& operator=(const WrongCat& other);		/* Atama operatörü */
	~WrongCat();									/* Destructor */

	void makeSound() const;							/* Override ama virtual olmadığı için polimorfizm yok */
};

#endif
