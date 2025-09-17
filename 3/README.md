In challenge 2 I changed local version to `CONFIG_LOCALVERSION="-VE482-Challenge-YuzhaoShi"`. This time I deleted the field and tweaked the Makefile to append `ve482challenge` and my name to the `EXTRAVERSION`.

Booting into the new kernel and `sudo dmesg | grep "Linux version"`:
```bash
[    0.000000] Linux version 6.17.0-rc6-ve482challenge-YuzhaoShi-g5aca7966d2a7-dirty (frank@xarch) (gcc (GCC) 15.2.1 20250813, GNU ld (GNU Binutils) 2.45.0) #2 SMP PREEMPT_DYNAMIC Thu Sep 18 00:33:22 CST 2025
```

Here are the related commands I use in Challenge 2&3:


```bash
sudo pacman -Syu --needed base-devel git flex bison openssl elfutils bc

zcat /proc/config.gz > .config

make olddefconfig

make -j$(nproc)

sudo make modules_install
```

```bash
# Create a variable to hold the exact kernel version string
VERSION=$(make -s kernelrelease)

# Copy the kernel image
sudo cp -v arch/x86/boot/bzImage /boot/vmlinuz-$VERSION

# Copy the System.map file
sudo cp -v System.map /boot/System.map-$VERSION

# Copy the configuration file
sudo cp -v .config /boot/config-$VERSION

sudo mkinitcpio -k $VERSION -g /boot/initramfs-$VERSION.img

sudo grub-mkconfig -o /boot/grub/grub.cfg
```
