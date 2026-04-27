/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:34 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:34 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Animal Sınıfı Header (ex02 - Soyut Sınıf / Abstract Class)
** ex01'den farklı: makeSound() = 0 (pure virtual) - SOYUT FONKSİYON.
** Bu sayede Animal nesnesi doğrudan oluşturulamaz (derleme hatası).
** Alt sınıflar (Cat, Dog) makeSound() implement etmek ZORUNDADIR.
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

/*
** Animal Sınıfı (Soyut - Abstract)
** makeSound() = 0 -> Saf sanal fonksiyon (pure virtual).
** Animal nesnesi doğrudan oluşturulamaz: const Animal a; -> DERLEME HATASI!
** Sadece implement eden alt sınıflar oluşturulabilir.
** Arayüz/sözleşme tanımlar: Her hayvan ses çıkarmak zorundadır.
*/
class Animal
{
protected:
	std::string type;	/* Hayvanın türü */

public:
	Animal();									/* Varsayılan constructor */
	Animal(const Animal& other);				/* Kopya constructor */
	Animal& operator=(const Animal& other);		/* Atama operatörü */
	virtual ~Animal();							/* Virtual destructor */

	virtual void makeSound() const = 0;			/* SAF SANAL - alt sınıf implement etmeli */
	std::string getType() const;				/* Tür ismi getter'ı */
};

#endif
