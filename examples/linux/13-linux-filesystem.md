# Linux Filesystem

This section covers the Linux filesystem hierarchy, important directories, and filesystem-related commands.

# Linux Filesystem Hierarchy

The Linux filesystem follows the Filesystem Hierarchy Standard (FHS), which defines the directory structure and directory contents.

## Important Directories

- **/** - Root directory (the starting point of the filesystem)
- **/bin** - Essential user binaries (commands)
- **/boot** - Boot loader files, Linux kernel
- **/dev** - Device files
- **/etc** - System configuration files
- **/home** - User home directories
- **/lib** - Essential shared libraries and kernel modules
- **/media** - Mount point for removable media
- **/mnt** - Mount point for temporarily mounted filesystems
- **/opt** - Optional application software packages
- **/proc** - Virtual filesystem for process and system information
- **/root** - Home directory for the root user
- **/run** - Run-time variable data
- **/sbin** - System binaries (system administration commands)
- **/srv** - Data for services provided by the system
- **/sys** - Virtual filesystem for system hardware information
- **/tmp** - Temporary files
- **/usr** - Secondary hierarchy for user data (includes binaries, libraries, documentation)
- **/var** - Variable data (logs, spool files, temporary e-mail files)

## Root Directory (/)

The root directory is the top-level directory in the Linux filesystem hierarchy. All other directories are subdirectories of the root, either directly or indirectly. When referenced in paths, the root directory is denoted by a single forward slash `/`.

## /bin

Contains essential command binaries (programs) that are needed in single-user mode and by all users of the system.

**Key Contents:**
- Basic commands: `bash`, `cp`, `mv`, `rm`, `ls`, `cat`, etc.
- Core utilities that need to be available even if only the root partition is mounted

## /boot

Contains files needed to boot the system.

**Key Contents:**
- Linux kernel (typically `vmlinuz-*`)
- Initial RAM disk (initrd or initramfs)
- Bootloader configuration files (GRUB)
- Boot loader stage files

## /dev

Contains device files that represent physical and virtual devices on the system.

**Key Contents:**
- Character devices (e.g., `/dev/tty1`, `/dev/null`)
- Block devices (e.g., `/dev/sda`, `/dev/nvme0n1`)
- Pseudo-devices (e.g., `/dev/random`, `/dev/urandom`)
- Device symbolic links (e.g., `/dev/cdrom`)

## /etc

Contains system-wide configuration files and shell scripts used during system boot.

**Key Contents:**
- System configuration files
- Network configuration (`/etc/network/`, `/etc/netplan/`)
- Service configurations (`/etc/ssh/`, `/etc/nginx/`)
- User database (`/etc/passwd`, `/etc/shadow`)
- Group database (`/etc/group`)
- Host information (`/etc/hostname`, `/etc/hosts`)
- System initialization and boot (`/etc/systemd/`)
- Package management information (`/etc/apt/`, `/etc/yum.repos.d/`)

## /home

Contains user home directories. Each user typically has a subdirectory named after their username.

**Key Contents:**
- User-specific configuration files (dotfiles)
- User documents, downloads, and personal files
- User-specific application settings

## /lib and /lib64

Contains essential shared libraries and kernel modules needed to boot the system and run the commands in `/bin` and `/sbin`.

**Key Contents:**
- Shared libraries (`.so` files)
- Kernel modules under `/lib/modules/`
- Firmware files under `/lib/firmware/`
- On 64-bit systems, `/lib64` contains 64-bit libraries

## /media

Mount point for removable media such as USB drives, CD-ROMs, etc.

**Key Contents:**
- Subdirectories for automatically mounted devices
- Named mount points (often named after the device label or ID)

## /mnt

Temporary mount point for manually mounted filesystems.

**Usage:**
- Traditionally used for temporary filesystem mounts
- Useful for mounting network shares, additional drives, or for recovery operations

## /opt

Contains optional software packages and add-on applications.

**Usage:**
- Commercial software installations often go here
- Self-contained application directories
- Each application typically uses a subdirectory like `/opt/application-name/`

## /proc

A virtual filesystem that provides information about processes and system information.

**Key Contents:**
- Process directories (named by PID)
- System information files
- Kernel parameters (`/proc/sys/`)
- Memory information (`/proc/meminfo`)
- CPU information (`/proc/cpuinfo`)
- Loaded modules (`/proc/modules`)

## /root

Home directory for the root user. Similar to directories in `/home/` but specifically for the superuser.

## /run

Contains runtime data for processes started since the last boot. This data is typically cleared at boot time.

**Key Contents:**
- PID files
- Lock files
- Socket files
- System state information

## /sbin

Contains system binaries (commands) essential for system administration. These commands are typically used by the system administrator.

**Key Contents:**
- System administration commands: `fdisk`, `mkfs`, `fsck`, `ifconfig`, etc.
- System initialization commands

## /srv

Contains data for services provided by the system, such as web servers, FTP servers, etc.

**Example Structure:**
- `/srv/www/` - Web server data
- `/srv/ftp/` - FTP server data

## /sys

A virtual filesystem that provides a view into the kernel's device tree. It exposes information about devices, drivers, and some kernel features.

**Key Contents:**
- Device information
- Driver information
- Power management
- USB device details
- Block device parameters

## /tmp

Contains temporary files created by system and users. These files may be deleted when the system is rebooted.

**Usage:**
- Many applications store temporary data here
- Often mounted as a tmpfs (memory-based filesystem)
- Typically has permissions allowing all users to write

## /usr

Secondary hierarchy containing user binaries, libraries, documentation, and source code. This directory contains non-essential files for multi-user functionality.

**Key Contents:**
- `/usr/bin/` - User commands
- `/usr/sbin/` - System administration commands
- `/usr/lib/` - Libraries
- `/usr/local/` - Locally installed software
- `/usr/share/` - Architecture-independent data
- `/usr/include/` - Header files for C programming
- `/usr/src/` - Source code

## /var

Contains variable data files. This includes logs, spool files, temporary e-mail files, and other files that change during the normal operation of the system.

**Key Contents:**
- `/var/log/` - Log files
- `/var/cache/` - Application cache data
- `/var/spool/` - Spool for tasks waiting to be processed
- `/var/mail/` - User mailboxes
- `/var/lib/` - Variable state information

## Important Files

| File                                               | Description                                           |
|----------------------------------------------------|-------------------------------------------------------|
| `/etc/passwd`                                      | User account information                              |
| `/etc/shadow`                                      | Secure user account information (encrypted passwords) |
| `/etc/group`                                       | Group definitions                                     |
| `/etc/sudoers`                                     | Sudo configuration                                    |
| `/etc/fstab`                                       | Filesystem table (mount points)                       |
| `/etc/hosts`                                       | Static hostname to IP mappings                        |
| `/etc/resolv.conf`                                 | DNS resolver configuration                            |
| `/etc/hostname`                                    | System hostname                                       |
| `/etc/network/interfaces` or `/etc/netplan/*.yaml` | Network configuration                                 |
| `/etc/ssh/sshd_config`                             | SSH server configuration                              |
| `/var/log/syslog` or `/var/log/messages`           | System logs                                           |
| `/var/log/auth.log` or `/var/log/secure`           | Authentication logs                                   |
| `/boot/grub/grub.cfg` or `/boot/grub2/grub.cfg`    | GRUB bootloader configuration                         |
| `/etc/crontab`                                     | System-wide cron jobs                                 |

## Filesystem Types

Linux supports various filesystem types:

| Filesystem | Description                                                                       |
|------------|-----------------------------------------------------------------------------------|
| `ext4`     | Fourth Extended Filesystem (default on many Linux distributions)                  |
| `xfs`      | High-performance journaling filesystem (default on some enterprise distributions) |
| `btrfs`    | B-tree filesystem with advanced features like snapshots and RAID                  |
| `f2fs`     | Flash-Friendly File System (optimized for SSDs)                                   |
| `zfs`      | Advanced filesystem with volume management capabilities                           |
| `tmpfs`    | In-memory filesystem for temporary files                                          |
| `vfat`     | Compatible with Windows FAT32 (often used on USB drives)                          |
| `ntfs`     | Windows NTFS filesystem (read/write support via NTFS-3G)                          |
| `exfat`    | Extended FAT filesystem (for large files on external media)                       |
| `nfs`      | Network File System for accessing files over a network                            |
| `cifs/smb` | Common Internet File System/Server Message Block (for Windows shares)             |

## Filesystem Management Commands

### df

Displays disk space usage for mounted filesystems.

```bash
df [options] [filesystem]
```

**Options:**
- `-h`: Human-readable sizes
- `-T`: Show filesystem type
- `-i`: Show inode information
- `-a`: Include pseudo, duplicate, and inaccessible filesystems

**Examples:**
```bash
# Show disk space usage in human-readable format
df -h

# Show filesystem types along with usage
df -hT

# Show inode usage
df -i
```

### du

Estimates file and directory space usage.

```bash
du [options] [file or directory]
```

**Options:**
- `-h`: Human-readable sizes
- `-s`: Summary (only total for each argument)
- `-a`: Include files, not just directories
- `-c`: Produce a grand total
- `--max-depth=N`: Show totals for directories N or fewer levels below

**Examples:**
```bash
# Show disk usage for a directory
du -h /var/log

# Show total size only
du -sh /home/user

# Show usage for each file/directory with a grand total
du -ach /etc
```

### mount

Mounts a filesystem.

```bash
mount [options] [device] [mountpoint]
```

**Options:**
- `-t type`: Specify filesystem type
- `-o options`: Mount options
- `-a`: Mount all filesystems in fstab
- `-r`: Mount read-only
- `-v`: Verbose

**Examples:**
```bash
# Mount a USB drive
sudo mount /dev/sdb1 /mnt/usb

# Mount with specific filesystem type
sudo mount -t ext4 /dev/sda2 /mnt/data

# Mount with options
sudo mount -o ro,noexec /dev/sdb1 /mnt/usb

# Mount all filesystems in fstab
sudo mount -a
```

### umount

Unmounts a filesystem.

```bash
umount [options] [device or mountpoint]
```

**Options:**
- `-f`: Force unmount
- `-l`: Lazy unmount
- `-a`: Unmount all filesystems
- `-r`: Remount read-only if unmounting fails

**Examples:**
```bash
# Unmount by mountpoint
sudo umount /mnt/usb

# Unmount by device
sudo umount /dev/sdb1

# Force unmount
sudo umount -f /mnt/usb

# Lazy unmount (useful when device is busy)
sudo umount -l /mnt/usb
```

### lsblk

Lists information about block devices.

```bash
lsblk [options]
```

**Options:**
- `-f`: Show filesystem information
- `-a`: Show all devices, including empty ones
- `-p`: Show full device paths
- `-o columns`: Select columns to display
- `-b`: Show sizes in bytes
- `-d`: Don't list partitions
- `-m`: Show permissions

**Examples:**
```bash
# List all block devices
lsblk

# Show filesystem information
lsblk -f

# Show custom columns
lsblk -o NAME,SIZE,FSTYPE,MOUNTPOINT,UUID
```

### blkid

Prints block device attributes.

```bash
blkid [options] [device]
```

**Options:**
- `-U uuid`: Search for device with specified UUID
- `-L label`: Search for device with specified label
- `-o format`: Output format (full, value, device, list, udev)

**Examples:**
```bash
# Show all block devices with attributes
sudo blkid

# Find device by UUID
sudo blkid -U "a1b2c3d4-e5f6-7890-abcd-1234567890ab"

# Find device by label
sudo blkid -L "SYSTEM"
```

### fdisk

Manipulates disk partition tables.

```bash
fdisk [options] [device]
```

**Options:**
- `-l`: List partition tables for specified devices

**Examples:**
```bash
# List all partition tables
sudo fdisk -l

# Manipulate partitions on a specific disk
sudo fdisk /dev/sdb
```

### mkfs

Creates a filesystem on a device.

```bash
mkfs [options] -t [fstype] [device]
```

**Examples:**
```bash
# Create an ext4 filesystem
sudo mkfs -t ext4 /dev/sdb1

# Create an XFS filesystem
sudo mkfs.xfs /dev/sdc1

# Create a FAT32 filesystem
sudo mkfs.vfat -F 32 /dev/sdd1
```

### fsck

Checks and repairs a filesystem.

```bash
fsck [options] [filesystem]
```

**Options:**
- `-t fstype`: Specify filesystem type
- `-a`: Automatically repair without questions
- `-y`: Assume "yes" to all questions
- `-f`: Force check even if clean
- `-v`: Verbose mode

**Examples:**
```bash
# Check the root filesystem at next boot
sudo touch /forcefsck

# Check a specific filesystem
sudo fsck /dev/sdb1

# Force check and automatically repair
sudo fsck -f -y /dev/sdb1
```

### findmnt

Lists mounted filesystems or searches for a filesystem.

```bash
findmnt [options] [device|mountpoint]
```

**Options:**
- `-t type`: Filter by filesystem type
- `-S source`: Search by source device
- `-T target`: Search by mountpoint
- `-l`: Use list format
- `-r`: Use raw output format
- `-f`: Print full paths

**Examples:**
```bash
# List all mounted filesystems
findmnt

# Find all ext4 filesystems
findmnt -t ext4

# Find filesystem mounted at specific point
findmnt /home

# Find mounts from specific device
findmnt -S /dev/sda1
```

### tune2fs

Adjusts parameters on ext2/ext3/ext4 filesystems.

```bash
tune2fs [options] device
```

**Options:**
- `-l`: List the contents of the filesystem superblock
- `-c max`: Set the maximum mount count
- `-i interval`: Set the check interval
- `-j`: Add journal to ext2 filesystem
- `-L label`: Set volume label

**Examples:**
```bash
# Show filesystem parameters
sudo tune2fs -l /dev/sda1

# Set filesystem label
sudo tune2fs -L "DATA" /dev/sdb1

# Disable automatic fsck at boot (not recommended)
sudo tune2fs -c 0 -i 0 /dev/sda1
```

### e2label

Changes the label on an ext2/ext3/ext4 filesystem.

```bash
e2label device [label]
```

**Examples:**
```bash
# Show current label
sudo e2label /dev/sda1

# Set a new label
sudo e2label /dev/sda1 "ROOT"
```

### fstab

The `/etc/fstab` file contains static filesystem information. Each filesystem is described on a separate line with fields separated by whitespace.

**Format:**
```
[device] [mountpoint] [filesystem] [options] [dump] [pass]
```

**Example `/etc/fstab` entry:**
```
# <file system>   <mount point>   <type>   <options>                       <dump>  <pass>
UUID=123abc...    /               ext4     errors=remount-ro               0       1
/dev/sdb1         /home           ext4     defaults                        0       2
/dev/sdc1         /media/data     xfs      defaults,noatime                0       2
//server/share    /mnt/nas        cifs     credentials=/etc/samba/creds    0       0
tmpfs             /tmp            tmpfs    defaults,size=2G,noexec         0       0
```

**Fields:**
1. **Device**: Device name, UUID, or label
2. **Mount point**: Directory where the filesystem is mounted
3. **Filesystem type**: ext4, xfs, ntfs, etc.
4. **Mount options**: Comma-separated list of options
5. **Dump**: Used by dump utility (0 = don't dump, 1 = dump)
6. **Pass**: Order in which fsck checks filesystems (0 = don't check, 1 = root, 2 = other)
