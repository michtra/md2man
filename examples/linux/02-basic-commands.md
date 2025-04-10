# Basic Commands

These are the most fundamental Linux commands that every user should know. They form the foundation for interacting with the Linux system.

## clear

Clears the terminal screen, giving you a clean workspace.

```bash
clear
```

**Options:**
- `-x`: Don't clear scrollback buffer
- `-T TERM`: Use this terminal type instead of $TERM

## man

Displays the manual pages for commands, providing detailed documentation.

```bash
man [section] command
```

**Options:**
- `-k keyword`: Search for commands related to a specific keyword
- `-f command`: Display a short description of the command
- `-w command`: Print the location of the man page

**Examples:**
```bash
# View the manual for the ls command
man ls

# Search for commands related to "password"
man -k password
```

## echo

Displays text or variable values to the terminal.

```bash
echo [options] [string]
```

**Options:**
- `-n`: Do not output a trailing newline
- `-e`: Enable interpretation of backslash escapes

**Examples:**
```bash
# Print a simple message
echo "Hello World"

# Print without a newline at the end
echo -n "No newline"

# Print with escape sequences interpreted
echo -e "Line 1\nLine 2"
```

## date

Displays or sets the system date and time.

```bash
date [options] [+format]
```

**Options:**
- `+format`: Display date in the specified format
- `-s "string"`: Set time described by string

**Examples:**
```bash
# Display current date and time
date

# Display date in a custom format
date "+%Y-%m-%d %H:%M:%S"

# Set the system date (requires root privileges)
sudo date -s "2025-04-10 12:00:00"
```

## whoami

Displays the username of the current user.

```bash
whoami
```

## exit

Exits the current shell or terminal session.

```bash
exit [n]
```

Where `n` is an optional exit code (0 means success).

## history

Shows the command history for the current user.

```bash
history [options]
```

**Options:**
- `-c`: Clear the history list
- `-d offset`: Delete the history entry at position offset

**Examples:**
```bash
# Show command history
history

# Show the last 10 commands
history 10

# Clear history
history -c
```

## uname

Prints system information.

```bash
uname [options]
```

**Options:**
- `-a`: Show all information
- `-s`: Show kernel name
- `-r`: Show kernel release
- `-v`: Show kernel version
- `-m`: Show machine hardware name
- `-p`: Show processor type
- `-o`: Show operating system

**Examples:**
```bash
# Show all system information
uname -a

# Show only the kernel version
uname -r
```

## alias

Creates shortcuts for commands.

```bash
alias [name[=value]]
```

**Examples:**
```bash
# Create an alias for listing files
alias ll='ls -la'

# List all defined aliases
alias
```

## help

Displays help for shell built-in commands.

```bash
help [command]
```

**Examples:**
```bash
# Get help for the cd command
help cd
```
