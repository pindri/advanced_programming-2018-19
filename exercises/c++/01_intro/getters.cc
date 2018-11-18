#include <iostream>
#include <string>

int get_int(){
    
    std::cout << "Insert an integer" << std::endl;

    int i;
    while(!(std::cin >> i)){
        std::cout << "Invalid input\n";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cout << "You have fed: " << i << std::endl;

    return i;
}


double get_double(){
    
    std::cout << "Insert a double" << std::endl;

    double i;
    while(!(std::cin >> i)){
        std::cout << "Invalid input\n";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cout << "You have fed: " << i << std::endl;

    return i;
}




int main(){ 
    
    get_int();

    get_double();

    return 0;    
}