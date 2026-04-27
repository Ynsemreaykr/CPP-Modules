/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:54:00 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/27 09:54:00 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** WrongAnimal Sınıfı Header Dosyası
** Animal'ın YANLIŞ versiyonu - makeSound() virtual DEĞİL.
** Bu, polimorfizmin çalışmadığını göstermek için karşılaştırma amacıyla kullanılır.
** WrongAnimal pointer üzerinden WrongCat::makeSound() çağrılamaz!
*/

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

/*
** WrongAnimal Sınıfı (Yanlış Uygulama - Karşılaştırma Amaçlı)
** makeSound() virtual OLMADIGI için WrongAnimal pointer'dan doğru türetilmiş sınıf sesi çıkmaz.
** Bu, virtual anahtar kelimesinin önemini vurgulamak için kasıtlı olarak hatalı yazılmıştır.
*/
class WrongAnimal
{
protected:
	std::string type;	/* Hayvanın türü */

public:
	WrongAnimal();									/* Varsayılan constructor */
	WrongAnimal(const WrongAnimal& other);			/* Kopya constructor */
	WrongAnimal& operator=(const WrongAnimal& other);	/* Atama operatörü */
	~WrongAnimal();									/* Destructor (virtual DEĞİL!) */

	void makeSound() const;  	/* virtual YOK - polimorfizm çalışmaz! */
	std::string getType() const;				/* Tür ismini döndürür */
};

#endif
