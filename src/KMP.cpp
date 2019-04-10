#include "../inc/KMP.h"

using namespace std;

KMP::KMP() { }
KMP::~KMP() { }

vector<int> KMP::pre_kmp(string text) {
	int size = text.size();
	vector<int> lps;
	lps.resize(size);
	int k =0;
	for(int i = 1; i < size; i++) {
		while(k && text[ k ] != text[ i ]) k = lps[ k - 1 ];
		if(text[ k ] == text[ i ]) k++;
		lps[i] = k;
	}
	return lps;
}

vector<int> KMP::kmp(string text, string key) {
	vector<int> lps = pre_kmp(text);
	int matched_pos = 0;
	vector<int> matches;
	for(int i = 0; i < text.length(); i++) {
		while(matched_pos && key[matched_pos] != text[i]) matched_pos = lps[matched_pos - 1];
		if(key[matched_pos] == text[i]) matched_pos++;
		if(matched_pos == key.length()) {
			matched_pos = lps[matched_pos - 1];
			matches.push_back(i - (key.length() - 1));
		}
	}
	return matches;
}

string KMP::getPreffix(int pos, string word) {
	string prefix = "";
	while(isalpha(word[pos])) prefix = word[pos--] + prefix;
	return prefix;
}

string KMP::getSuffix(int pos, string word) {
	string sufix = "";
	pos++;
	while(isalpha(word[pos])) sufix += word[pos++];
	return sufix;
}

set<string> KMP::autoComplete(vector<int> matches, string word, string text) {
	set < string > suffix;
	int pos;
	for(int i = 0; i < (int)matches.size() && suffix.size() < 4; i++ ){ 
		string ans = getSuffix(matches[i] + word.size() - 1, text);
		if(ans.size()){
			suffix.insert(ans);
		}
	}
	return suffix;
}

void KMP::write_suffix(set<string> suffix) {
	ofstream file;
	file.open("res/suffix.txt");
	if(!file.good()) {
		system("touch res/suffix.txt");
		return write_suffix(suffix);
	}
	for(auto s : suffix) {
		string ans = s;
		file << ans.c_str() << endl;
	}
	file.close();
}