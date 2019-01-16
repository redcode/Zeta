typedef struct {int a; int b;} AB;


int get_a(AB *restrict ab);

int get_a(AB *restrict ab)
	{return ab->a;}


int main(int argc, char **argv)
	{
	AB ab = {1, 2};

	return get_a(&ab);
	}
