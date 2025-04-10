# User Management

These commands are used to manage users, groups, and permissions on a Linux system.

## sudo

Executes a command as another user, typically the superuser.

```bash
sudo [options] command
```

**Options:**
- `-u user`: Run command as user instead of root
- `-i`: Simulate initial login (run login shell)
- `-s`: Run the shell specified in the password database
- `-l`: List user's sudo privileges
- `-k`: Invalidate the user's cached credentials

**Examples:**
```bash
# Execute a command as root
sudo apt update

# Execute a command as another user
sudo -u postgres psql

# Run a shell as root
sudo -i

# List sudo privileges
sudo -l
```

## su

Switch user or become another user.

```bash
su [options] [username]
```

**Options:**
- `-`: Start a login shell (loads user's environment)
- `-c command`: Execute command as the specified user

**Examples:**
```bash
# Switch to root user
su

# Switch to root with environment
su -

# Switch to another user
su username

# Execute a command as another user
su -c "ls -la /home" username
```

## useradd

Creates a new user.

```bash
useradd [options] username
```

**Options:**
- `-m`: Create home directory
- `-s shell`: Specify the login shell
- `-g group`: Specify primary group
- `-G groups`: Specify supplementary groups
- `-c comment`: Set the GECOS field (user info)
- `-d dir`: Home directory path
- `-e date`: Account expiration date

**Examples:**
```bash
# Create a new user with default settings
sudo useradd username

# Create a user with home directory and bash shell
sudo useradd -m -s /bin/bash username

# Create a user with specific groups
sudo useradd -m -G sudo,docker username
```

## adduser

A more user-friendly frontend to useradd (on Debian-based systems).

```bash
adduser [options] username
```

**Options:**
- `--system`: Create a system user
- `--group`: Create a user group with the same name
- `--home DIR`: Specify home directory

**Examples:**
```bash
# Create a new user interactively
sudo adduser username

# Create a system user
sudo adduser --system username
```

## usermod

Modifies user account settings.

```bash
usermod [options] username
```

**Options:**
- `-a -G groups`: Add to supplementary groups
- `-g group`: Change primary group
- `-s shell`: Change login shell
- `-L`: Lock the user account
- `-U`: Unlock the user account
- `-d dir`: Change home directory
- `-m`: Move contents of current home to new home

**Examples:**
```bash
# Add user to the sudo group
sudo usermod -a -G sudo username

# Change user's shell
sudo usermod -s /bin/zsh username

# Lock a user account
sudo usermod -L username

# Change home directory and move contents
sudo usermod -d /newhome/username -m username
```

## userdel

Deletes a user account.

```bash
userdel [options] username
```

**Options:**
- `-r`: Remove home directory and mail spool
- `-f`: Force removal

**Examples:**
```bash
# Delete a user
sudo userdel username

# Delete a user and their home directory
sudo userdel -r username
```

## passwd

Changes user password.

```bash
passwd [options] [username]
```

**Options:**
- `-l`: Lock the user account
- `-u`: Unlock the user account
- `-d`: Delete the password
- `-e`: Expire the password (user must change at next login)
- `-S`: Display password status

**Examples:**
```bash
# Change your own password
passwd

# Change another user's password (as root)
sudo passwd username

# Lock a user account
sudo passwd -l username

# Force user to change password at next login
sudo passwd -e username

# Check password status
sudo passwd -S username
```

## groupadd

Creates a new group.

```bash
groupadd [options] groupname
```

**Options:**
- `-g GID`: Use GID for the new group
- `-r`: Create a system group

**Examples:**
```bash
# Create a new group
sudo groupadd developers

# Create a new group with specific GID
sudo groupadd -g 1010 developers
```

## groupmod

Modifies a group.

```bash
groupmod [options] groupname
```

**Options:**
- `-n new_name`: Change the group name
- `-g GID`: Change the group ID

**Examples:**
```bash
# Rename a group
sudo groupmod -n devs developers

# Change a group's GID
sudo groupmod -g 1020 developers
```

## groupdel

Deletes a group.

```bash
groupdel [options] groupname
```

**Examples:**
```bash
# Delete a group
sudo groupdel developers
```

## groups

Shows group membership for a user.

```bash
groups [username]
```

**Examples:**
```bash
# Show your group memberships
groups

# Show another user's group memberships
groups username
```

## id

Displays user and group IDs.

```bash
id [options] [username]
```

**Options:**
- `-u`: Print only the user ID
- `-g`: Print only the effective group ID
- `-G`: Print all group IDs
- `-n`: Print names instead of numbers

**Examples:**
```bash
# Show your user and group information
id

# Show information for another user
id username

# Show only username
id -un username

# Show all groups (names) for a user
id -nG username
```

## chage

Changes user password expiry information.

```bash
chage [options] username
```

**Options:**
- `-l`: List account aging information
- `-m days`: Set minimum days between password changes
- `-M days`: Set maximum days until password change required
- `-d date`: Set last password change date
- `-E date`: Set account expiration date
- `-I days`: Set inactive days after password expires

**Examples:**
```bash
# List password aging information
sudo chage -l username

# Set password to expire in 90 days
sudo chage -M 90 username

# Set account expiration date
sudo chage -E 2025-12-31 username

# Force password change at next login
sudo chage -d 0 username
```

## getent

Gets entries from administrative databases.

```bash
getent database [key]
```

**Databases:**
- `passwd`: User accounts
- `group`: Groups
- `hosts`: Host names and IP addresses
- `services`: Network services

**Examples:**
```bash
# Get all users
getent passwd

# Get information about a specific user
getent passwd username

# Get all groups
getent group

# Get information about a specific group
getent group groupname

# Lookup hostname
getent hosts example.com
```

## who

Shows who is logged on.

```bash
who [options]
```

**Options:**
- `-a`: Shows all information
- `-b`: Show time of last system boot
- `-r`: Show current runlevel
- `-H`: Show column headings

**Examples:**
```bash
# Show logged-in users
who

# Show all information
who -a

# Show with headers
who -H
```

## w

Shows who is logged on and what they are doing.

```bash
w [options] [user]
```

**Options:**
- `-h`: Don't print header
- `-s`: Short format
- `-f`: Toggle FROM field (remote hostname)

**Examples:**
```bash
# Show logged-in users and their activity
w

# Show information for a specific user
w username
```

## last

Shows listing of last logged-in users.

```bash
last [options] [username] [tty]
```

**Options:**
- `-n number`: Limit to number of lines
- `-R`: Don't display hostname field
- `-a`: Display hostname in the last column

**Examples:**
```bash
# Show recent logins
last

# Show last 10 logins
last -n 10

# Show logins for a specific user
last username
```

## lastlog

Reports the most recent login of all users.

```bash
lastlog [options]
```

**Options:**
- `-u uid`: Show lastlog record for the specified user
- `-t days`: Show only records more recent than days

**Examples:**
```bash
# Show login information for all users
lastlog

# Show information for a specific user
lastlog -u username

# Show users who logged in in the last 7 days
lastlog -t 7
```

## chmod/chown/chgrp

These commands change file permissions, ownership, and group.

See [File Management](04-file-management.md) for details on these commands.
