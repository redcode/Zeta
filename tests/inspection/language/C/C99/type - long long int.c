int main(int argc, char **argv)
	{
	signed long long int a = (long long int)argc;
	unsigned long long int b = (unsigned long long int)argc;

	return a || b ? 1 : 0;
	}
