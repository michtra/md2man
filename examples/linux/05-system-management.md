# System Management

These commands help you manage and monitor system resources, services, and system-level operations.

## systemctl

Controls the systemd system and service manager, which is the foundation of most modern Linux distributions.

```bash
systemctl [options] command [unit]
```

**Common commands:**
- `start`: Start a unit
- `stop`: Stop a unit
- `restart`: Restart a unit
- `status`: Show status of a unit
- `enable`: Enable a unit to start at boot
- `disable`: Disable a unit from starting at boot
- `reload`: Reload a unit's configuration
- `mask`: Completely disable a unit
- `unmask`: Remove mask from a unit
- `list-units`: List loaded units

**Examples:**
```bash
# Check status of a service
systemctl status nginx

# Start a service
sudo systemctl start nginx

# Enable a service to start at boot
sudo systemctl enable nginx

# Restart a service
sudo systemctl restart nginx

# List all active services
systemctl list-units --type=service --state=active
```

## journalctl

Queries the systemd journal, which contains logs from the system and services.

```bash
journalctl [options]
```

**Options:**
- `-u unit`: Show logs for the specified unit
- `-f`: Follow new entries as they are added (like `tail -f`)
- `-b`: Show logs from the current boot
- `-n NUMBER`: Show the last NUMBER of log entries
- `-p PRIORITY`: Filter by priority (0-7)
- `--since "YYYY-MM-DD HH:MM:SS"`: Show entries since the specified time
- `--until "YYYY-MM-DD HH:MM:SS"`: Show entries until the specified time

**Examples:**
```bash
# View system logs
journalctl

# Follow logs in real-time
journalctl -f

# View logs for a specific service
journalctl -u nginx

# View recent logs
journalctl -n 100

# View logs from today
journalctl --since "today"

# View logs with errors and critical issues only
journalctl -p err..crit
```

## df

Reports file system disk space usage.

```bash
df [options] [file]
```

**Options:**
- `-h`: Human-readable output
- `-T`: Print file system type
- `-i`: List inode information instead of block usage
- `-a`: Include dummy file systems

**Examples:**
```bash
# Show disk space in human-readable format
df -h

# Show file system types along with usage
df -hT

# Show inode usage
df -i
```

## free

Displays amount of free and used memory in the system.

```bash
free [options]
```

**Options:**
- `-h`: Human-readable output
- `-s SEC`: Update continuously every SEC seconds
- `-t`: Display a line showing totals
- `-m`: Display values in mebibytes
- `-g`: Display values in gibibytes

**Examples:**
```bash
# Show memory usage in human-readable format
free -h

# Show memory usage updated every 2 seconds
free -h -s 2
```

## top

Displays real-time view of system processes.

```bash
top [options]
```

**Options:**
- `-d SEC`: Specify update interval
- `-u USER`: Show only processes from specified user
- `-p PID`: Monitor only processes with specified PID

**Interactive commands:**
- `q`: Quit
- `h`: Help
- `k`: Kill a process
- `r`: Renice a process
- `f`: Configure fields to display
- `o`: Change sort order

**Examples:**
```bash
# Start top with 3-second refresh
top -d 3

# Show only processes from a specific user
top -u username
```

## htop

An interactive process viewer, more user-friendly than top.

```bash
htop [options]
```

**Options:**
- `-u USER`: Show only processes of a given user
- `-d SEC`: Set update interval
- `-s COLUMN`: Sort by specified column

**Interactive commands:**
- `F1-F10`: Various functions (shown at bottom)
- `Space`: Mark process
- `u`: Filter by user
- `k`: Kill process
- `/`: Search

**Examples:**
```bash
# Start htop filtering for root user
htop -u root
```

## reboot

Restarts the system.

```bash
reboot [options]
```

**Options:**
- `--force`: Force reboot
- `--no-wall`: Don't send wall message before reboot

**Examples:**
```bash
# Reboot the system
sudo reboot

# Force reboot
sudo reboot --force
```

## poweroff

Shuts down the system.

```bash
poweroff [options]
```

**Options:**
- `--force`: Force power off
- `--no-wall`: Don't send wall message before poweroff

**Examples:**
```bash
# Shutdown the system
sudo poweroff

# Force shutdown
sudo poweroff --force
```

## shutdown

Shuts down or restarts the system.

```bash
shutdown [options] [time] [message]
```

**Options:**
- `-r`: Reboot after shutdown
- `-h`: Halt or power off after shutdown
- `-c`: Cancel a pending shutdown

**Examples:**
```bash
# Shutdown immediately
sudo shutdown now

# Reboot in 5 minutes with a message
sudo shutdown -r +5 "System maintenance"

# Schedule a shutdown at a specific time
sudo shutdown -h 23:30

# Cancel a scheduled shutdown
sudo shutdown -c
```

## dmesg

Displays kernel ring buffer messages.

```bash
dmesg [options]
```

**Options:**
- `-H`: Human-readable output
- `-l LEVEL`: Filter by level (emerg, alert, crit, err, warn, notice, info, debug)
- `-f FACILITY`: Filter by facility (kern, user, daemon, etc.)
- `-w`: Wait for new messages (follow)
- `-T`: Show human-readable timestamps

**Examples:**
```bash
# Show kernel messages with readable timestamps
dmesg -HT

# Show only error messages
dmesg --level=err

# Follow new kernel messages
dmesg -w
```

## uname

Prints basic system information.

```bash
uname [options]
```

**Options:**
- `-a`: All information
- `-s`: Kernel name
- `-n`: Network node hostname
- `-r`: Kernel release
- `-v`: Kernel version
- `-m`: Machine hardware name
- `-p`: Processor type
- `-o`: Operating system

**Examples:**
```bash
# Show all system information
uname -a

# Show only kernel version
uname -r

# Show machine architecture
uname -m
```

## lsblk

Lists information about block devices.

```bash
lsblk [options]
```

**Options:**
- `-a`: List all devices
- `-f`: Show filesystem information
- `-p`: Show full device paths
- `-S`: List only SCSI devices
- `-o LIST`: Select output columns

**Examples:**
```bash
# List all block devices with basic info
lsblk

# Show filesystem information
lsblk -f

# Show full paths with size and type
lsblk -po NAME,SIZE,TYPE
```

## blkid

Locates/prints block device attributes.

```bash
blkid [options] [device]
```

**Options:**
- `-U UUID`: Search for device with the specified UUID
- `-L LABEL`: Search for device with the specified label

**Examples:**
```bash
# Show all block devices with attributes
sudo blkid

# Find device with specific UUID
sudo blkid -U "a1b2c3d4-e5f6-7890-abcd-1234567890ab"
```

## lsof

Lists open files.

```bash
lsof [options]
```

**Options:**
- `-u USER`: Files opened by user
- `-p PID`: Files opened by process
- `-c command`: Files opened by command starting with string

**Examples:**
```bash
# Show all open files
sudo lsof

# Show all open network connections
sudo lsof -i

# Show files opened by a specific user
sudo lsof -u username

# Show all files opened by a process
sudo lsof -p 1234

# Show which process is using a specific port
sudo lsof -i :80
```

## mount/umount

Mounts/unmounts filesystems.

```bash
mount [options] [device] [directory]
umount [options] [device|directory]
```

**Options (mount):**
- `-t type`: Specify filesystem type
- `-o options`: Specify mount options
- `-a`: Mount all filesystems in /etc/fstab
- `-r`: Mount read-only

**Options (umount):**
- `-f`: Force unmount
- `-l`: Lazy unmount

**Examples:**
```bash
# Mount a device to a directory
sudo mount /dev/sdb1 /mnt/usb

# Mount with specific filesystem type and options
sudo mount -t ext4 -o rw,noatime /dev/sda2 /home

# Unmount a filesystem
sudo umount /mnt/usb

# Force unmount when device is busy
sudo umount -f /mnt/usb
```

## fdisk

Manipulates disk partition table.

```bash
fdisk [options] [device]
```

**Options:**
- `-l`: List partition tables

**Interactive commands:**
- `m`: Show help menu
- `p`: Print partition table
- `n`: Add a new partition
- `d`: Delete a partition
- `w`: Write changes to disk and exit
- `q`: Quit without saving changes

**Examples:**
```bash
# List all partitions
sudo fdisk -l

# Manipulate partitions on a specific disk
sudo fdisk /dev/sdb
```

## mkfs

Creates a filesystem on a device or partition.

```bash
mkfs [options] -t [fstype] [device]
```

**Common filesystem types:**
- `ext4`: Extended filesystem 4
- `xfs`: XFS filesystem
- `btrfs`: B-tree filesystem
- `vfat`: FAT filesystem

**Examples:**
```bash
# Create an ext4 filesystem
sudo mkfs -t ext4 /dev/sdb1

# Create an XFS filesystem
sudo mkfs.xfs /dev/sdc1

# Create a FAT32 filesystem (for USB drives)
sudo mkfs.vfat -F 32 /dev/sdd1
```

## dd

Copies and converts files, often used for disk images.

```bash
dd [options] operand
```

**Common operands:**
- `if=file`: Input file
- `of=file`: Output file
- `bs=bytes`: Block size
- `count=n`: Copy only n blocks
- `status=progress`: Show progress during copy

**Examples:**
```bash
# Create a disk image
sudo dd if=/dev/sda of=disk.img bs=4M status=progress

# Write an ISO to a USB drive
sudo dd if=ubuntu.iso of=/dev/sdb bs=4M status=progress

# Wipe a disk with zeros
sudo dd if=/dev/zero of=/dev/sdc bs=1M count=1000
```

## timedatectl

Controls the system time and date.

```bash
timedatectl [command]
```

**Commands:**
- `status`: Show current time settings
- `set-time TIME`: Set system time
- `set-timezone ZONE`: Set system timezone
- `list-timezones`: List available timezones
- `set-ntp BOOL`: Enable/disable network time synchronization

**Examples:**
```bash
# Show current time settings
