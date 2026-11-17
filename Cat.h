#ifndef CAT_H
#define CAT_H

#include <string>
#include <vector>

class Cat
{
public:
    Cat(const std::string& name);

    void introduce() const;
    void addItem(const std::string& item);
    bool hasItem(const std::string& item) const;
    bool useItem(const std::string& item);
    void showInventory() const;

private:
    std::string m_name;
    std::vector<std::string> m_inventory;
};

#endif
