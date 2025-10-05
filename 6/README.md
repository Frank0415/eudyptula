sudo insmod main.ko
sudo rmmod main

read_func / write_func parameters

- struct file *file
    - Opaque kernel-side file descriptor for this open instance. Contains fs-specific state (not used directly in this snippet).

- char __user *buf / const char __user *buf
    - Pointer into user-space memory where data is read to (read_func) or taken from (write_func). The __user annotation documents that the pointer is in user space and must be accessed with copy_to_user / copy_from_user.

size_t count
Number of bytes the caller wants to read or write. The implementation should cap this to available buffer size and return the actual number copied.

loff_t *ppos
Pointer to the file position (offset). The function should use it to implement offset-based reads/writes and update it by the number of bytes transferred. Returning 0 from read means EOF at that offset.
return type: ssize_t

On success returns number of bytes transferred. On error returns a negative errno (e.g. -EFAULT when copy_to_user/copy_from_user fails). Returning 0 from read signals EOF.
file_operations struct fields used

.owner = THIS_MODULE
Prevents the module from being freed while its file ops are in use.
.read / .write
Pointers to the read and write handler functions used when user code does read(2)/write(2) on the device.
miscdevice fields used

.minor = MISC_DYNAMIC_MINOR
Kernel assigns an available minor number for this misc device.
.name = "ve482challenge"
Name exposed in /dev and used for the device entry.
.fops = &files
The file_operations to use for this device.
.mode = 0666
Permission bits for the device node (read/write for owner/group/others).
helpers and macros referenced

copy_to_user / copy_from_user
Safely copy data between kernel and user space; return nonzero on failure.
misc_register / misc_deregister
Register/unregister the misc device so the device node appears under /dev.