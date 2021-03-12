#include <iostream>
#include <iomanip>

int main(int, char**) 
{
    int fahr;
    for ( fahr = -100; fahr <= 400; fahr += 25)
    {
        // printf("Fahr  = %d\t Cels = %f\n ", fahr, 5./9. * (fahr-32));
        std::cout << "fahr = " << std::setw(5) << fahr
                  << ", cels = " << std::setw(8)  << 5./9. * (fahr-32)
                  << std::endl;
    }
    return 0;
}

