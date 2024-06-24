#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];

void cat(int fd)
{
	int n;

	while ((n = read(fd, buf, sizeof(buf))) > 0)
	{
		// read from the fd and write to the standard output(1) of the cat process
		if (write(1, buf, n) != n)
		{
			fprintf(2, "cat: write error\n");
			exit(1);
		}
	}
	if (n < 0)
	{
		fprintf(2, "cat: read error\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	int fd, i;

	if (argc <= 1)
	{
		cat(0);
		exit(0);
	}
	// for all files, open it, get fd and  call cat(fd)
	for (i = 1; i < argc; i++)
	{
		if ((fd = open(argv[i], 0)) < 0)
		{
			fprintf(2, "cat: cannot open %s\n", argv[i]);
			exit(1);
		}
		cat(fd);
		// release the file descriptor
		close(fd);
	}
	exit(0);
}
