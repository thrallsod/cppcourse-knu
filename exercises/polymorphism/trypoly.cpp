#include "Polygons.hpp"
#include <iostream>

int main() {

    Pentagon p(10);
    std::cout << "Pentagon perimeter: " << p.computePerimeter() << std::endl;

    Hexagon h(10);
    std::cout << "Hexagon perimeter: " << h.computePerimeter() << std::endl;

    // Step 2 - Call Hexagon method through base class reference
    RegularPolygon& ref = h;
    std::cout << "Hexagon via base ref: " << ref.computePerimeter() << std::endl;


    return 0;
// output before virtual
//Pentagon perimeter: Polygon::computePerimeter is being called
//58.7785
//Hexagon perimeter: Hexagon::computePerimeter is being called
//60
//Hexagon via base ref: Polygon::computePerimeter is being called
//60
// output after virtual
//    Pentagon perimeter: Polygon::computePerimeter is being called
//    58.7785
//    Hexagon perimeter: Hexagon::computePerimeter is being called
//    60
//    Hexagon via base ref: Hexagon::computePerimeter is being called
//    60

}
