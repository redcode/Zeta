typedef struct {int a; int b;} AB;


int increment(int value)
	{return value + 1;}


int main(int argc, char **argv)
	{
	AB ab = {increment(0), increment(1)};

	return ab.a;
	}
