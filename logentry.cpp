//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date: 3/24/2024       
// Author: Peter Nguyen     
//
// Description: Class implementation for a log entry.
//
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

// REQUIRES:
// ENSURES:
LogEntry::LogEntry(const String& line) {
    //Use split to create LogEntry
    std::vector<String> logEntryParts = line.split(' ');

    if (vec.size() == 10) {
        host = logEntryParts[0];

        std::vector<String> date_time = logEntryParts.split(':');
        std::vector<String> date_string = date_time[0].split('/');
        String stringDay = date_string[0].substr(1, date_string[0].getLength());
        Date.setDay(stringDay);

        String stringMonth = date_string[1];
        Date.setMonth(stringMonth);

        String stringYear = date_string[2];
        Date.setYear(stringYear);

        Time.setHour(date_time[1]);
        Time.setMinute(date_time[2]);
        Time.setSecond(date_time[3]);

        request = logEntryParts[5] + logEntryParts[6] + logEntryParts[7];

        status = logEntryParts[8];
        if(logEntryParts[9] == '-'){
            number_of_bytes = 0;
        }
        number_of_bytes = logEntryParts[9];

    }
    else {
        host = "";
        Date.setDay("");
        Date.setMonth("");
        Date.setYear("");
        Time.setHour("");
        Time.setMinute("");
        Time.setSecond("");
        request = "";
        status = "";
        number_of_bytes = 0;
    }

}

// REQUIRES:
// ENSURES:
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    do {
        String line = getline(in);
        LogEntry log(line);
        result.push_back(log);
    } 
    while (!in.eof());
    return result;
}

// REQUIRES:
// ENSURES:
void output_all(std::ostream& out, const std::vector<LogEntry>& logs) {
        for (int i = 0; i < logs.size(); ++i) {
        out << logs[i];
    }
}

// REQUIRES:
// ENSURES:
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (int i = 0; i < logs.size(); ++i) {
        out << logs[i].gethost() << std::endl;
    }
}

// REQUIRES:
// ENSURES:
int byte_count(const std::vector<LogEntry>& logs) {
    
    int sum = 0;
    
    for (int i = 0; i < logs.size(); ++i) {
        sum += logs[i].getbytes();
    }
    
    return sum;
}

