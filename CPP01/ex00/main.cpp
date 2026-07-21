/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyborg95 <cyborg95@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:10:59 by cyborg95          #+#    #+#             */
/*   Updated: 2026/07/21 14:11:48 by cyborg95         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();
    
    delete zombie1;
    
    randomChump("Zombie2");
    
    return 0;
}