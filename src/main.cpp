#include "../inc/KMP.h"
#include "../inc/Justify.h"
#include <iostream>
#include <fstream>
using namespace std;

typedef long long lli;

string readFile() {
	ifstream file;
	file.open("res/input.txt");
	string text="", line;
	while(getline(file, line)) {
		text += (line + "\n");
	}
	file.close();
	return text;
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
			string text = readFile();
			vector<int> matches = _kmp.kmp(text, word);
			cout << "foram encontradas: " << matches.size() << " ocorrencias dessa palavra";
			if(matches.size()) cout << ", são elas:" << endl;
			else cout << endl;
			for(int i = 0; i < matches.size(); i++) {
				cout << "[ " << i + 1 << " ] " << _kmp.getPreffix(matches[i], text) << _kmp.getSuffix(matches[i], text) << endl;
			}
			cout << "#####################################################";
		} else if(op == 2){
			string text = readFile();
			for(int i = 0; i < text.length(); i++) {
				if(text[i] == '!' && i + 1 < text.length() && text[i + 1] == '!') {
					i++;
					string word = "";
					while(isalpha(text[i])) {
						word += text[i++];
					}
					text = readFile();
					vector<int> matches = _kmp.kmp(text, word);
					_kmp.write_suffix(_kmp.autoComplete(matches, word, text));
				}
			}
		}else if(op == 3) {
			Justify just;
			vector<string> text = just.build("res/input.txt");
			vector< vector <lli >> DP = just.pre_justify(text, 2);
			vector<lli> line, best;
			best.resize(DP.size());
			line.resize(DP.size());
			just.findBest(best, line, DP);
			just.print(DP, line, text);		
		}
	}
	return 0;
	// string text = "";
	// ifstream file;
	// file.open("res/BDST.txt");
	// string line;
	// while(file >> line) text += line + '\n';
	// file.close();
	// string palavra;
	// KMP _kmp;

	// while(1) {
	// 	cin >> palavra;
	// 	if(palavra == "xau") return 0;
	// 	vector<int> m = _kmp.kmp(text, palavra);
	// 	_kmp.write_suffix(_kmp.autoComplete(m, palavra, text));
	// }
}