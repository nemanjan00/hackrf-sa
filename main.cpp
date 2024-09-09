#include <fstream>
#include <iostream>

using namespace std;

int main () {
	ifstream file;

	int buffer_length = 4000000;

	int8_t * buffer = new int8_t [buffer_length];

	double * average = new double [2];
	long * count = new long [2];
	bool * started = new bool [2];

	file.open("samples/95MHz-center-100MHzCW", ios::in | ios::binary);

	do {
		file.read((char*) buffer, buffer_length);
		//cout << "read " << file.gcount() << "\n";

		for(int i = 0; i < file.gcount(); i++) {
			int type = i % 2;

			if(started[type] == false) {
				count[type] = 1;
				average[type] = buffer[i];

				started[type] = true;
			} else {
				average[type] =
					((double) count[type] / (double)(count[type] + 1) * (double)average[type]) +
					((double)buffer[i] / (count[type] + 1));

				count[type]++;
			}
		}
	} while(file);

	cout << "I " << average[0] << "\n";
	cout << "Q " << average[1] << "\n";

	file.close();

	return 0;
}
