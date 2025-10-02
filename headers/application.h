#include "array.h"
#include "number.h"

#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
public:
    Array* globalArray;
    Application();
    int exec();
    int allMenu();
    int polynomExec();
private:
    void menu();
    void menuPolynom();
};

#endif // APPLICATION_H