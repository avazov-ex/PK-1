#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Product { //определяет тип данных "Product" в программе
    string tovar; 
    int quanty;
    double price;
};

bool compareNames(const Product& p1, const Product& p2) {
    return p1.tovar < p2.tovar; //возвращает true, если имя первого объекта  меньше имени второго объекта 
}

int main() {
    int nomerp;
    cout << "Введите количество проданных товаров: ";
    cin >> nomerp;
    
    Product* prod = new Product[nomerp]; //Создается указатель на объект типа Product, который будет выделять память под массив из nomerp элементов
    
    for (int i = 0; i < nomerp; i++) { //В цикле происходит ввод данных о товаре с клавиатуры: название, количество и цена за единицу товара. Все данные сохраняются в соответствующих полях структуры Product
        cout << "Введите название товара: ";
        cin >> prod[i].tovar;
        cout << "Введите количество единиц товара: ";
        cin >> prod[i].quanty;
        cout << "Введите цену за единицу товара: ";
        cin >> prod[i].price;
    }
    
    double totalSales = 0;
    double totalSals = 0;
    
    for (int i = 0; i < nomerp; i++) {
        totalSales += prod[i].quanty * prod[i].price; //Вычисляется общая сумма продаж, умножая количество единиц товара на его цену и суммируя результаты для каждого товара
        totalSals += prod[i].price;
    }
    
    double averagePrice = totalSals / nomerp; //Вычисляется средняя цена товаров, разделив общую сумму продаж на количество товаров
    
    sort(prod, prod + nomerp, compareNames);  //Массив продуктов сортируется по имени с помощью функции compareNames
    
   
    
    for (int i = 0; i < nomerp; i++) {
     cout << prod[i].tovar<< " - Количество: " << prod[i].quanty << ", Цена за единицу: " << prod[i].price << endl;
   
    }
    delete[] prod;
    cout << "Общая сумма продаж: " << totalSales << endl;
    cout << "Средняя цена за единицу товара: " << averagePrice << endl;
    
    return 0;
}