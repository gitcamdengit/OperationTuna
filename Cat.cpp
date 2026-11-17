#include "Cat.h"

#include <algorithm>
#include <iostream>

Cat::Cat(const std::string& name)
    : m_name(name)
{
}

void Cat::introduce() const
{
    std::cout << "You are " << m_name
              << ", a cat with a very important mission.\n";
}

bool Cat::hasItem(const std::string& item) const
{
    return std::find(m_inventory.begin(), m_inventory.end(), item)
           != m_inventory.end();
}

void Cat::addItem(const std::string& item)
{
    if (!hasItem(item))
    {
        m_inventory.push_back(item);
        std::cout << "Added to inventory: " << item << "\n";
    }
    else
    {
        std::cout << "You already have that item.\n";
    }
}

bool Cat::useItem(const std::string& item)
{
    std::vector<std::string>::iterator found =
        std::find(m_inventory.begin(), m_inventory.end(), item);

    if (found == m_inventory.end())
    {
        return false;
    }

    m_inventory.erase(found);
    return true;
}

void Cat::showInventory() const
{
    if (m_inventory.empty())
    {
        std::cout << "Inventory: (empty)\n";
        return;
    }

    std::cout << "Inventory:\n";
    for (const std::string& item : m_inventory)
    {
        std::cout << "- " << item << "\n";
    }
}
