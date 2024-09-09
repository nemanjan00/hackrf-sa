#include <fstream>
#include <iostream>

using namespace std;

int main () {
	ifstream file;

	int buffer_length = 4000000;

	int8_t * buffer = new int8_t [buffer_length];

	double * average = new double [2];
	long * count = new long [2];

	file.open("samples/95MHz-center-100MHzCW", ios::in | ios::binary);

	do {
		file.read((char*) buffer, buffer_length);
		cout << "read " << file.gcount() << "\n";
	} while(file);

	return 0;
}
