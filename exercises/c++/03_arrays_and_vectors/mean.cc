#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<math.h>


int main(){
  
  std::vector<double> v0, vsort;

  double value;

  std::ifstream txt_file;
  txt_file.open ("temperatures.txt");

  while(txt_file >> value){
    v0.push_back(value);
  }

 // for (int i{0}; i<v0.size(); i++)  std::cout << v0[i] << std::endl;
  int count{0};
  double mean{0}, median{0};
  for (int i{0}; i<v0.size(); i++){
     mean += v0[i];
     count += 1;
  }
 
  mean = mean/v0.size();

  std::cout << "mean: " << mean << std::endl;

  std::sort(v0.begin(), v0.end());

 // for (int i{0}; i<v0.size(); i++)  std::cout << v0[i] << std::endl;

  if (v0.size() != 0) median = v0[floor(v0.size()*0.5)];
  else median = (v0[0.5*v0.size()] + v0[0.5*v0.size()])*0.5;

  std::cout << "median: " << median << std::endl;



}
