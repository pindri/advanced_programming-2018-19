/**
 * @file date.h
 * @brief Declaration of Date class.
 *
 * @author Patrick Indri
 * @date 14/01/19
 */

#ifndef DATE_H
#define DATE_H

#include<map>
#include<iostream>
#include<string>

/**
 * @brief Enum Class cointaining the months of a year.
 */
enum class m_enum {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

/**
 * @brief Struct for exceptions regarding incorrect number of days per month.
 */
struct Invalid_day {
  std::string message;
  Invalid_day(const std::string& s);
};


/**
 * @class Date
 * @brief Implement a date class
 *
 * Contains function to add days and check if a year is leap
 */
class Date {
  private:
    unsigned int d;
    m_enum m;
    int y;
  std::map<m_enum, unsigned int> m_days;

  public:
    //!Returns the value of the day variable.
    unsigned int day() const; 
    //!Returns the value of the month variable.
    m_enum month() const;
    //!Returns the value of the year variable.
    int year() const;

  //!Date constructor
  Date(unsigned int _d, m_enum _m, int _y);
  
  //!Checks if the year is leap
  /*! Returns True if the year is divisible by 4 or by 400
   * @param none
   * @return bool
   */
  bool is_leap();


  //! Adds a single day to the current date.
  /*!
   * Adds a single day checking if the month or the year needs to advance as well.
   * @param none
   * @return none
   */
  void add_day();

  //! Adds multiple days
  /*!
   * Calls add_day() n times.
   * @param n number of days to e added
   * @return none
   */
  void add_days(const int n);
};


std::ostream& operator<<(std::ostream& os, const Date& date); 
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs); 

#endif //DATE_H
