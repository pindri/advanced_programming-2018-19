/**
 * @file date.cc
 * @brief implementation of the Date class
 *
 * @author Patrick Indri
 * @date 14/01/19
 */

#include <iostream>
#include <map>
#include "date.h"


Invalid_day::Invalid_day(const std::string& s) { message = s; };


Date::Date(unsigned int _d, m_enum _m, int _y) 
{ 
  d=_d;
  m=_m;
  y=_y;


  m_days = {
    { m_enum::jan,    31},
    { m_enum::feb,    is_leap() ? 29 : 28},
    { m_enum::mar,    31},
    { m_enum::apr,    30},
    { m_enum::may,    31},
    { m_enum::jun,    30},
    { m_enum::jul,    31},
    { m_enum::aug,    31},
    { m_enum::sep,    30},
    { m_enum::oct,    31},
    { m_enum::nov,    30},
    { m_enum::dec,    31},
  };
  if (_d > m_days[_m])
    throw Invalid_day{"Invalid number of days. Month " + std::to_string(static_cast<int>(_m)) + " has at most " + std::to_string(m_days[_m]) + " days. You gave me " + std::to_string(_d ) + "."};
}

unsigned int Date::day() const {return d;}
m_enum Date::month() const {return m;}
int Date::year() const {return y;}

  bool Date::is_leap() {return y % 4 == 0 && y % 400 != 0;}
/* Implementing functions to add n days to a Date object */

  void Date::add_day() {
    if (d == m_days[m]) {
      if (m==m_enum::dec) {
        m=m_enum::jan;
        d=1;
        ++y;
      } else {
        m=static_cast<m_enum>(static_cast<int>(m)+1);
        d=1;
      }
    } else {
      ++d;
    }
  }

  void Date::add_days(const int n) {
    for (int i=0; i<n; ++i) Date::add_day();
  }

/* Operators to print and compare Date objects */

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.day() << "/" << static_cast<int>(date.month()) << "/" << date.year() << std::endl;
  return os;
}

bool operator==(const Date& lhs, const Date& rhs) {
  return lhs.day()==rhs.day() && lhs.month()==rhs.month() && lhs.year()==rhs.year();
}

bool operator!=(const Date& lhs, const Date& rhs) {
  return lhs.day()!=rhs.day() || lhs.month()!=rhs.month() || lhs.year()!=rhs.year();
}



