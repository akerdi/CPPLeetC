#include <iostream>

using namespace std;

#include "config.h"

#ifdef ENABLE_CPPLEETC
    #include <perfectMovement.h>
    #include <strReOrder.h>
#endif

int main(int argc, char** argv) {
    cout << "cppleetc: " << APP_VERSION_MAJOR << "." << APP_VERSION_MINOR << endl;
#ifdef ENABLE_CPPLEETC
    exec_perfectMovement();
    exec_strReOrder();
#endif
    return 0;
}