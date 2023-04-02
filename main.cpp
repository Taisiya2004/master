#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Car {
private:
    string model;
public:

    string get_model()
    {
        return model;
    }

    Car(const string& _model) : model(_model) {}
    virtual void print() { 
        cout << "Модель: " << model << endl;
    }

    virtual ~Car() {}
};

class Mercedes : public Car {
public:
    Mercedes(const string& _model) : Car(_model) {}
    void print() {
        cout << "Мерседес " << get_model() << endl;
    }
};

class Audi : public Car {
public:
    Audi(const string& _model) : Car(_model) {}

    void print() {
        cout << "Ауди " << get_model() << endl;
    }
};

int main() {
    vector<Car*> cars; 

    ifstream file("cars.txt"); // открытие файла
    if (file.is_open()) {
       
        string brand, model;
        while (file>>brand>>model) { 

            Car* car; //указатель на новый объект
            if (brand == "Мерседес") {
                car = new Mercedes(model);
            }
            else if (brand == "Ауди") {
                car = new Audi(model);
            }
            else {
                car = new Car(model);
            }

            cars.push_back(car); 
        }
        
    }
    file.close(); // закрытие файла
    for (auto car : cars) { car->print(); }; 

    for (auto car : cars) { delete car; };

    return 0;
}
