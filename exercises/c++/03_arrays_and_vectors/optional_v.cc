#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<chrono>
#include<map>

int main() {

  std::string word, tmp;
  std::vector<std::string> text;
  
  auto start = std::chrono::high_resolution_clock::now();

  while(std::cin >> word){
    text.push_back(word);
  } 
  
  std::sort(text.begin(), text.end());
  
  for (int i{0}; i < text.size(); i++){
    
    if (tmp != text[i]) std::cout << text[i] << std::endl;

    tmp = text[i];

  }


  auto finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = finish - start;

  std::cout << "std::vector time: " << elapsed.count() << " s\n";


}

