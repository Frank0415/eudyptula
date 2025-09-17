/*
 * A kernel module that prints to the debug log level when loaded.
 */
#define MODULE
#define LINUX
#define __KERNEL__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int init_mod(void)
{
    printk(KERN_DEBUG "Good morning ve482!\n");
    return 0;
}

static void cleanup_mod(void)
{
    printk(KERN_DEBUG "exit by ve482.\n");
}

module_init(init_mod);
module_exit(cleanup_mod);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Frank Shi");