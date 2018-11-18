#include <iostream>
#include <string>


int split_line(int n, std::string line){

    int pos;
    std::string newline;

    for(pos = n; pos >= 0; --pos) {

        if (line[pos] == ' '){

            std::cout << pos << "\t" << line.substr(0, pos) << std::endl;
            newline = line.substr(pos + 1, line.size());

            if (newline.length() > n) {

                split_line(n, newline);

            } else {

                std::cout << newline.length() << "\t" << newline << std::endl;

            }
            break;
        }

        if (pos == 0) std::cout << line.length() << "\t" << line << std::endl;
    } 

    return 0;
}



void formatter(int n){

    std::string line;

    while(std::getline(std::cin,line)){

        if (line.length() > n) {
            split_line(n, line);
        } else std::cout << line.length() << "\t" << line << std::endl;
   
    }


}





int main(){

    formatter(49);
    return 0;
}