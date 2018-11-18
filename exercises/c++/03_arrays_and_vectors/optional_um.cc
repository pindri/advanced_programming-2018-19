#include<iostream>
#include<string>
#include<algorithm>
#include<chrono>
#include<unordered_map>

int main() {

  std::string word, tmp;
  std::unordered_map<std::string, int> umtext;
  
  auto start = std::chrono::high_resolution_clock::now();

  while(std::cin >> word){
    if (umtext.find(word) == umtext.end()) umtext.insert(make_pair(word, 1));
    else umtext[word]++;
  }

  std::unordered_map<std::string, int>::iterator itr;

  for (itr = umtext.begin(); itr != umtext.end(); ++itr){   
    std::cout << itr->first << ": " << (itr->second) << "\n";
  }

  auto finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = finish - start;

  std::cout << "std::vector time: " << elapsed.count() << " s\n";


}

