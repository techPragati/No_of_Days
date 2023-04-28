#include <iostream> 
using namespace std; 
// funcƟon to check if a given year is a leap year or not 
bool isLeapYear(int year) { 
 if (year % 4 != 0) 
 return false; 
 else if (year % 100 != 0) 
 return true; 
 else if (year % 400 != 0) 
 return false; 
 else 
 return true; 
} 
// funcƟon to calculate the number of days between two dates 
int daysBetweenDates(int startYear, int startMonth, int startDay, int endYear, int 
endMonth, int endDay) 
{ 
 // array to store the number of days in each month 
 int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 // check if the dates are of same year 
 if(startYear==endYear) 
 { 
 if(startMonth==endMonth) 
 { 
 return endDay-startDay; 
 } 
 else 
 { 
 int totalDays=0; 
 for (int month = startMonth; month < endMonth; month++) 
 { 
 if (month == 2 && isLeapYear(startYear)) 
 totalDays += 29; 
 else 
 totalDays += daysInMonth[month-1]; 
 } 
 
 totalDays = totalDays-startDay + endDay; 
 return totalDays; 
 } 
 } 
 else 
 { 
 // array to store the number of days in each month 
 int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 // calculate the number of days from start date to end of start year 
 int daysInStartYear = 0; 
 for (int month = startMonth; month <= 12; month++) 
 { 
 if (month == 2 && isLeapYear(startYear)) 
 daysInStartYear += 29; 
 else 
 daysInStartYear += daysInMonth[month-1]; 
 } 
 daysInStartYear -= startDay; 
 
 // step 3: calculate the number of days from start of end year to end date 
 int daysInEndYear = 0; 
 for (int month = 1; month < endMonth; month++) 
 { 
 if (month == 2 && isLeapYear(endYear)) 
 daysInEndYear += 29; 
 else 
 daysInEndYear += daysInMonth[month-1]; 
 } 
 daysInEndYear += endDay; 
 
 // step 4: calculate the number of days between start year and end year 
 int daysBetweenYears = 0; 
 for (int year = startYear+1; year < endYear; year++) 
 { 
 if (isLeapYear(year)) 
 daysBetweenYears += 366; 
 else 
 daysBetweenYears += 365; 
 } 
 // step 5: add up the total number of days 
 int totalDays = daysBetweenYears + daysInStartYear + daysInEndYear; 
 return totalDays; 
 } 
} 
int main() { 
 // sample input dates 
 int startYear = 2012; 
 int startMonth = 1; 
 int startDay = 1; 
 int endYear = 2012; 
 int endMonth = 2; 
 int endDay = 28; 
 int days = daysBetweenDates(startYear, startMonth, startDay, endYear, 
endMonth, endDay); 
 cout << "Number of days between the two dates: " << days << endl; 
 
 startYear = 2012; 
 startMonth = 1; 
 startDay = 1; 
 endYear = 2012; 
 endMonth = 3; 
 endDay = 1; 
 days = daysBetweenDates(startYear, startMonth, startDay, endYear, endMonth, 
endDay); 
 cout << "Number of days between the two dates: " << days << endl; 
 
 startYear = 2011; 
 startMonth = 6; 
 startDay = 30; 
 endYear = 2012; 
 endMonth = 6; 
 endDay = 30; 
 days = daysBetweenDates(startYear, startMonth, startDay, endYear, endMonth, 
endDay); 
 cout << "Number of days between the two dates: " << days << endl; 
 startYear = 2011; 
 startMonth = 1; 
 startDay = 1; 
 endYear = 2012; 
 endMonth = 8; 
 endDay = 8; 
 days = daysBetweenDates(startYear, startMonth, startDay, endYear, endMonth, 
endDay); 
 cout << "Number of days between the two dates: " << days << endl; 
 startYear = 1900; 
 startMonth = 1; 
 startDay = 1; 
 endYear = 1999; 
 endMonth = 12; 
 endDay = 31; 
 days = daysBetweenDates(startYear, startMonth, startDay, endYear, endMonth, 
endDay); 
cout << "Number of days between the two dates: " << days << endl; 
 return 0; 
}
