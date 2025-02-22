#include "date.h"
#include <iostream>
#include <sstream>

Date::Date(){
	dateString = "";
	day = 0;
	month = 0;
	year = 0;
}

void Date::init(std::string dateString){
	std::stringstream ss;
	std::string strDay;
	std::string strMonth;
	std::string strYear;
	std::stringstream converter;
	
	ss.str(dateString);

	getline(ss,strMonth,'/');
	converter << strMonth;
	converter >> Date::month;

	converter.clear();

	getline(ss,strDay,'/');
	converter << strDay;
	converter >> Date::day;

	converter.clear();

	getline(ss,strYear,'/');
	converter << strYear;
	converter >> Date::year;	
	
}

void Date::printDate(){
	std::string months[13] = {"","January","Febuary","March","April","May","June","July","August","September","October","November","December"};
	std::cout << months[month] << " " << day << "," << " " << year << std::endl;
}

