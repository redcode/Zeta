#define MACRO(...) __VA_ARGS__


int main(int argc, char **argv)
	{
	int array[2] = {MACRO(1, 2)};

	return array[1];
	}
