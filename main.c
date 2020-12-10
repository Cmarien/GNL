#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line = NULL;
	int ret = 0;

	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		printf("%s\n", line);
		printf("%d\n", ret);
		if (line)
			free(line);
		if (!ret)
			break;
	}
	close(fd);
	return (0);
}
