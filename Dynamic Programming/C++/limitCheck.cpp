#include <iostream>
#include <limits>

int main() {

    std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "Minimum value of int: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "Maximum value of int: " << std::numeric_limits<int>::max() << std::endl;

    std::cout << "Size of long int: " << sizeof(long int) << " bytes" << std::endl;
    std::cout << "Minimum value of long int: " << std::numeric_limits<long int>::min() << std::endl;
    std::cout << "Maximum value of long int: " << std::numeric_limits<long int>::max() << std::endl;

    std::cout << "Size of int64_t int: " << sizeof(int64_t) << " bytes" << std::endl;
    std::cout << "Minimum value of int64_t int: " << std::numeric_limits<int64_t>::min() << std::endl;
    std::cout << "Maximum value of int64_t int: " << std::numeric_limits<int64_t>::max() << std::endl;

    return 0;
}
