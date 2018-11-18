#include<iostream>
#include<map>





enum class m_enum {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};


class Date {
  private:
    unsigned int d;
    m_enum m;
    int y;

  public:
    unsigned int day() const {return d;}
    m_enum month() const {return m;}
    int year() const {return y;}


  Date(unsigned int _d, m_enum _m, int _y) : d{_d}, m{_m}, y{_y} {}

  bool is_leap() {return y % 4 == 0 && y % 400 != 0;}

  std::map<m_enum, unsigned int> m_days = {
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

/* Implementing functions to add n days to a Date object */

  void add_day() {
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

  void add_days(const int n) {
    for (int i=0; i<n; ++i) add_day();
  }
};


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






int main() {


  Date test = Date(28, m_enum::feb, 2004);

  Date comparison = Date(28, m_enum::feb, 2004);
  test == comparison ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

  std::cout << test << std::endl;

  test.add_days(4);

  test == comparison ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;
  std::cout << test << std::endl;

}
