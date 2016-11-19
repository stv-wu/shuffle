#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int get_random_int(int *);

int main()
{
#define TEST_NUM  3
	int rand;

	for (int i = 0; i < TEST_NUM; i++){
	    if(!get_random_int(&rand)){
		printf("Got %x\n", rand);
	    }
	}
}

int get_random_int(int *rnd)
{
#define SYS_RAND_FILE "/dev/random"

	int fd;

	int nbytes;

	fd = open(SYS_RAND_FILE, O_RDONLY);

	if( fd < 0){
		return(-1);
	}

	nbytes = read(fd, rnd, sizeof(*rnd));

	close(fd);

	return nbytes > 0 ? 0: -1;

}

