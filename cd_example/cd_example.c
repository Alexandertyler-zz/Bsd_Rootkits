#include <sys/param.h>
#include <sys/proc.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>
#include <sys/conf.h>
#include <sys/uio.h>

#include <bsm/audit_kevents.h>

/* Function Prototypes */
d_open_t	open;
d_close_t	close;
d_read_t	read;
d_write_t	write;

static struct cdevsw cd_example_cdevsw = 
{
	.d_version = 	D_VERSION;
	.d_open =	open;
	.d_close = 	close;
	.d_read = 	read;
	.d_write = 	write;
	.d_name = 	"cd_example";
};


