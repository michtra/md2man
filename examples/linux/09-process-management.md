# Process Management

These commands help you monitor and control processes running on your Linux system.

## ps

Displays information about active processes.

```bash
ps [options]
```

**Options:**
- `-e`: Show all processes
- `-f`: Full format listing
- `-l`: Long format
- `-u username`: Show processes for specific user
- `-p pid`: Show specific process ID
- `--sort=criteria`: Sort output
- `-o format`: Specify output format

**Examples:**
```bash
# Show all processes
ps -e

# Show all processes with full details
ps -ef

# Show processes for current user
ps -u $(whoami)

# Show process tree
ps -ejH

# Show processes sorted by memory usage
ps -e --sort=-%mem

# Show processes sorted by CPU usage
ps -e --sort=-%cpu

# Custom format (PID, user, command, CPU, memory)
ps -eo pid,user,comm,%cpu,%mem --sort=-%cpu
```

## top

Interactive dynamic real-time process viewer.

```bash
top [options]
```

**Options:**
- `-d seconds`: Specify update interval
- `-u username`: Show only processes of a specific user
- `-p pid`: Monitor only specific PIDs
- `-n number`: Update a specific number of times, then exit
- `-b`: Batch mode (non-interactive)

**Interactive commands (when top is running):**
- `q`: Quit
- `h` or `?`: Help
- `k`: Kill a process
- `r`: Renice a process
- `u`: Filter by user
- `f`: Select fields to display
- `o` or `O`: Change sort field
- `M`: Sort by memory usage
- `P`: Sort by CPU usage
- `t`: Toggle task/cpu display
- `c`: Toggle command line/program name
- `W`: Write configuration

**Examples:**
```bash
# Run top with 3-second refresh
top -d 3

# Run top for specific user
top -u username

# Monitor specific PIDs
top -p 1234,5678
```

## htop

An enhanced, interactive process viewer (more user-friendly than top).

```bash
htop [options]
```

**Options:**
- `-u username`: Show only processes of a specific user
- `-p pid,pid...`: Show only specified processes
- `-d seconds`: Delay between updates
- `-s column`: Sort by column

**Interactive commands (when htop is running):**
- `F1-F10`: Various functions (shown at bottom)
- `q`: Quit
- `h`: Help
- `u`: Filter by user
- `F4` or `/`: Search
- `F5`: Tree view
- `F6`: Sort by column
- `F9`: Kill process
- `F10`: Quit

**Examples:**
```bash
# Start htop
htop

# Monitor specific user's processes
htop -u username

# Start htop with processes sorted by memory usage
htop -s PERCENT_MEM
```

## kill

Sends a signal to processes.

```bash
kill [options] pid...
```

**Options:**
- `-l`: List available signals
- `-s signal` or `-signal`: Specify signal to send
- `-9`: SIGKILL (forceful termination)
- `-15`: SIGTERM (graceful termination, default)

**Common signals:**
- `1` (SIGHUP): Hangup
- `2` (SIGINT): Interrupt (like Ctrl+C)
- `9` (SIGKILL): Kill (can't be caught or ignored)
- `15` (SIGTERM): Terminate (default)

**Examples:**
```bash
# Send SIGTERM (default) to a process
kill 1234

# Force kill a process
kill -9 1234

# List available signals
kill -l

# Send HUP signal (often used to reload configurations)
kill -s HUP 1234
```

## killall

Kills processes by name.

```bash
killall [options] name...
```

**Options:**
- `-i`: Interactive mode, ask for confirmation
- `-I`: Ignore case in process name
- `-e`: Exact match
- `-signal`: Specify signal
- `-u user`: Kill only processes owned by user
- `-v`: Verbose output

**Examples:**
```bash
# Kill all processes with a specific name
killall firefox

# Force kill all processes
killall -9 firefox

# Kill processes owned by a specific user
killall -u username firefox

# Interactive kill with confirmation
killall -i firefox
```

## pkill

Sends signal to processes based on name and other attributes.

```bash
pkill [options] pattern
```

**Options:**
- `-f`: Match against full command line
- `-u username`: Match only processes owned by user
- `-t terminal`: Match only processes running on terminal
- `-signal`: Specify signal
- `-n`: Match only newest process
- `-o`: Match only oldest process

**Examples:**
```bash
# Kill processes matching pattern
pkill firefox

# Kill processes matching full command line
pkill -f "firefox -private"

# Kill processes owned by specific user
pkill -u username firefox

# Send specific signal
pkill -HUP nginx
```

## pgrep

Lists process IDs matching criteria.

```bash
pgrep [options] pattern
```

**Options:**
- `-f`: Match against full command line
- `-u username`: Match only processes owned by user
- `-t terminal`: Match only processes running on terminal
- `-l`: List process name along with PID
- `-a`: List full command line
- `-n`: Match only newest process
- `-o`: Match only oldest process

**Examples:**
```bash
# Find PIDs matching pattern
pgrep firefox

# Show process names along with PIDs
pgrep -l firefox

# Find processes matching full command line
pgrep -f "firefox -private"

# Find processes owned by specific user
pgrep -u username firefox

# List full command line
pgrep -a firefox
```

## nice

Runs a command with modified scheduling priority.

```bash
nice [options] command [arguments]
```

**Options:**
- `-n adjustment`: Specify priority adjustment (-20 to 19, default 10)

**Examples:**
```bash
# Run command with lower priority (nice value 10)
nice tar -czf backup.tar.gz /home

# Specify nice value (higher number = lower priority)
nice -n 15 tar -czf backup.tar.gz /home

# Specify nice value (lower number = higher priority)
sudo nice -n -10 important_task
```

## renice

Alters priority of running processes.

```bash
renice priority [options] identifier
```

**Options:**
- `-p`: Interpret identifiers as process IDs (default)
- `-u`: Interpret identifiers as usernames
- `-g`: Interpret identifiers as group IDs

**Examples:**
```bash
# Change priority of a process
sudo renice -n 10 -p 1234

# Change priority for all processes owned by a user
sudo renice -n 5 -u username
```

## nohup

Runs a command immune to hangups, with output to a non-tty.

```bash
nohup command [arguments]
```

**Examples:**
```bash
# Run command that continues after logout
nohup long_running_script.sh &

# Specify output file (default is nohup.out)
nohup long_running_script.sh > output.log 2>&1 &
```

## bg

Resumes suspended jobs in the background.

```bash
bg [job_spec...]
```

**Examples:**
```bash
# Resume the most recently suspended job in background
bg

# Resume specific job in background
bg %1
```

## fg

Brings jobs to the foreground.

```bash
fg [job_spec...]
```

**Examples:**
```bash
# Bring most recently backgrounded job to foreground
fg

# Bring specific job to foreground
fg %1
```

## jobs

Lists active jobs.

```bash
jobs [options]
```

**Options:**
- `-l`: List process IDs in addition to normal information
- `-p`: List process IDs only
- `-r`: Restrict output to running jobs
- `-s`: Restrict output to stopped jobs

**Examples:**
```bash
# List all jobs
jobs

# List jobs with PIDs
jobs -l

# List only running jobs
jobs -r
```

## at

Executes commands at a specified time.

```bash
at time [date] [options]
```

**Options:**
- `-f file`: Read commands from file
- `-m`: Send mail to user when job is completed
- `-l`: List queued jobs (same as atq)
- `-r`: Remove jobs (same as atrm)

**Examples:**
```bash
# Schedule a command for a specific time
at 10:00 AM
command1
command2
Ctrl-D

# Schedule a command for a future date
at 10:00 AM July 31

# Read commands from a file
at -f commands.txt 10:00 PM
```

## atq

Lists pending jobs for the at command.

```bash
atq
```

## atrm

Deletes jobs queued by the at command.

```bash
atrm job_number
```

**Examples:**
```bash
# Remove job number 23
atrm 23
```

## crontab

Schedules periodic background jobs.

```bash
crontab [options]
```

**Options:**
- `-e`: Edit crontab
- `-l`: List crontab entries
- `-r`: Remove crontab
- `-u user`: Specify user's crontab

**Crontab format:**
```
* * * * * command
| | | | |
| | | | +-- Day of week (0-7, where 0 and 7 are Sunday)
| | | +---- Month (1-12)
| | +------ Day of month (1-31)
| +-------- Hour (0-23)
+---------- Minute (0-59)
```

**Examples:**
```bash
# Edit your crontab
crontab -e

# List your crontab entries
crontab -l

# Remove your crontab
crontab -r

# Examples of crontab entries:
# Run at 5:00 AM every day
0 5 * * * /path/to/script.sh

# Run every hour
0 * * * * /path/to/script.sh

# Run every 15 minutes
*/15 * * * * /path/to/script.sh

# Run at 2:30 PM on the first of every month
30 14 1 * * /path/to/script.sh

# Run at midnight on weekdays (Monday-Friday)
0 0 * * 1-5 /path/to/script.sh
```

## lsof

Lists open files and the processes that opened them.

```bash
lsof [options]
```

**Options:**
- `-p pid`: List files opened by process
- `-u user`: List files opened by user
- `-c command`: List files opened by command

**Examples:**
```bash
# Show all open files
sudo lsof

# Show files opened by a specific process
sudo lsof -p 1234

# Show files opened by a specific user
sudo lsof -u username

# Show processes using a specific port
sudo lsof -i :80

# Show all network connections
sudo lsof -i
```

## strace

Traces system calls and signals.

```bash
strace [options] command
```

**Options:**
- `-p pid`: Attach to process with PID
- `-f`: Trace child processes
- `-e expr`: Filter which events to trace
- `-o file`: Write output to file
- `-c`: Count time, calls, and errors and report summary

**Examples:**
```bash
# Trace system calls made by a command
strace ls -l

# Attach to running process
sudo strace -p 1234

# Trace only specific system calls
strace -e open,read ls -l

# Trace with child processes
strace -f ./script.sh

# Generate summary report
strace -c ls -l

# Save trace to a file
strace -o trace.txt ls -l
```

## time

Times a simple command or gives resource usage.

```bash
time [options] command [arguments...]
```

**Options:**
- `-p`: Use the POSIX output format
- `-v`: Verbose output with detailed resource usage

**Examples:**
```bash
# Time a command
time ls -R /

# Verbose timing information
/usr/bin/time -v gcc -o program program.c
```
