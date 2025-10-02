#include "headers/application.h"
#include "windows.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Application application = Application();
    application.allMenu();
    return 0;
}