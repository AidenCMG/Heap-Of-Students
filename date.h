#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS
#include <string>

class Date{
	protected:
		std::string dateString;
		int day;
		int month;
		int year;
	public:
		Date();
		void init(std::string dateString);
		void printDate();
	};
#endif
