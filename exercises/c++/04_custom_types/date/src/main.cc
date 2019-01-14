/**
 * @file main.cc
 * @brief Tests the Date class
 *
 * @author Patrick Indri
 * @date 14/01/19
 */

#include<iostream>
#include<map>
#include"date.h"

int main() {


  Date test1 = Date(28, m_enum::feb, 2004);
  Date comparison = Date(28, m_enum::feb, 2004);

  test1 == comparison ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

  std::cout << test1 << std::endl;

  test1.add_days(4);

  test1 == comparison ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
  std::cout << test1 << std::endl;

  Date test2 = Date(23, m_enum::dec, 2005);

  test2.add_days(10);

  std::cout << test2 << std::endl;

  try{
    Date error = Date(31, m_enum::feb, 2004);
  } catch ( const Invalid_day& s ) {
    std::cerr << s.message << std::endl;
    return 1;
  }

  return 0;
}
