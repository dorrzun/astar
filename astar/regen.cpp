#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	string line;
	string s = argv[1];
	ifstream input = ifstream(s);

	getline(input,line);
	while(getline(input,line)){
		for(int i = 0; i < line.size(); ++i){
			if(line[i] == '.' or line[i] == '-'){
				line[i] = ' ';
			}
		}
		cout << line << endl;
	}

}
