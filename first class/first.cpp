#include <iostream>
#include <vector>
#include <string>

class HouseholdItem {
private:
    std::string name;
    std::string category;
    double price;

public:
    HouseholdItem(std::string n, std::string c, double p) : name(n), category(c), price(p) {}

    void display() const {
        std::cout << "Название предмета: " << name << ", Категория: " << category << ", Цена: " << price << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<HouseholdItem> items;
    std::string name, category;
    double price;
    char more;
    do {
        std::cout << "Введите имя предмета: ";
        std::getline(std::cin, name);
        std::cout << "Введите категорию предмета: ";
        std::getline(std::cin, category);
        std::cout << "Введите цену предмета: ";
        std::cin >> price;
        std::cin.ignore();

        items.emplace_back(name, category, price);

        std::cout << "Хотите добавить ещё предмет (y/n): ";
        std::cin >> more;
        std::cin.ignore(); 
    } while (more == 'y' || more == 'Y');

    std::cout << "\nКаталог предметов:\n";
    for (const auto& item : items) {
        item.display();
    }

    return 0;
}
