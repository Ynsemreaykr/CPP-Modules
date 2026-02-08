/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:46:04 by yayiker           #+#    #+#             */
/*   Updated: 2025/09/15 13:46:05 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** MEGAPHONE - Büyük Harf Dönüştürücü
** Bu program, komut satırından aldığı tüm argümanları büyük harfe çevirir.
** Argüman verilmezse varsayılan bir mesaj gösterir.
*/

#include <iostream>
#include <cctype>

/*
** main - Program giriş noktası
** @argc: Argüman sayısı
** @argv: Argüman dizisi
**
** Tüm komut satırı argümanlarını büyük harfe çevirir ve ekrana yazdırır.
** Argüman yoksa "* LOUD AND UNBEARABLE FEEDBACK NOISE *" mesajını gösterir.
** Return: Her zaman 0
*/
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			std::cout << static_cast<char>(std::toupper(argv[i][j++]));
		if (argv[i + 1])
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}
