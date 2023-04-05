#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


class Car {
private:
    const std::string model;
    const std::string brand;
public:

    const std::string& get_model()
    {
        return model;
    }
    const std::string& get_brand() {
        return brand;
    }

    Car(const std::string& _model, const std::string& _brand) : model(_model), brand(_brand) {}
    virtual void print() = 0;

    ~Car() {}
};

class Mercedes : public Car {
public:
    Mercedes(const std::string& _model, const std::string& _brand) : Car(_model, _brand) {}
    void print() override {
        std::cout << get_brand() << ": \n" << get_model() << std::endl;
    }
};

class Audi : public Car {
public:
    Audi(const std::string& _model, const std::string& _brand) : Car(_model, _brand) {}

    void print() override {
        std::cout << get_brand() << ": \n" << get_model() << std::endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Car*> cars;

    std::ifstream file("cars.txt"); // открытие файла
    if (file.is_open()) {

        std::string brand, model;
        while (file >> brand >> model) {

            Car* car; //указатель на новый объект
            if (brand == "Мерседес") {
                car = new Mercedes(model, brand);
            }
            else if (brand == "Ауди") {
                car = new Audi(model, brand);
            }
            else {
                car = new Car(model, brand);
            }

            cars.push_back(car);
        }

    }
    file.close(); // закрытие файла
    for (auto car : cars) { car->print(); };

    for (auto car : cars) { delete car; };

    return 0;
}


