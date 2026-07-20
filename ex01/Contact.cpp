/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:24:03 by otidahoh          #+#    #+#             */
/*   Updated: 2026/07/20 17:58:07 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

static std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

Contact::Contact(){}

void Contact::setContact() { 
    std::cout << "First name: ";
    std::getline(std::cin, firstName);
    
    std::cout << "Last name: ";
    std::getline(std::cin, lastName);

    std::cout << "Nickname: ";
    std::getline(std::cin, nickName);
    
    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);

}

void Contact::displayShort(int index) const
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << formatField(firstName) << "|";
    std::cout << std::setw(10) << formatField(lastName) << "|";
    std::cout << std::setw(10) << formatField(nickName) << std::endl;
}

void Contact::displayFull() const
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nick name: " << nickName << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
}