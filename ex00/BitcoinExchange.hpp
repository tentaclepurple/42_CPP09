/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:56:53 by imontero          #+#    #+#             */
/*   Updated: 2023/12/28 11:56:53 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
		
		void	getData();
		void	calculateBalance(const char *inFile);
		bool	checkDate(const std::string date);
		//bool	checkAmount(const int amount);
};


#endif
