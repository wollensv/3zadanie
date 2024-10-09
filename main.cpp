#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Overcoat {
private:
    string name;
    string type;
    int size;
    double price;

public:
    Overcoat() : name("Unknown"), type("Unknown"), size(0), price(0.0) {}
    Overcoat(string n, string t, int s, double p) : name(n), type(t), size(s), price(p) {}

    void setName(const string& n) { name = n; }
    void setType(const string& t) { type = t; }
    void setSize(int s) { size = s; }
    void setPrice(double p) { price = p; }

    string getName() const { return name; }
    string getType() const { return type; }
    int getSize() const { return size; }
    double getPrice() const { return price; }

    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    bool operator!=(const Overcoat& other) const {
        return !(*this == other);
    }

    bool operator>(const Overcoat& other) const {
        return price > other.price;
    }

    bool operator>=(const Overcoat& other) const {
        return price >= other.price;
    }

    bool operator<(const Overcoat& other) const {
        return price < other.price;
    }

    bool operator<=(const Overcoat& other) const {
        return price <= other.price;
    }

    Overcoat& operator++() {
        size++;
        return *this;
    }

    Overcoat operator++(int) {
        Overcoat temp = *this;
        size++;
        return temp;
    }

    Overcoat& operator--() {
        size--;
        return *this;
    }

    Overcoat operator--(int) {
        Overcoat temp = *this;
        size--;
        return temp;
    }

    friend istream& operator>>(istream& in, Overcoat& overcoat) {
        cout << "Введіть найменування: ";
        in >> overcoat.name;
        cout << "Введіть тип: ";
        in >> overcoat.type;
        cout << "Введіть розмір: ";
        in >> overcoat.size;
        cout << "Введіть ціну: ";
        in >> overcoat.price;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Overcoat& overcoat) {
        out << "Найменування: " << overcoat.name << ", Тип: " << overcoat.type 
            << ", Розмір: " << overcoat.size << ", Ціна: " << overcoat.price;
        return out;
    }
};

class Shop {
private:
    vector<Overcoat> shop;

public:
    void addOvercoat(const Overcoat& overcoat) {
        shop.push_back(overcoat);
    }

    void removeOvercoat(int index) {
        if (index >= 0 && index < shop.size()) {
            shop.erase(shop.begin() + index);
        } else {
            cout << "Неправильний індекс!" << endl;
        }
    }

    void editSize(int index, int newSize) {
        if (index >= 0 && index < shop.size()) {
            shop[index].setSize(newSize);
        } else {
            cout << "Неправильний індекс!" << endl;
        }
    }

    void searchByType(const string& type) {
        for (const auto& overcoat : shop) {
            if (overcoat.getType() == type) {
                cout << overcoat << endl;
            }
        }
    }

    void sortByPrice() {
        std::sort(shop.begin(), shop.end(), [](const Overcoat& a, const Overcoat& b) {
            return a.getPrice() < b.getPrice();
        });
    }

    void display() const {
        for (const auto& overcoat : shop) {
            cout << overcoat << endl;
        }
    }
};

int main() {
    Shop shop;
    Overcoat oc1("Куртка", "Чоловічий", 42, 150.0);
    Overcoat oc2("Пальто", "Жіночий", 38, 200.0);
    Overcoat oc3("Куртка", "Дитячий", 30, 100.0);

    shop.addOvercoat(oc1);
    shop.addOvercoat(oc2);
    shop.addOvercoat(oc3);

    cout << "Початковий список верхнього одягу:" << endl;
    shop.display();

    cout << "Сортування за ціною:" << endl;
    shop.sortByPrice();
    shop.display();

    cout << "Пошук жіночого одягу:" << endl;
    shop.searchByType("Жіночий");

    cout << "Редагування розміру першого елемента:" << endl;
    shop.editSize(0, 44);
    shop.display();

    cout << "Видалення другого елемента:" << endl;
    shop.removeOvercoat(1);
    shop.display();

    return 0;
}
