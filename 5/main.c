#include "linux/kern_levels.h"
#include "linux/printk.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

static int my_usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "VE482: USB Keyboard plugged in!\n");
    return 0;
}

static void my_usb_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "VE482: USB Keyboard disconnected.\n");
}

static const struct usb_device_id my_usb_table[] = {
    [0] = {USB_INTERFACE_INFO(3, 1, 1)},
    [1] = {}};

MODULE_DEVICE_TABLE(usb, my_usb_table);

static struct usb_driver my_usb_driver = {
    .name = "VE482_Challenge_usb_keyboard_driver",
    .id_table = my_usb_table,
    .probe = my_usb_probe,
    .disconnect = my_usb_disconnect,
};

static int __init my_module_init(void)
{
    int result = usb_register(&my_usb_driver);
    if (result)
    {
        pr_err("usb register failed. Error number %d\n", result);
    }
    printk(KERN_INFO "VE482: USB Keyboard Driver Registered.\n");
    return result;
}

static void __exit my_module_exit(void)
{
    usb_deregister(&my_usb_driver);
    printk(KERN_INFO "VE482: USB Keyboard Driver Registered\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Frank Shi");
MODULE_DESCRIPTION("A simple USB Driver for the Eudyptla Challenge");
