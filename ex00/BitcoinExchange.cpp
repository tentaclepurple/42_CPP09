/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:01:05 by imontero          #+#    #+#             */
/*   Updated: 2024/01/25 17:09:59 by imontero         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->getData();
	return;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
	return;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	*this = rhs;
	return *this;
}

void BitcoinExchange::getData()
{
	std::ifstream data("data.csv");

	if (!data.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return;
	}

	std::string line;
	std::string date;
	std::string rate;

	std::getline(data, line); // skip first line
	while (std::getline(data, line))
	{
		date = line.substr(0, line.find(','));
		rate = line.substr(line.find(',') + 1, line.length());
		_db[date] = std::atof(rate.c_str());
	}
	data.close();
}

void	BitcoinExchange::calculateBalance(const char *inFile)
{
	std::ifstream file(inFile);
	if (!file.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return ;
	}
	std::string line;
	std::string date;
	float amount;
	
	std::getline(file, line); // skip first line
	while (std::getline(file, line))
	{
		if (line.empty() || line.length() < 12)
		{
			std::cout << "Error: Bad input => " << line << std::endl;
			continue;
		}
		size_t div = line.find_first_of(" |");
		date = line.substr(0, div);
		amount = std::atof(line.substr(line.find('|') + 2).c_str());
		if (!checkDate(date)){

			std::cout << "Error: Bad date => " << date << std::endl;
		}
		else if (amount < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (amount > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else
		{
			std::map<std::string, float>::const_iterator it = this->_db.upper_bound(date);
			//std::cout << "date*: " << date << std::endl;
			if (it->first.compare(date) != 0)
				--it;
			std::cout << date << " => " << amount << " = " << it->second*amount << "\n";
		}
	}
	file.close();
}

/* checks if the date is between 0000-00-00 and 2024-01-01 */
bool	BitcoinExchange::checkDate(const std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);


	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return false;
	if (std::atoi(year.c_str()) < 0 || std::atoi(year.c_str()) > 2024)
		return false;
	if (std::atoi(month.c_str()) < 0 || std::atoi(month.c_str()) > 12)
		return false;
	if (std::atoi(day.c_str()) < 0 || std::atoi(day.c_str()) > 31)
		return false;
	if (std::atoi(year.c_str()) < 2009 || (atoi(year.c_str()) == 2009 && atoi(month.c_str()) == 1 && atoi(day.c_str()) < 2))
		return false;
	return true;
}

