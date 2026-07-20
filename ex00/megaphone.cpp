/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:05:14 by otidahoh          #+#    #+#             */
/*   Updated: 2026/07/20 15:34:24 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i = 1;
   
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (i < ac)
    {
        int j = 0;
        while (av[i][j])
        {
            std::cout << static_cast<char>(std::toupper(av[i][j]));
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return (0);
}