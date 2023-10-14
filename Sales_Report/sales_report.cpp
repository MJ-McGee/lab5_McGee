/*
Author: MJ McGee
Date Created: 10/12/23
Date Last Modified: 10/14/23
Sources: cplusplus.com | stackoverflow.com
Description: Read in a file of sales data and process it into a sales report
*/
#include <iostream>
#include <fstream>
using namespace std;

float return_sales_data(ifstream &file) {
	//Initialize variables
	char data[28];
	file.getline(data, 10);
	char* pEnd;
	
	return strtof(data, &pEnd);
}


int main() {
	//Initialize variables
	char filename[32];
	cout << "Please enter the desired filename: ";
	cin >> filename;
	ifstream file(filename);
	//Initialize monthly sales data. Could not think of a better way to do this. Too bad!
	float january = return_sales_data(file);
	float february = return_sales_data(file);
	float march = return_sales_data(file);
	float april = return_sales_data(file);
	float may = return_sales_data(file);
	float june = return_sales_data(file);
	float july = return_sales_data(file);
	float august = return_sales_data(file);
	float september = return_sales_data(file);
	float october = return_sales_data(file);
	float november = return_sales_data(file);
	float december = return_sales_data(file);
	
	
	file.close();
	return 0;
}