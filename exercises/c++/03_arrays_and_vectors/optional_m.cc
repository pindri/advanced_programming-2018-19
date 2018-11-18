#include<iostream>
#include<string>
#include<algorithm>
#include<chrono>
#include<map>

int main() {

  std::string word, tmp;
  std::map<std::string, int> mtext;
  
  auto start = std::chrono::high_resolution_clock::now();

  int i{0};

  std::pair<std::map<std::string, int>::iterator, bool> add;

  while(std::cin >> word){
    add = mtext.insert(std::pair<std::string, int>(word, 1));
    if (add.second == false) mtext[word]++;
  }


  std::map<std::string, int>::const_iterator itr;

  for (itr = mtext.begin(); itr != mtext.end(); ++itr){   
    std::cout << itr->first << ": " << (itr->second) << "\n";
  }


  auto finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = finish - start;

  std::cout << "std::vector time: " << elapsed.count() << " s\n";


}

