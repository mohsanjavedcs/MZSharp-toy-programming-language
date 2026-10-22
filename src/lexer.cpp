#include <iostream>
#include <string>
#include <cctype>
#include <set>

using namespace std;

int main() {
    string source = "agar (age >= 18) { show age; };";

    set<string> keywords = {
        "show",
        "take",
        "imagine",
        "agar",
        "phirse"
    };

    for (int i = 0; i < source.length(); i++) {

        // Ignore whitespace
        if (isspace(source[i])) {
            continue;
        }

        // Recognize identifiers and keywords
        else if (isalpha(source[i])) {
            string word = "";

            while (i < source.length() &&
                   (isalpha(source[i]) || isdigit(source[i]))) {
                word += source[i];
                i++;
            }

            if (keywords.count(word) > 0) {
                cout << "Keyword: " << word << endl;
            }
            else {
                cout << "Identifier: " << word << endl;
            }

            i--;
        }

        // Recognize complete numbers
        else if (isdigit(source[i])) {
            string number = "";

            while (i < source.length() && isdigit(source[i])) {
                number += source[i];
                i++;
            }

            cout << "Number: " << number << endl;

            i--;
        }

        // Recognize operators
        else if (source[i] == '=' || source[i] == '!' ||
			     source[i] == '>' || source[i] == '<' ||
				 source[i] == '+' || source[i] == '*' ||
			     source[i] == '-' || source[i] == '/') {
            if (i + 1 < source.length() &&
                source[i + 1] == '=') {
				
				string op = "";
				op += source[i];
				op += "=";
                cout << "Operator: " << op << endl;
                i++;
            }
            else {
            	string op = "";
				op += source[i];
            	
                cout << "Operator: " << op << endl;
            }
        }

        // Handle other symbols for now
        else {
            cout << "Symbol: " << source[i] << endl;
        }
    }

    return 0;
}
