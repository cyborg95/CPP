/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:46:14 by otidahoh          #+#    #+#             */
/*   Updated: 2026/07/20 18:08:21 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "PhoneBook.hpp"
#include    <iomanip>

PhoneBook::PhoneBook()
{
    count = 0;
    oldest = 0;
}
void    PhoneBook::addContact()
{
    if (count < 8)
    {
        contacts[count].setContact();
        count++;
    }
    else
    {
        contacts[oldest].setContact();
        oldest = (oldest + 1) % 8;
    }
}

void PhoneBook::searchContact() const
{
    if (count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
        contacts[i].displayShort(i);

    std::string input;

    std::cout << "Index: ";
    std::getline(std::cin, input);

    if (input.length() != 1 || input[0] < '0' || input[0] >= '0' + count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int index = input[0] - '0';

    contacts[index].displayFull();
}
