//
// File:        logentry.hpp
//
// Version:     1.0
// Date:  3/24/2024
// Author: Peter Nguyen
//
// Description: Class definition for a log entry.
//
//
//
 
#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>

//
class Date {
public:
            Date() {};
    void    setDay(String line) { day = line; };
    void    setMonth(String line) { month = line; };
    void    setYear(String line) { year = line; };
    String  getDay() const { return day; };
    String  getMonth() const { return month; };
    String  getYear() const { return year; };
private:
    String  day, month, year;
};

//
class Time {
  public:
            Time() {};
    void    setHour(String line) { hour = line; };
    void    setMinute(String line) { minute = line; };
    void    setSecond(String line) { second = line; };
    String  getHour() const { return hour; };
    String  getMinute() const { return minute; };
    String  getSecond() const { return second; };
  private:
    String  hour, minute, second;
};


// A single log entry
class LogEntry {
public:
            LogEntry() {};
            LogEntry(const String&);
    String getHost() const { return host; };
    int getBytes() const { return number_of_bytes; };

    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);

#endif
