#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
	FILE *fd; // file   
	
	openlog(NULL,0,LOG_USER);
	
	
	if (argc < 3)
	{
		syslog(LOG_ERR, "Invalide Number of argumetns: %d", (argc-1));
		printf("Invalide Number of argumetns: %d", (argc-1));
		return 1;
	}
	fd = fopen(argv[1], "w");
	
	if (fd == NULL)	// no file
	{
		syslog(LOG_ERR, "Can't open file: %s", argv[1]);
		printf("\neCan't open file: %s \n",argv[1]);
		return 1;
	}
	
	fprintf(fd, "%s", argv[2]);
	fclose(fd);
	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
}

