/*
Author: MJ McGee
Date Created: 10/12/23
Date Last Modified: 10/14/23
Sources: cplusplus.com | stackoverflow.com
Description: Read in a file of sales data and process it into a sales report
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

//Return a line from the given file as a float variable type
float return_sales_data(ifstream &file) {
	//Initialize variables
	char data[28];
	file.getline(data, 10);
	char* pEnd;
	
	return strtod(data, &pEnd);
}

//Return the name of the given month as a string
string return_month_name(int month) {
	month += 1;
	switch(month) {
		case 1:
			return "January";
		case 2:
			return "February";
		case 3:
			return "March";
		case 4:
			return "April";
		case 5:
			return "May";
		case 6:
			return "June";
		case 7:
			return "July";
		case 8:
			return "August";
		case 9:
			return "September";
		case 10:
			return "October";
		case 11:
			return "November";
		case 12:
			return "December";
		default:
			return "Undefined";
	}
}

int main() {
	//Initialize variables
	char filename[32];
	cout << "Please enter the desired filename: ";
	cin >> filename;
	ifstream file(filename);
	ofstream report("sales_report.txt");
	float minimum;
	float maximum;
	float average = 0;
	int month_int;
	float value;

	//Initialize monthly sales data.
	float sales_array[12] = {return_sales_data(file), return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file),return_sales_data(file)};
	float sorted_array[12];
	for(int i = 0; i < 12; i++) {
		sorted_array[i] = sales_array[i];
	
	}
	sort(begin(sorted_array), end(sorted_array));
	
	//Print data to sales_report.txt
	report << setprecision(7) << "Monthly Sales Report for 2022:\n" << endl;
	report << "Month\t\tSales" << endl;
	for (int i = 0; i < 12; i++) {
		report << return_month_name(i) << "\t\t$" << sales_array[i] << endl;
	}
	
	report << "\n\nSales Summary:" << endl;
	
	//Find the minimum
	minimum = sales_array[0];
	for(int i = 0; i < 12; i++) {
		if(minimum >= sales_array[i]) {
			minimum = sales_array[i];
			month_int = i;
		}
	}
	report << "Minimum Sales:\t$" << minimum << "\t(" << return_month_name(month_int) << ")\n";
	
	//Find the maximum
	maximum = sales_array[0];	
	for(int i = 0; i < 12; i++) {
		if(maximum <= sales_array[i]) {
			maximum = sales_array[i]; 
			month_int = i;
		}
	}
	report << "Maximum Sales:\t$" << maximum << "\t(" << return_month_name(month_int) << ")\n";
	
	//Calculate the average
	for(int i = 0; i <12; i++) {
		average += sales_array[i];
	}
	average /= 12;
	report << "Average Sales:\t$" << average << endl;
	
	report << "\n\nSix-Month Moving Average Report:" << endl;
	//Calculate the 6-month moving averages
	for(int i = 0; i <= 6; i++) {
		average = 0;
		report << return_month_name(i) << "\t- " << return_month_name(i+5);
		for(int j = i; j <= i+5; j++) {
			average += sales_array[j];
		}
		average /= 6;
		report << "\t$" << average << endl;
	}
	

	report << "\n\nSales Report (Highest to Lowest):" << endl;
	//Print the sorted data highest to lowest
	for(int i = 11; i >= 0; i--) {
		value = sorted_array[i];
		for(int j = 0; j < 12; j++) {
			if(value == sales_array[j]) {
				month_int = j;
			}
		}
		report << return_month_name(month_int) << "\t\t$" << value << endl;
	}
	report.close();
	file.close();
	return 0;
}