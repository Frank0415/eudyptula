I cloned from `https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git`, and compiled `6.17-rc6` kernel, with the options copied from my current linux with some tweaks, including the `CONFIG_LOCALVERSION_AUTO=y` and appended info to `CONFIG_LOCALVERSION`. The output from: `sudo grub-mkconfig -o /boot/grub/grub.cfg`

```bash
Generating grub configuration file ...
Found linux image: /boot/vmlinuz-linux
Found initrd image: /boot/intel-ucode.img /boot/initramfs-linux.img
Found fallback initrd image(s) in /boot:  intel-ucode.img initramfs-linux-fallback.img
Found linux image: /boot/vmlinuz-6.17.0-rc6-VE482-Challenge-YuzhaoShi-00007-g5aca7966d2a7
Found initrd image: /boot/intel-ucode.img
Warning: os-prober will be executed to detect other bootable partitions.
Its output will be used to detect bootable binaries on them and create new boot entries.
Found Windows Boot Manager on /dev/nvme0n1p1@/EFI/Microsoft/Boot/bootmgfw.efi
Adding boot menu entry for UEFI Firmware Settings ...
done
```

Booting into the new kernel and use `uname -r` and `sudo dmesg | grep "Linux version"`:
```bash
6.17.0-rc6-VE482-Challenge-YuzhaoShi-00007-g5aca7966d2a7
```

```Bash
[    0.000000] Linux version 6.17.0-rc6-VE482-Challenge-YuzhaoShi-00007-g5aca7966d2a7 (frank@xarch) (gcc (GCC) 15.2.1 20250813, GNU ld (GNU Binutils) 2.45.0) #1 SMP PREEMPT_DYNAMIC Wed Sep 17 23:34:57 CST 2025
```