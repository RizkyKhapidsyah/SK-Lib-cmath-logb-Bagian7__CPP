#pragma warning(disable:4996)
#pragma fenv_access(on)

#include <iostream>
#include <cmath>
#include <limits>
#include <cfenv>
#include <conio.h>

int main() {
    double x = 647.98;
    std::cout << "Given the number " << x << " or " << std::hexfloat << x << std::defaultfloat << " in hex,\n";

    double x3;
    double x2 = std::modf(x, &x3);
    std::cout << "modf() makes " << x3 << " + " << x2 << '\n';

    int i;
    x2 = std::frexp(x, &i);
    std::cout << "frexp() makes " << x2 << " * 2^" << i << '\n';

    i = std::ilogb(x);
    std::cout << "logb()/ilogb() make " << x / std::scalbn(1.0, i) << " * " << std::numeric_limits<double>::radix << "^" << std::ilogb(x) << '\n';

    // error handling
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "logb(0) = " << std::logb(0) << '\n';

    if (std::fetestexcept(FE_DIVBYZERO)) {
        std::cout << "    FE_DIVBYZERO raised\n";
    }
        
    _getch();
    return 0;
}