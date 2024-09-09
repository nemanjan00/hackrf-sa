#include <fstream>
#include <iostream>
#include "volk/volk.h"

using namespace std;

int main () {
	ifstream file;

	int buffer_length = 4000000;

	int8_t * buffer = new int8_t [buffer_length];
	float * buffer_32f = new float [buffer_length];

	float * i_buffer_32f = new float [buffer_length / 2];
	float * q_buffer_32f = new float [buffer_length / 2];

	file.open("samples/95MHz-center-100MHzCW", ios::in | ios::binary);

	do {
		file.read((char*) buffer, buffer_length);

		volk_8i_s32f_convert_32f(buffer_32f, buffer, 128.0f, file.gcount());

		int counter = 0;

		for(int i = 0; i < file.gcount() / 2; i++) {
			i_buffer_32f[i] = buffer[i * 2];
			q_buffer_32f[i] = buffer[i * 2 + 1];
		}

		float i_stddev;
		float q_stddev;

		float i_mean;
		float q_mean;

		volk_32f_stddev_and_mean_32f_x2(&i_stddev, &i_mean, i_buffer_32f, file.gcount() / 2);
		volk_32f_stddev_and_mean_32f_x2(&q_stddev, &q_mean, q_buffer_32f, file.gcount() / 2);

		cout << "I mean " << i_mean << " stddev " << i_stddev << "\n";
		cout << "Q mean " << q_mean << " stddev " << q_stddev << "\n";
		cout << "\n";
	} while(file);

	file.close();

	return 0;
}
