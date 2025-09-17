#include "headers/application.h"

#include "iostream"

using namespace std;
Application::Application() {

}

void Application::menu() {
    cout << "1 - Создать массив заданной длины" << endl;
    cout << "2 - Заполнить массив" << endl;
    cout << "3 - Изменить размерность массива" << endl;
    cout << "4 - Вывести элементы массива" << endl;
    cout << "5 - Вычислить среднее и СКО" << endl;
    cout << "6 - Сортировать по возрастанию" << endl;
    cout << "7 - Сортировать по убыванию" << endl;
    cout << "8 - Изменить значение выбранного элемента массива" << endl;
    cout << "9 - Выход" << endl;
}

int Application::exec() {
    int option, length;
    Array* array = new Array();
    while (true) {
        menu();
        cout << "Выберите вариант: " << endl;
        cin >> option;

        switch (option) {
        case 1:
        {
            cout << "Введите длину массива" << endl;
            cin >> length;
            array = new Array(length);
            break;
        }
        case 2:
        {
            cout << "Введите элементы для заполнения массива";
            array->add();
            break;
        }
        case 3:
        {
            cout << "Введите новую длину массива";
            cin >> length;
            length = array->changeLength(length);
            cout << length;
            break;
        }
        case 4:
        {
            cout << "Ваш массив: ";
            array->printArray();
            cout << "\n";
            break;
        }
        case 5:
        {
            cout << "Среднее значение: " << array->average() << ", ";
            cout << "СКО: " << array->sko() << endl;
            break;
        }
        case 6:
        {
            cout << "Исходный массив: ";
            array->printArray();
            cout << "Отсортированный по возрастанию: ";
            array->sortIncrease();
            array->printArray();
            break;
        }
            case 7:
        {
            cout << "Исходный массив: ";
            array->printArray();
            cout << "Отсортированный по убыванию: ";
            array->sortDecrease();
            array->printArray();
            break;
        }
        case 8:
        {
            int index, value;
            cout << "Исходный массив: ";
            array->printArray();
            cout << "Введите индекс элемента для изменения: ";
            cin >> index;
            array->changeElem(index);
            cout << "Измененный массив: ";
            array->printArray();
            break;
        }
        case 9:
        {
            return 0;
        }
        default:
        {
            cout << "Введите корректное значение";
        }
        }
    }
}