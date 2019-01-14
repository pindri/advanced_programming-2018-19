/**
 * @file uom.cc
 * @brief Converts inches in meters and the other way around.
 *
 * @author Patrick Indri
 * @date 10/10/18
 */

#include <iostream>
#include <string>

void conversion(){

    std::string uom;
    double value;

    std::cout << "Insert a value and its unit of measure ('in' or 'm')" << std::endl;
    std::cin >> value >> uom;

    if (uom == "in") {
        std::cout << value*0.0254 << " " << "m" << std::endl;
    }
    else if (uom == "m") {
        std::cout << value/0.0254 << " " << "in" << std::endl;
    }
    else {
        std::cout << "Invalid input" << std::endl;
    }

}



int main(){

    conversion();

    return 0;
}
