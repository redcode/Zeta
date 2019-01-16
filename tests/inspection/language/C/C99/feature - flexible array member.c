typedef struct {int a; int b; int c[];} ABC;


int main(int argc, char **argv)
	{
	ABC abc = {1, 2};
	ABC *abc_pointer = &abc;

	return abc_pointer->a;
	}
