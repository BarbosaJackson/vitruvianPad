#include "../inc/KMP.h"
#include "../inc/Justify.h"
#include <iostream>
#include <fstream>
using namespace std;

typedef long long lli;

int main(int argc, char const *argv[]) {
	Justify just;
	vector<string> text = just.build("res/teste.txt");
	vector< vector <lli >> DP = just.pre_justify(text, 10);
	vector<lli> line, best;
	best.resize(DP.size());
	line.resize(DP.size());
	just.findBest(best, line, DP);
	just.print(DP, line, text);
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