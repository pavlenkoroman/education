#include <iostream>

unsigned long long read_int_value() {
	auto const max = 255;

	std::cout << "¬ведите строку: ";

	char in[max];

	fgets(in, max, stdin);

	char result[max];
	char* result_pointer = result;
	int stringPosition = 0;

	for (unsigned long long i = 0; i < strlen(in); i++)
	{
		if (isdigit(in[i]))
		{
			*(result_pointer + stringPosition) = in[i];
			stringPosition++;
		}
	}

	*(result_pointer + stringPosition) = '\0';

	printf("%s", result);

	return atoi(result);
}