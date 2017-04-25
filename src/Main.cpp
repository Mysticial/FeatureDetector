/* Main.cpp
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 04/17/2015
 * Last Modified    : 04/17/2015
 * 
 */

#include <iostream>
using std::cout;
using std::endl;

#include "x86/cpu_x86.h"
using namespace FeatureDetector;

int main(){

    cout << "CPU Vendor String: " << cpu_x86::get_vendor_string() << endl;
    cout << endl;

    cpu_x86::print_host();

    cpu_x86::print_warnings();

#if _WIN32
    system("pause");
#endif
}
