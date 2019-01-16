typedef struct {int a; int b;} AB;


int main(int argc, char **argv)
	{
	AB ab;

	ab = (AB){1, 2};
	return ab.a;
	}
