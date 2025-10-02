#include "headers/application.h"
#include "headers/polynom.h"
#include "iostream"

using namespace std;
Application::Application() {
}

void Application::menu() {
    cout << "МЕНЮ РАБОТЫ С МАССИВОМ" << endl;
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
void Application::menuPolynom() {
    cout << "МЕНЮ РАБОТЫ С ПОЛИНОМОМ" << endl;
    cout << "1 - Создать полином 0-й степени" << endl;
    cout << "2 - Ввести полином n-й степени" << endl;
    cout << "3 - Вывести полином в форме 1 (anx^n + ... + a0)" << endl;
    cout << "4 - Вывести полином в форме 2 (an(x-rn)...(x-r1))" << endl;
    cout << "5 - Вычислить значение полинома в точке" << endl;
    cout << "6 - Выход" << endl;
}
int Application::polynomExec() {
    int option;
    Polynom* polynom = new Polynom(); // Полином по умолчанию

    while (true) {
        menuPolynom();
        cout << "Выберите вариант: ";
        cin >> option;

        switch (option) {
            case 1: {
                delete polynom;
                polynom = new Polynom();
                cout << "Создан полином по умолчанию (нулевой степени)" << endl;
                break;
            }
            case 2: {
                polynom->input(cin);
                cout << "Полином успешно введен" << endl;
                break;
            }
            case 3: {
                cout << "Полином в форме 1: ";
                polynom->outputForm1(cout);
                cout << endl;
                break;
            }
            case 4: {
                cout << "Полином в форме 2: ";
                polynom->outputForm2(cout);
                cout << endl;
                break;
            }
            case 5: {
                number x, result;
                cout << "Введите точку x для вычисления: ";
                cin >> x;
                result = polynom->findNumberInPoint(x);
                cout << "Значение полинома в точке " << x << " равно: " << result << endl;
                break;
            }
            case 6: {
                delete polynom;
                allMenu();
            }
            default: {
                cout << "Введите корректное значение" << endl;
            }
        }
    }
}
int Application::allMenu() {
    int option;
    while (true) {
        cout << "1 - действия с массивом"<< endl;
        cout << "2 - действия с полиномом"<< endl;
        cin >> option;
        switch (option) {
            case 1:
                {
                exec();
                break;
            }
            case 2: {
                polynomExec();
                break;
            }


        }
    }
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