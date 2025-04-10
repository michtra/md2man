# Systemd

Systemd is the init system and service manager for most modern Linux distributions. It provides aggressive parallelization capabilities, uses socket and D-Bus activation for starting services, and offers on-demand starting of daemons.

## systemctl

The primary command for controlling and managing systemd services and the system state.

```bash
systemctl [options] command [unit]
```

**Common Commands:**

**Service Management:**
- `start`: Start a unit
- `stop`: Stop a unit
- `restart`: Restart a unit
- `reload`: Reload configuration
- `status`: Show status of a unit
- `enable`: Enable a unit to start at boot
- `disable`: Disable a unit from starting at boot
- `mask`: Completely disable a unit
- `unmask`: Remove mask from a unit
- `is-active`: Check if a unit is active
- `is-enabled`: Check if a unit is enabled

**System Management:**
- `poweroff`: Power off the system
- `reboot`: Reboot the system
- `suspend`: Suspend the system
- `hibernate`: Hibernate the system
- `rescue`: Enter rescue mode
- `emergency`: Enter emergency mode

**Unit Listing:**
- `list-units`: List loaded units
- `list-unit-files`: List installed unit files

**Examples:**
```bash
# Start a service
sudo systemctl start nginx.service

# Stop a service
sudo systemctl stop nginx.service

# Restart a service
sudo systemctl restart nginx.service

# Reload service configuration (without restarting)
sudo systemctl reload nginx.service

# Check service status
systemctl status nginx.service

# Enable service to start at boot
sudo systemctl enable nginx.service

# Disable service from starting at boot
sudo systemctl disable nginx.service

# Mask a service (completely prevent it from starting)
sudo systemctl mask nginx.service

# Unmask a service
sudo systemctl unmask nginx.service

# Check if service is active
systemctl is-active nginx.service

# Check if service is enabled at boot
systemctl is-enabled nginx.service

# Show all running services
systemctl list-units --type=service --state=running

# Show all failed services
systemctl list-units --type=service --state=failed

# List all available service units
systemctl list-unit-files --type=service

# Reboot the system
sudo systemctl reboot

# Power off the system
sudo systemctl poweroff
```

## journalctl

The command to query and display logs from the systemd journal.

```bash
journalctl [options]
```

**Options:**
- `-u unit`: Show logs for the specified unit
- `-f`: Follow new entries as they are added
- `-n [number]`: Show the last number of log entries
- `-b [ID]`: Show logs from a specific boot
- `-p priority`: Filter by priority level
- `--since="time"`: Show entries since the specified time
- `--until="time"`: Show entries until the specified time
- `-r`: Show entries in reverse order (newest first)
- `-o format`: Control the output format
- `-k`: Show kernel messages only
- `-g pattern`: Show entries matching the pattern

**Priority Levels:**
0. `emerg`: System is unusable
1. `alert`: Action must be taken immediately
2. `crit`: Critical conditions
3. `err`: Error conditions
4. `warning`: Warning conditions
5. `notice`: Normal but significant condition
6. `info`: Informational
7. `debug`: Debug-level messages

**Examples:**
```bash
# View all logs
journalctl

# View logs for a specific service
journalctl -u nginx.service

# Follow log entries in real-time
journalctl -f

# Show only the last 50 entries
journalctl -n 50

# Show logs from current boot
journalctl -b

# Show logs from previous boot
journalctl -b -1

# Show logs with priority level err and above
journalctl -p err

# Show logs since yesterday
journalctl --since="yesterday"

# Show logs between two dates/times
journalctl --since="2023-01-01 00:00:00" --until="2023-01-02 00:00:00"

# Show kernel messages only
journalctl -k

# Show logs matching a pattern
journalctl -g "error"

# Combine filters
journalctl -u nginx.service -p err --since="1 hour ago"

# Show logs in JSON format
journalctl -o json

# Show logs with timestamp precision
journalctl -o short-precise
```

## systemd-analyze

A tool to analyze system boot-up performance.

```bash
systemd-analyze [command]
```

**Commands:**
- `time`: Show time spent in different boot-up phases
- `blame`: Show time spent by each service during boot-up
- `critical-chain`: Show critical chain of boot-up
- `plot`: Create SVG graphic of boot process
- `verify`: Verify unit files

**Examples:**
```bash
# Show boot time information
systemd-analyze time

# Show service startup times
systemd-analyze blame

# Show critical chain of boot-up
systemd-analyze critical-chain

# Generate an SVG graph of the boot sequence
systemd-analyze plot > boot.svg

# Verify unit files
systemd-analyze verify unit.service
```

## Creating Systemd Service Units

Systemd service units are defined in files with the `.service` extension, typically located in the `/etc/systemd/system/` or `/usr/lib/systemd/system/` directories.

**Basic Service Unit Example:**
```ini
[Unit]
Description=My Custom Service
After=network.target

[Service]
Type=simple
User=myuser
WorkingDirectory=/opt/myapp
ExecStart=/opt/myapp/start.sh
Restart=on-failure
RestartSec=5
StandardOutput=syslog
StandardError=syslog
SyslogIdentifier=myapp

[Install]
WantedBy=multi-user.target
```

**Common [Unit] Section Options:**
- `Description`: Human-readable description
- `Documentation`: URLs to documentation
- `Requires`: Units that must be started along with this unit
- `Wants`: Units that should be started along with this unit
- `After`: Units that must be started before this unit
- `Before`: Units that should be started after this unit
- `Conflicts`: Units that cannot be run concurrently with this unit

**Common [Service] Section Options:**
- `Type`: Service start-up type (simple, forking, oneshot, notify, dbus)
- `ExecStart`: Command to run when the service starts
- `ExecStop`: Command to run when the service stops
- `ExecReload`: Command to run when the service is reloaded
- `User`: User to run the service as
- `Group`: Group to run the service as
- `WorkingDirectory`: Working directory
- `Restart`: When to restart the service (always, on-success, on-failure, on-abnormal, on-abort, on-watchdog)
- `RestartSec`: Time to wait before restarting
- `Environment`: Environment variables
- `EnvironmentFile`: File containing environment variables
- `TimeoutStartSec`: Maximum time to consider service startup successful
- `TimeoutStopSec`: Maximum time to wait for service stop before force kill

**Common [Install] Section Options:**
- `WantedBy`: Target that wants this service (typically multi-user.target)
- `RequiredBy`: Target that requires this service
- `Alias`: Additional names for the unit
- `Also`: Units to enable/disable alongside this unit

**Creating and Enabling a Custom Service:**
```bash
# Create a service file
sudo nano /etc/systemd/system/myapp.service

# Reload systemd to recognize the new service
sudo systemctl daemon-reload

# Start the service
sudo systemctl start myapp.service

# Check if it's running
systemctl status myapp.service

# Enable the service to start at boot
sudo systemctl enable myapp.service
```

## systemd Targets

Targets are groups of units that define system states, similar to runlevels in SysV init.

**Common Targets:**
- `default.target`: The default target when booting
- `poweroff.target`: System shutdown
- `rescue.target`: Single-user mode
- `multi-user.target`: Multi-user command-line mode
- `graphical.target`: Multi-user graphical mode
- `emergency.target`: Emergency shell

**Target Management Commands:**
```bash
# View default target
systemctl get-default

# Set default target
sudo systemctl set-default multi-user.target

# Switch to a different target
sudo systemctl isolate rescue.target

# List units in a target
systemctl list-dependencies multi-user.target
```

## systemd Timers

Timers are systemd units with `.timer` extensions that can be used to trigger actions at specific times, similar to cron jobs.

**Basic Timer Example:**
```ini
[Unit]
Description=Run my script daily

[Timer]
OnCalendar=*-*-* 02:00:00
Persistent=true
AccuracySec=1s

[Install]
WantedBy=timers.target
```

**Timer Management:**
```bash
# List all timers
systemctl list-timers

# Start a timer
sudo systemctl start myscript.timer

# Enable a timer
sudo systemctl enable myscript.timer
```

**Common [Timer] Section Options:**
- `OnBootSec`: Trigger after boot
- `OnUnitActiveSec`: Trigger after the unit became active
- `OnCalendar`: Trigger on calendar events
- `OnStartupSec`: Trigger after systemd startup
- `Persistent`: If true, trigger immediately if missed
- `RandomizedDelaySec`: Add a random delay
- `AccuracySec`: Accuracy of the timer

## systemd Socket Activation

Socket activation allows systemd to create listening sockets and pass them to services when needed, enabling services to be started on-demand.

**Basic Socket Example:**
```ini
[Unit]
Description=My Socket

[Socket]
ListenStream=8080
Accept=yes

[Install]
WantedBy=sockets.target
```

**Socket Management:**
```bash
# List all sockets
systemctl list-sockets

# Start a socket
sudo systemctl start myapp.socket

# Enable a socket
sudo systemctl enable myapp.socket
```

## systemd-nspawn

A tool for creating and managing lightweight containers.

```bash
systemd-nspawn [options] [command]
```

**Examples:**
```bash
# Boot a container from a directory
sudo systemd-nspawn -D /path/to/container --boot

# Run a command in a container
sudo systemd-nspawn -D /path/to/container ls -l

# Create a new container
sudo debootstrap --arch=amd64 bullseye /var/lib/container/debian
sudo systemd-nspawn -D /var/lib/container/debian --boot
```

## systemd Resource Control

Systemd supports resource control through cgroups, allowing limiting resources for services.

**Resource Control Settings in Unit Files:**
```ini
[Service]
CPUShares=1024
MemoryLimit=1G
BlockIOWeight=500
```

**Setting Resource Limits via Command Line:**
```bash
# Set memory limit for a service
sudo systemctl set-property myapp.service MemoryLimit=1G

# Set CPU shares for a service
sudo systemctl set-property myapp.service CPUShares=1000
```

## systemd Environment Variables

Setting and managing environment variables for systemd services.

**Setting Environment Variables in Unit Files:**
```ini
[Service]
Environment="VAR1=value1" "VAR2=value2"
EnvironmentFile=/etc/myapp/env
```

**Setting Environment Variables via Command Line:**
```bash
# Set environment variable for a service
sudo systemctl set-environment VAR=value

# Show environment variables
systemctl show-environment
```
