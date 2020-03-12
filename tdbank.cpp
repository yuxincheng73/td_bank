#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class ThirtySecondsFormatter {
    private:
    int fullDollar;
    int thirtysecondDollar;
    //this is the string formatted version of the double 
    string thirtysecondformat;

    public:
    string convertToString(double dollarAmount);
};

string ThirtySecondsFormatter::convertToString(double dollarAmount) {
    string str = to_string(dollarAmount);
    string splitstr[2];

    //not sure if there is a .split function implemented for c++
    //c++ doesnt seem to have an easy way to split strings by delimiters
    splitstr = str.split(".");
    //so 0 index contains the dollar amount and 1 index contains decimal
    //first set it just equal to the dollar amount
    string dollar = splitstr[0];

    //atof to convert the decimal part to an int
    double decimal = atof(splitstr[1].c_str());
    //x is the 32nds part
    //this calculation should work because in the question it said
    //assume all decimal parts are multiples of 1/32
    int x = 32 * decimal;
    string x_str = to_string(x);

    //if length of the 32nds part is less than two digits, append 0s
    if(x_str.length() < 2) {
        for(int i = 0; i < 2 - x_str.length(); i++) {
            x_str = "0" + x_str;
        }
    }

    //if length of the full dollar amount part is less than two digits, append 0s
    if(dollar.length() < 2) {
        for(int i = 0; i < 2 - dollar.length(); i++) {
            dollar = "0" + dollar;
        }
    }

    //combine the string together in the correct format
    ThirtySecondsFormatter::thirtysecondformat =  dollar + "-" + x_str;
}

//writing some test case functions
void test_case1() {
    ThirtySecondsFormatter thirtysecond;
    double amount = 105.25;
    string expectedString = "105-08";
    thirtysecond.convertToString(amount);

    assert(thirtysecond.thirtysecondformat == expectedString);
}

void test_case2() {
    ThirtySecondsFormatter thirtysecond;
    double amount = 9.03125;
    string expectedString = "09-01";
    thirtysecond.convertToString(amount);

    assert(thirtysecond.thirtysecondformat == expectedString);
}

//in main you call the test case functions
int main() {
    test_case1();
    test_case2();

    return 0;
}