#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

int main(){
	
	string source = "204";
	
	set<string> keywords = {
	
	"show",
	"take",
	"imagine",
	"agar",
	"phirse"
	
	};
	
	for(int i = 0; i < source.length(); i++){
		
		if (isspace(source[i])){
			continue;
		}
		
		else if (isalpha(source[i])){
			string word = "";
			while(i < source.length() && (isalpha(source[i]) || isdigit(source[i]))){
				word += source[i];
				i++;
			}
			
			if (keywords.count(word) > 0){
				cout << "Keyword: " << word << endl;
			}
			
			else{
			cout << "Identifier: " << word << endl;
			}
			
			i--;
		}
		
		else if (isdigit(source[i])){
			string number = "";
			while(i < source.length() && isdigit(source[i])){
				number += source[i];
				i++;
			}
			i--;
			
			cout << "Number: " << number << endl;
		}
		
		else {
			cout << "Symbol: " <<source[i] << endl;
		}
	}
	
	return 0;
}