#include <iostream>
#include <string>
#include <cctype>
#include <set>
#include <vector>

using namespace std;

struct Token{
    	string type;
    	string value;
	};
	
bool parseShowStatement(const vector<Token>& tokens){
	if (tokens.size() == 0){
		
		return false;
	}
	else if (tokens[0].type != "Keyword" ||
		     tokens[0].value != "show"){
		     	
		return false;
	}
	else if (tokens[1].type != "Identifier"){
		
		return false;
	}
	else if (tokens[2].type != "Symbol" ||
		     tokens[2].value != ";"){
		
		return false;
	}
	return true;
}

int main() {
    string source = "show username;";
    
    vector<Token> tokens;

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
                Token token;
				token.type = "Keyword";
				token.value = word;
				
				tokens.push_back(token);
            }
            else {
                Token token;
				token.type = "Identifier";
				token.value = word;
				
				tokens.push_back(token);
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

            Token token;
			token.type = "Number";
			token.value = number;
			
			tokens.push_back(token);

            i--;
        }

        // Recognize operators
        else if (source[i] == '=' || source[i] == '!' ||
		         source[i] == '>' || source[i] == '<' ||
		         source[i] == '+' || source[i] == '-' ||
		         source[i] == '*' || source[i] == '/') {
            if (i + 1 < source.length() &&
                source[i + 1] == '=') {
				
				string op = "";
				op += source[i];
				op += "=";
                Token token;
				token.type = "Operator";
				token.value = op;
				
				tokens.push_back(token);
                i++;
            }
            else {
            	string op = "";
				op += source[i];
            	
                Token token;
				token.type = "Operator";
				token.value = op;
				
				tokens.push_back(token);
            }
        }

        // Handle other symbols for now
        else {
            Token token;
			token.type = "Symbol";
			token.value = string(1, source[i]);
				
			tokens.push_back(token);
        }
    }
    
    if (parseShowStatement(tokens)){
    	cout << "Valid show statement" << endl;
	}
	else {
    	cout << "Invalid show statement" << endl;
		
	}
    
    for(int i = 0; i < tokens.size(); i++){
    	cout << tokens[i].type << ": " << tokens[i].value << endl;
	}

    return 0;
}
