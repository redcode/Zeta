typedef struct {int a; int b;} AB;


int main(int argc, char **argv)
	{
	AB ab = {.a = 1};
	int array[10] = {[2] = 1, [5] = 2};

	return ab.a + array[2];
	}
