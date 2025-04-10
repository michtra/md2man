# System Navigation

These commands help you navigate the Linux file system and find information about files and directories.

## cd

Changes the current working directory.

```bash
cd [directory]
```

**Special directories:**
- `cd ~`: Change to your home directory
- `cd -`: Change to the previous directory
- `cd ..`: Change to the parent directory
- `cd /`: Change to the root directory

**Examples:**
```bash
# Change to home directory
cd ~

# Change to /etc directory
cd /etc

# Go up one directory level
cd ..

# Go to the previous directory
cd -
```

## ls

Lists files and directories in the current directory.

```bash
ls [options] [directory]
```

**Options:**
- `-l`: List in long format (permissions, owner, size, date)
- `-a`: List all files (including hidden files)
- `-h`: Human-readable file sizes
- `-S`: Sort by file size
- `-t`: Sort by modification time
- `-r`: Reverse order while sorting
- `--color=auto`: Colorize the output

**Examples:**
```bash
# List all files with details
ls -la

# List files sorted by size
ls -lS

# List files with human-readable sizes
ls -lh
```

## pwd

Prints the current working directory (full path).

```bash
pwd [options]
```

**Options:**
- `-L`: Use PWD from environment (logical path)
- `-P`: Show the physical path without symbolic links

## find

Searches for files and directories in a directory hierarchy.

```bash
find [path] [expression]
```

**Common expressions:**
- `-name pattern`: Search by name
- `-type f|d`: Search for files (f) or directories (d)
- `-size n`: Search by size
- `-mtime n`: Search by modification time
- `-exec command {} \;`: Execute a command on found items

**Examples:**
```bash
# Find all .txt files in the current directory and subdirectories
find . -name "*.txt"

# Find all directories named "log"
find / -type d -name log

# Find files larger than 100MB
find /home -type f -size +100M

# Find files modified in the last day
find /var/log -type f -mtime -1
```

## whereis

Locates the binary, source, and manual page files for a command.

```bash
whereis [options] command
```

**Options:**
- `-b`: Search only for binaries
- `-m`: Search only for manual pages
- `-s`: Search only for source files

**Examples:**
```bash
# Find all locations related to the ls command
whereis ls

# Find only the binary for grep
whereis -b grep
```

## which

Shows the full path of shell commands.

```bash
which [options] command
```

**Options:**
- `-a`: Print all matching paths, not just the first

**Examples:**
```bash
# Find the path to the python command
which python

# Find all python executables in PATH
which -a python
```

## tree

Displays directory structure in a tree-like format.

```bash
tree [options] [directory]
```

**Options:**
- `-L level`: Limit the depth of recursion
- `-d`: List directories only
- `-f`: Print the full path prefix for each file
- `-a`: Show all files (including hidden files)

**Examples:**
```bash
# Display directory tree with 2 levels
tree -L 2

# Display only directories
tree -d
```

## locate

Finds files by name using a previously built database.

```bash
locate [options] pattern
```

**Options:**
- `-i`: Ignore case distinctions
- `-c`: Output the number of matching entries
- `-l number`: Limit the output to a specified number of files

**Examples:**
```bash
# Find all files with "config" in the name
locate config

# Find files ignoring case
locate -i README
```

## updatedb

Updates the file name database used by locate.

```bash
sudo updatedb [options]
```

**Options:**
- `-U directory`: Only update the database for the specified directory
