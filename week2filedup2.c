#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd = open("./week_dup2_data",O_CREAT|O_WRONLY,0777);

	if(dup2(fd,STDOUT_FILENO) == -1)
	{
		perror("failed dup2");
		return 1;
	}

	printf("Hello world\n");
	close(fd);
	return 0;

}
