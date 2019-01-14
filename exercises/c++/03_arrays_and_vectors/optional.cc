/**
 * @file optional.cc
 * @brief reads from file and prints the words without repetition,
 * using std::vector, std::map and std::unordered_map
 *
 * @author Patrick Indri
 * @date 9/1/19
 */


#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<chrono>
#include<map>
#include<unordered_map>

int main() {

  std::string word, tmp;
  std::vector<std::string> text;
  std::map<std::string,int> text_map;
  std::unordered_map<std::string,int> text_un_map;
  



  //=============VECTOR============

  std::ifstream txt_file;
  txt_file.open ("LittleWomen.txt");

  auto start = std::chrono::high_resolution_clock::now();

  while(txt_file >> word){
    text.push_back(word);
  } 
  
  std::sort(text.begin(), text.end());
  
  int count=1;
  std::string previous_word;

  for (unsigned int i{0}; i < text.size(); i++){
  
    if (previous_word == text[i]) {
      count+=1;
    } else if (previous_word == "") {
      previous_word =text[i];
      continue;
    } else {
      std::cout << count << "\t" << previous_word << std::endl;
      count = 1;
    }

    previous_word = text[i];

  } std::cout << count << "\t" << previous_word << std::endl;

  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_vector = finish - start;



  //=========MAP====================================
  std::ifstream txt_file1;
  txt_file1.open ("LittleWomen.txt");

  start = std::chrono::high_resolution_clock::now();

  while(txt_file1 >> word){
    if (text_map.find(word) == text_map.end()) text_map.insert(make_pair(word, 1));
    else text_map[word]++;
  }


  std::map<std::string, int>::const_iterator itr;

  for (itr = text_map.begin(); itr != text_map.end(); ++itr){
    std::cout << itr->second << "\t" << itr->first << "\n";
  }


  finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed_map = finish - start;


  //========UNORDERED MAP=============================

  std::ifstream txt_file2;
  txt_file2.open ("LittleWomen.txt");
  
  start = std::chrono::high_resolution_clock::now();

  while(txt_file2 >> word){
    if (text_un_map.find(word) == text_un_map.end()) text_un_map.insert(make_pair(word, 1));
    else text_un_map[word]++;
  }

  std::unordered_map<std::string, int>::iterator um_itr;

  for (um_itr = text_un_map.begin(); um_itr != text_un_map.end(); ++um_itr){   
    std::cout << um_itr->second << "\t" << um_itr->first << "\n";
  }

  finish = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed_un_map = finish - start;

  //==========COMPARE TIMES=====================

  std::cout << "std::vector time: " << elapsed_vector.count() << " s\n";
  std::cout << "std::map timr: " << elapsed_map.count() << " s\n";
  std::cout << "std::unordered_map time: " << elapsed_un_map.count() << " s\n";


}
