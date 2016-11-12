#include <iostream>
#include <locale>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
    struct tm t;
    istringstream ss("01/01/2000-01:00:00");
    const char* format = "%d/%m/%Y-%H:%M:%S";
    ss.imbue(locale("en_US.utf-8"));
    ss >> get_time(&t, format);
    
    time_t hehe = timelocal(&t);
    
    cout << hehe <<endl;
    
    return 0;
}
