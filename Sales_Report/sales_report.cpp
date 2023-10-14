/*
Author: MJ McGee
Date Created: 10/12/23
Date Last Modified: 10/12/23
Description: Read in a file of sales data and process it into a sales report
*/
#include <iostream>
#include <fstream>
using namespace std;


int main() {

	ifstream file("sales_data.txt");

	char *data;
	file.getline(data, 20);

	printf(data);

	file.close();
	return 0;
}
