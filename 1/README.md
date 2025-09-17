For this part I sourced (one of the more modern version with kernel 5.0+ of) The Linux Kernel Module Programming Guide, [lkmpg 4.2](https://sysprog21.github.io/lkmpg/#hello-and-goodbye), to learn about how to program and Makefile.

For generating the clang compilation database, I used `Bear -- make`. By loading the modules using `sudo insmod main.ko` and unloading using `sudo rmmod main`, I was able to see the output in the kernel log using `journalctl`. The following are the results:

```bash
journalctl --since "1 minute ago" | grep "ve482" > README
```

```bash
Sep 17 18:37:15 xarch kernel: Good morning ve482!
Sep 17 18:37:22 xarch kernel: exit by ve482.
```