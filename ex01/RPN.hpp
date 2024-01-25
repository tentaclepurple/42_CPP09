/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:59:36 by imontero          #+#    #+#             */
/*   Updated: 2023/12/28 16:59:36 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN( void );
		RPN( RPN const & rhs );
		~RPN( void );

		RPN & operator=(RPN const & rhs);

		bool	operation(const char op);
		
		void 	pushNum(const int num);
		int		topStack(void) const;
		
};



#endif

