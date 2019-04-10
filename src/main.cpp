#include "../inc/KMP.h"
#include "../inc/Justify.h"
#include <iostream>
#include <fstream>
using namespace std;

typedef long long lli;

string readFile(string filename) {
	ifstream file;
	file.open(filename);
	string text="", line;
	while(getline(file, line)) {
		text += (line + "\n");
	}
	file.close();
	return text;
}

bool is_auto_complete(string word) {
	if(word.length() <= 2) return false;
	if(word[1] == '#' && word[2] == '#') return true;
	return false;
}

int main(int argc, char const *argv[]) {
	int op = 1;
	KMP _kmp;
	while(op) {
		cout << "[ 1 ] buscar palavra" << endl;
		cout << "[ 2 ] auto-completar" << endl;
		cout << "[ 3 ] Justificar o texto " << endl;
		cout << "[ 0 ] sair" << endl;
		cin >> op;
		if(op == 1) {
			cout << "qual palavra você gostaria de buscar: ";
			string word;
			cin >> word;
			string text = readFile("res/input.txt");
			vector<int> matches = _kmp.kmp(text, word);
			cout << "foram encontradas: " << matches.size() << " ocorrencias dessa palavra";
			if(matches.size()) cout << ", são elas:" << endl;
			else cout << endl;
			for(int i = 0; i < matches.size(); i++) {
				string match = _kmp.getPreffix(matches[i], text) + _kmp.getSuffix(matches[i], text);
				if(!is_auto_complete(match)){
					cout << "<" << matches[i] << ">: ";
					cout << "[ " << i + 1 << " ] " << match << endl;
				}
			}
			cout << "#####################################################" << endl;
		} else if(op == 2){
			string text = readFile("res/input.txt");
			set< pair < string, string > > autoCompletes;
			for(int i = 0; i < text.length(); i++) {
				if(text[i] == '#' && i + 1 < text.length() && text[i + 1] == '#') {
					i += 2;
					string word = "";
					while(isalpha(text[i])) {
						word += text[i++];
					}
					string text_auto_complete = readFile("res/BDST.txt");
					vector<int> matches = _kmp.kmp(text_auto_complete, word);
					set < pair < string, string > > aux = _kmp.autoComplete(matches, word, text_auto_complete);
					for( auto p : aux) {
						autoCompletes.insert(p);
					}
				}
				_kmp.write_suffix(autoCompletes);
			}
		}else if(op == 3) {
			Justify just;
			vector<string> text = just.build("res/input.txt");
			vector< vector <lli >> DP = just.pre_justify(text, 50);
			vector<lli> line, best;
			best.resize(DP.size());
			line.resize(DP.size());
			just.findBest(best, line, DP);
			just.print(DP, line, text);		
		}
	}
	return 0;
}