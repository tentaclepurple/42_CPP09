/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:45:20 by imontero          #+#    #+#             */
/*   Updated: 2024/04/11 17:31:15 by imontero         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"
#include <cctype>

bool onlySpaces(const std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
        if (!isspace(str[i]))
            return false;
    return true; 
}

int	main(int argc, char **argv)
{
	if (argc != 2 ) return (std::cout << "Usage example: ./RPN \"2 3 + 4*\"" << std::endl, -1);

	std::string str(argv[1]);
	
	if (onlySpaces(str)) return (std::cout << "Usage example: ./RPN \"2 3 + 4*\" 🖕" << std::endl, -1);

	RPN inst;
	std::string check = "0123456789+-*/ ";
	int i = 0;
	while (str[i])
	{
		if (check.find(str[i]) == std::string::npos)
		{
			std::cout << "Error" << std::endl;
			return (-1);
		}
		if (isdigit(str[i]))
		{
			if (str[i + 1] && str[i + 1] != ' ')
			{
				std::cout << "Error" << std::endl;
				return (-1);
			}
			inst.pushNum(atoi(&str[i]));
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (!inst.operation(str[i]))
				return (-1);
		}
		i++;
	}
	std::cout << inst.topStack() << std::endl;
	return (0);
}