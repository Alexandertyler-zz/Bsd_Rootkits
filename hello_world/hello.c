/* This is an updated version of the hello world KLD as 
 * described in Joseph Kong's book, Designing BSD Rootkits
 */

#include <sys/param.h>
#include <sys/module.h>
#include <sys/kernel.h>
#include <sys/systm.h>

static int
load (struct module *module, int cmd, void *arg)
{
	/* Set up error code we return, initialized at 0 */	
	int error = 0;

	switch (cmd)
	{
		case MOD_LOAD:
			uprintf("Hello world!\n");
			break;

		case MOD_UNLOAD:
			uprintf("Goodbye, cruel world!\n");
			break;

		default:
			error = EOPNOTSUPP;
			break;
	}

	/* we only return if the module needs to exit, either a 0 as success
	 * or an EOPNOTSUPP for error
	 */
	return (error);
}

static moduledata_t hello_mod = {
	"hello",
	load,
	NULL
};

DECLARE_MODULE (hello, hello_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE);
