/*
Author: MJ McGee
Date Created: 10/15/23
Date Last Modified: 10/15/23
Sources: cplusplus.com | stackoverflow.com
Description: Get an integer value from the user. Find all the possible combinations of football scoring plays that can equal that score.
*/
#include <iostream>
#include <fstream>
using namespace std;

//Driver program
int main() {
    //Initialize variables
    int score;

    cout << "Enter 0 or 1 to STOP\nEnter the NFL score: ";
    cin >> score;
    //While loop to contain software
    while(!(score <=1)) {

    //Iterate through every possible combination of plays. If the combination would result in the given score, print it
    cout << "Possible combinations of scoring plays:" << endl;
    for(int i = 0; i <= score/8; i++) {
        for(int j = 0; j <= score/7; j++) {
            for(int k = 0; k <= score/6; k++) {
                for(int l = 0; l <= score/3; l++) {
                    for(int m = 0; m <= score/2; m++) {
                        if((i*8 + j*7 + k*6 + l*3 + m*2) == score) {
                            cout << i << " TD + 2pt, ";
                            cout << j << " TD + FG, ";
                            cout << k << " TD, ";
                            cout << l << " 3pt FG, ";
                            cout << m << " Safety" << endl;
                        }
                    }
                }
            }
        }
    }
    cout << "Enter 0 or 1 to STOP\nEnter the NFL score: ";
    cin >> score;
    }
    return 0;
}  