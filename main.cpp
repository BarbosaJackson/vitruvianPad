#include "fileMan.cpp"

using namespace std;

int main() {
	int op; string path;
	cout << " [ 1 ] open a file " << endl;
	cout << " [ 2 ] create a file " << endl;
	cout << " [ 0 ] exit " << endl;
	cin >> op;
	if(op == 1) {
		// system("cls");
		cout << "write path for file" << endl;
		cin >> path;
		write(path);
	}
	return 0;
}