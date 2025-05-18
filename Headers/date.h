#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
    private:
        int day;
        int month;
        int year;

        int toInt() const;

    public:
        Date();
        Date(const Date&);

        Date& operator = (const Date&);
        
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        void setDay(const int&);
        void setMonth(const int&);
        void setYear(const int&);

        std::string toString() const;

        bool operator == (const Date&) const;
        bool operator != (const Date&) const;
        bool operator < (const Date&) const;
        bool operator <= (const Date&) const;
        bool operator > (const Date&) const;
        bool operator >= (const Date&) const;

        friend std::ostream& operator << (std::ostream&, Date&);
        friend std::istream& operator >> (std::istream&, Date&);
};

#endif // DATE_H