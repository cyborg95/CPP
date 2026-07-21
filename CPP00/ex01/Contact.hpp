/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otidahoh <otidahoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:09:48 by otidahoh          #+#    #+#             */
/*   Updated: 2026/07/20 17:23:05 by otidahoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;

public:
    Contact();
        
    void    setContact();
        
    void    displayShort(int index) const;
        
    void    displayFull() const;
    
};

#endif