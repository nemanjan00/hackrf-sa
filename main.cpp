#include <fstream>
#include <iostream>

using namespace std;

int main () {
	ifstream file;

	int buffer_length = 4000000;

	int8_t * buffer = new int8_t [buffer_length];

	file.open("samples/95MHz-center-100MHzCW", ios::in | ios::binary);

	while(file) {
		file.read((char*) buffer, buffer_length);
		cout << buffer[0];
	}

	return 0;
}
