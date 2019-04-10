#include "../inc/Justify.h"

using namespace std;

Justify::Justify() { }
Justify::~Justify() {}

vector<string> Justify::build(string filename) {
	ifstream file; 
	file.open(filename.c_str());
	string line;
	vector<string> text;
	while(file >> line) {
		text.push_back(line);
	}
	return text;
}

vector < vector < lli > > Justify::pre_justify(vector<string> &words, lli lenght) {
	lli qnt_words = (lli)words.size();
	vector < vector < lli > > DP;
	DP.resize(qnt_words);
	for(lli i = 0; i < qnt_words; i++) 
		DP[i].assign(qnt_words, INF);
	for(lli i = 0; i < qnt_words; i++) {
		lli sum = 0;
		for(lli j = i; j < qnt_words; j++) {
			sum += words[j].size();
			if(sum <= lenght) 
				DP[i][j] = (lenght - sum) * (lenght - sum);
		}
	}
	return DP;
}

void Justify::findBest(vector<lli> &best, vector<lli> &line, vector<vector<lli>> &DP) {
	for(lli i  = (lli)DP.size() - 1; i>= 0; i--) {
		best[i] = DP[i][(lli)DP.size() - 1];
		line[i] = (lli)DP.size();
		for(lli j = DP.size() - 1; j > i; j--) {
			if(DP[i][j - 1] != INF && best[i] > best[j] + DP[i][j - 1]){
				best[i] = best[j] + DP[i][j - 1];
				line[i] = j;
			}
		}
	}
}

void Justify::print(vector<vector<lli>> &DP, vector<lli> &line, vector<string> &words) {
	ofstream output;
	output.open("res/Justify.txt");
	if(!output.good()) {
		system("touch res/Justify.txt");
		return print(DP, line, words);
	}
	for(lli i = 0, j = 0; j < DP.size(); i = j) {
		j = line[i];
		for(lli k = i; k < j; k++) {
			output << words[k];
			if(k + 1 != j) output << " ";
		}
		output << endl;
	}
	output << endl;
}