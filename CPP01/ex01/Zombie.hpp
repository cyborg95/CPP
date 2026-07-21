/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyborg95 <cyborg95@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:24:30 by cyborg95          #+#    #+#             */
/*   Updated: 2026/07/21 14:27:47 by cyborg95         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
public:          
    Zombie(void);
    ~Zombie(void);

    void setName(std::string name);
    void announce(void) const;
};
Zombie* zombieHorde(int N, std::string name);

#endif