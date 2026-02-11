/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yayiker <yayiker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:42:44 by yayiker           #+#    #+#             */
/*   Updated: 2026/01/20 11:42:44 by yayiker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;
	
	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result += str.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();

	}
	result += str.substr(pos);
	
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return 1;
	}
	
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}
	
	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: could not create file " << outfilename << std::endl;
		infile.close();
		return 1;
	}
	
	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replaceAll(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}

