#ifndef justify_h
#define justify_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

typedef long long lli;

class Justify {
public:
	Justify();
	~Justify();
	vector < vector < lli > > pre_justify(vector<string> &words, lli lenght);
	void findBest(vector<lli> &best, vector<lli> &line, vector<vector<lli>> &DP);
	void print(vector<vector<lli>> &DP, vector<lli> &line, vector<string> &words);
	vector<string> build(string filename);

};

#endif