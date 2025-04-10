# Linux Security

This section covers essential security-related commands and concepts for Linux systems, helping you protect your system and manage security features.

## User and Permission Management

### chmod

Changes the permissions of files and directories. See [File Management](04-file-management.md) for details.

### chown

Changes the owner and group of files and directories. See [File Management](04-file-management.md) for details.

### sudo

Executes a command as another user, typically the superuser. See [User Management](06-user-management.md) for details.

### visudo

Edits the sudoers file safely.

```bash
visudo [options]
```

**Options:**
- `-c`: Check syntax only
- `-f file`: Use an alternate sudoers file
- `-s`: Enable strict checking

**Examples:**
```bash
# Edit the sudoers file
sudo visudo

# Check syntax of sudoers file
sudo visudo -c

# Edit a specific sudoers file
sudo visudo -f /etc/sudoers.d/custom
```

## Firewalls

### ufw (Uncomplicated Firewall)

A user-friendly interface for managing iptables firewall rules.

```bash
ufw [options] [rule]
```

**Common Commands:**
- `enable`: Enable the firewall
- `disable`: Disable the firewall
- `status`: Show firewall status
- `allow`: Allow traffic
- `deny`: Deny traffic
- `reject`: Reject traffic
- `default`: Set default policy
- `delete`: Delete a rule
- `app list`: List application profiles

**Examples:**
```bash
# Enable the firewall
sudo ufw enable

# Check firewall status
sudo ufw status verbose

# Allow SSH connections
sudo ufw allow ssh

# Allow specific port
sudo ufw allow 8080/tcp

# Allow from specific IP address
sudo ufw allow from 192.168.1.100

# Allow from subnet to specific port
sudo ufw allow from 192.168.1.0/24 to any port 22

# Deny traffic to a port
sudo ufw deny 23

# Set default policies
sudo ufw default deny incoming
sudo ufw default allow outgoing

# Delete a rule
sudo ufw delete allow 8080/tcp

# Show numbered rules
sudo ufw status numbered

# Delete rule by number
sudo ufw delete 2
```

### iptables

Low-level firewall utility for packet filtering. See [Network Management](07-network-management.md) for details.

### firewalld

A dynamically managed firewall with support for network zones.

```bash
firewall-cmd [options]
```

**Common Commands:**
- `--state`: Show firewall state
- `--reload`: Reload configuration
- `--get-default-zone`: Show default zone
- `--set-default-zone=ZONE`: Set default zone
- `--get-zones`: List available zones
- `--get-active-zones`: Show active zones
- `--list-all`: List all configuration
- `--list-all-zones`: List configuration for all zones
- `--permanent`: Make settings permanent
- `--add-service`: Allow service
- `--remove-service`: Remove service
- `--add-port`: Allow port
- `--remove-port`: Remove port

**Examples:**
```bash
# Check firewall state
sudo firewall-cmd --state

# List all settings in the default zone
sudo firewall-cmd --list-all

# Allow a service
sudo firewall-cmd --add-service=http --permanent

# Allow a port
sudo firewall-cmd --add-port=8080/tcp --permanent

# Reload configuration
sudo firewall-cmd --reload

# Set default zone
sudo firewall-cmd --set-default-zone=home

# Show active zones
sudo firewall-cmd --get-active-zones

# List all settings in a specific zone
sudo firewall-cmd --zone=public --list-all
```

## Encryption and Security Tools

### openssl

A toolkit for the Transport Layer Security (TLS) and Secure Sockets Layer (SSL) protocols.

```bash
openssl [command] [options]
```

**Common Commands:**
- `genrsa`: Generate RSA private key
- `rsa`: Process RSA keys
- `req`: PKCS#10 certificate request and certificate generating utility
- `x509`: Certificate display and signing utility
- `enc`: Encryption, decryption, and encoding
- `dgst`: Message digest calculation

**Examples:**
```bash
# Generate a private key
openssl genrsa -out private.key 2048

# Create a certificate signing request
openssl req -new -key private.key -out request.csr

# Self-sign a certificate
openssl req -new -x509 -key private.key -out certificate.crt -days 365

# View certificate information
openssl x509 -in certificate.crt -text -noout

# Encrypt a file
openssl enc -aes-256-cbc -salt -in file.txt -out file.enc

# Decrypt a file
openssl enc -d -aes-256-cbc -in file.enc -out file.txt

# Generate a random password
openssl rand -base64 12

# Calculate file hash
openssl dgst -sha256 file.txt

# Test TLS/SSL connection
openssl s_client -connect example.com:443
```

### ssh-keygen

Generates, manages, and converts authentication keys for SSH.

```bash
ssh-keygen [options]
```

**Options:**
- `-t type`: Specify key type (rsa, dsa, ecdsa, ed25519)
- `-b bits`: Specify key length in bits
- `-f file`: Specify key file
- `-C comment`: Add a comment
- `-p`: Change the passphrase of a private key file
- `-i`: Read key from STDIN
- `-R hostname`: Remove host from known_hosts file

**Examples:**
```bash
# Generate an RSA key pair
ssh-keygen -t rsa -b 4096

# Generate a key with a specific name
ssh-keygen -t ed25519 -f ~/.ssh/github_key

# Add a comment to identify the key
ssh-keygen -t rsa -C "user@example.com"

# Change key passphrase
ssh-keygen -p -f ~/.ssh/id_rsa

# Show fingerprint of a key
ssh-keygen -l -f ~/.ssh/id_rsa.pub

# Convert a key to PEM format
ssh-keygen -e -f ~/.ssh/id_rsa > id_rsa.pem
```

### ssh-copy-id

Installs an SSH key on a remote machine as an authorized key.

```bash
ssh-copy-id [options] [user@]hostname
```

**Options:**
- `-i identity_file`: Use a specific identity file
- `-f`: Force mode
- `-n`: Dry run (just print what would be done)

**Examples:**
```bash
# Copy default key to remote host
ssh-copy-id user@remote_host

# Specify identity file
ssh-copy-id -i ~/.ssh/specific_key.pub user@remote_host

# Use a non-standard port
ssh-copy-id -i ~/.ssh/id_rsa.pub "user@remote_host -p 2222"
```

### gpg

GNU Privacy Guard for encryption and signing. See [Miscellaneous Tools](14-miscellaneous-tools.md) for details.

## File Integrity and Security Scanning

### md5sum, sha1sum, sha256sum

Calculate and check message digests.

```bash
md5sum [options] [files]
sha1sum [options] [files]
sha256sum [options] [files]
```

**Options:**
- `-c, --check`: Check digests from a file
- `-b, --binary`: Read in binary mode
- `--tag`: Create a BSD-style checksum

**Examples:**
```bash
# Calculate MD5 hash
md5sum file.iso > file.md5

# Calculate SHA-256 hash
sha256sum file.iso > file.sha256

# Verify checksum
sha256sum -c file.sha256

# Calculate hash for multiple files
sha1sum file1.txt file2.txt > checksums.sha1
```

### chkrootkit

Checks for signs of rootkits on the system.

```bash
chkrootkit [options]
```

**Options:**
- `-r dir`: Specify alternative root directory
- `-x`: Expert mode
- `-q`: Quiet mode

**Examples:**
```bash
# Run a basic check
sudo chkrootkit

# Run in expert mode
sudo chkrootkit -x

# Check specific tests
sudo chkrootkit chkutmp chklastlog
```

### rkhunter (Rootkit Hunter)

Scans for rootkits, backdoors, and local exploits.

```bash
rkhunter [options]
```

**Options:**
- `--check`: Perform system check
- `--update`: Update rkhunter database
- `--propupd`: Update file properties database
- `--list`: List available tests
- `--skip`: Skip specific tests
- `--quiet`: Quiet mode

**Examples:**
```bash
# Run a standard check
sudo rkhunter --check

# Update the database
sudo rkhunter --update

# Update file properties database
sudo rkhunter --propupd

# Run in verbose mode
sudo rkhunter --check --verbose

# Skip specific tests
sudo rkhunter --check --skip netstat,properties
```

### ClamAV

An open-source antivirus engine.

**Common Commands:**
- `clamscan`: Scan files and directories
- `freshclam`: Update virus database
- `clamdscan`: Scan using the clamd daemon

**Examples:**
```bash
# Update virus definitions
sudo freshclam

# Scan a directory
clamscan -r /home/user

# Scan and remove infected files
clamscan -r --remove /home/user

# Scan and show only infected files
clamscan -r -i /home/user

# Scan using the daemon (faster for multiple scans)
clamdscan -r /home/user
```

## Auditing and Logging

### auditd

The Linux Audit daemon for monitoring system calls and file access.

**Commands:**
- `auditctl`: Control the audit system
- `ausearch`: Search audit logs
- `aureport`: Generate audit reports
- `autrace`: Trace processes with the audit system

**Examples:**
```bash
# Check audit status
sudo auditctl -s

# Set a file watch
sudo auditctl -w /etc/passwd -p rwxa -k password-file

# List all rules
sudo auditctl -l

# Delete all rules
sudo auditctl -D

# Search for events by user
sudo ausearch -ua root

# Search for events by key
sudo ausearch -k password-file

# Generate a summary report
sudo aureport

# Generate a user report
sudo aureport -u

# Trace a command with audit
sudo autrace /bin/ls
```

### fail2ban

Scans log files and bans IPs that show malicious activity.

```bash
fail2ban-client [options] [command]
```

**Common Commands:**
- `start`: Start fail2ban
- `stop`: Stop fail2ban
- `status`: Show status
- `reload`: Reload configuration
- `set`: Set options
- `get`: Get options
- `add`: Add options
- `unban`: Unban IP address

**Examples:**
```bash
# Start fail2ban
sudo fail2ban-client start

# Check status
sudo fail2ban-client status

# Check status of a specific jail
sudo fail2ban-client status sshd

# Reload configuration
sudo fail2ban-client reload

# Unban an IP address
sudo fail2ban-client set sshd unbanip 192.168.1.100

# Get currently banned IPs for a jail
sudo fail2ban-client get sshd banned

# Manually ban an IP
sudo fail2ban-client set sshd banip 192.168.1.100
```

### logrotate

Manages log files by rotating, compressing, and mailing them.

```bash
logrotate [options] [config_file]
```

**Options:**
- `-d`: Debug mode (don't make changes)
- `-f`: Force rotation
- `-s state_file`: Use an alternate state file
- `-v`: Verbose mode

**Examples:**
```bash
# Test configuration (debug mode)
sudo logrotate -d /etc/logrotate.conf

# Force log rotation
sudo logrotate -f /etc/logrotate.conf

# Rotate a specific config
sudo logrotate -f /etc/logrotate.d/nginx

# Verbose output
sudo logrotate -v /etc/logrotate.conf
```

## Secure Communication

### ssh

OpenSSH client for secure remote login. See [Network Management](07-network-management.md) for details.

### scp

Secure copy between hosts. See [Network Management](07-network-management.md) for details.

### sftp

Secure file transfer protocol client. Similar to FTP but encrypted over SSH.

```bash
sftp [options] [user@]host[:file ...]
```

**Options:**
- `-P port`: Connect to port on remote host
- `-i identity_file`: Use identity file for public key authentication
- `-b batchfile`: Batch mode with file containing commands
- `-r`: Recursively copy entire directories

**SFTP Commands:**
- `cd path`: Change remote directory
- `lcd path`: Change local directory
- `ls`: List remote directory
- `lls`: List local directory
- `get file`: Download file
- `put file`: Upload file
- `mget files`: Download multiple files
- `mput files`: Upload multiple files
- `mkdir dir`: Create remote directory
- `rmdir dir`: Remove remote directory
- `rm file`: Delete remote file
- `pwd`: Print remote working directory
- `lpwd`: Print local working directory
- `exit`/`quit`: Exit sftp

**Examples:**
```bash
# Connect to SFTP server
sftp user@remote_host

# Connect to a specific port
sftp -P 2222 user@remote_host

# Download a file
sftp> get remote_file.txt

# Upload a file
sftp> put local_file.txt

# Download directory recursively
sftp> get -r remote_directory

# Upload directory recursively
sftp> put -r local_directory

# Batch mode
echo -e "cd /remote/dir\nget file.txt\nquit" > commands.txt
sftp -b commands.txt user@remote_host
```

## SELinux and AppArmor

### SELinux

Security-Enhanced Linux provides a flexible MAC (Mandatory Access Control) system.

**Commands:**
- `getenforce`: Display current SELinux mode
- `setenforce`: Modify current SELinux mode
- `sestatus`: SELinux status information
- `semanage`: Manage SELinux policies
- `setsebool`: Set SELinux boolean values
- `restorecon`: Restore file(s) default SELinux security contexts
- `chcon`: Change file SELinux security context

**Examples:**
```bash
# Check SELinux status
getenforce

# Set SELinux to permissive mode
sudo setenforce 0

# Set SELinux to enforcing mode
sudo setenforce 1

# View detailed status
sestatus

# List SELinux booleans
getsebool -a

# Change a boolean value
sudo setsebool httpd_can_network_connect on

# Make boolean change permanent
sudo setsebool -P httpd_can_network_connect on

# Restore default context to a file
sudo restorecon -v /var/www/html/index.html

# Recursively restore contexts
sudo restorecon -R -v /var/www/html/

# Change context of a file
sudo chcon -t httpd_sys_content_t /path/to/file
```

### AppArmor

Application Armor restricts programs' capabilities with per-program profiles.

**Commands:**
- `aa-status`: Show AppArmor status and loaded profiles
- `aa-enforce`: Set profile to enforce mode
- `aa-complain`: Set profile to complain mode
- `aa-disable`: Disable AppArmor profile
- `aa-genprof`: Generate new profile
- `aa-logprof`: Update profile based on logs
- `apparmor_parser`: Load AppArmor profiles

**Examples:**
```bash
# Check AppArmor status
sudo aa-status

# Set a profile to enforce mode
sudo aa-enforce /usr/bin/firefox

# Set a profile to complain mode
sudo aa-complain /usr/bin/firefox

# Disable a profile
sudo aa-disable /usr/bin/firefox

# Generate a profile
sudo aa-genprof /path/to/program

# Update profile based on logs
sudo aa-logprof

# Reload all profiles
sudo systemctl reload apparmor

# Load a specific profile
sudo apparmor_parser -r /etc/apparmor.d/profile
```

## Password Tools

### passwd

Changes user password. See [User Management](06-user-management.md) for details.

### pwgen

Generates random, pronounceable passwords.

```bash
pwgen [options] [length] [number]
```

**Options:**
- `-s`: Generate secure, completely random passwords
- `-y`: Include at least one special symbol
- `-n`: Include at least one number
- `-c`: Include at least one capital letter
- `-1`: One password per line
- `-B`: Don't include ambiguous characters
- `-A`: Don't include capital letters
- `-0`: Don't include numbers

**Examples:**
```bash
# Generate 10 passwords of length 12
pwgen 12 10

# Generate one secure random password
pwgen -s -1 16

# Generate password with special symbols, numbers, and capital letters
pwgen -cnys 12 1

# Generate 5 passwords without ambiguous characters
pwgen -B 10 5
```

### mkpasswd

Generates a password hash.

```bash
mkpasswd [options] [password] [salt]
```

**Options:**
- `-m, --method=METHOD`: Select encryption method
- `-S, --salt=SALT`: Use specified salt
- `-R, --rounds=ROUNDS`: Use specified rounds
- `--help`: Display help

**Examples:**
```bash
# Generate SHA-512 hashed password
mkpasswd -m sha-512 "mypassword"

# Specify salt
mkpasswd -m sha-512 -S mysalt "mypassword"

# Specify rounds for SHA-512
mkpasswd -m sha-512 -R 10000 "mypassword"
```

### pam_tally2

Tracks failed login attempts and can lock accounts.

```bash
pam_tally2 [options]
```

**Options:**
- `--user=name`: Show failures for specified user
- `--reset`: Reset failure count
- `--reset=n`: Reset count to n
- `--unlock`: Unlock account

**Examples:**
```bash
# Show failed login attempts for all users
sudo pam_tally2

# Show failed login attempts for a specific user
sudo pam_tally2 --user=username

# Reset counter for a specific user
sudo pam_tally2 --user=username --reset

# Reset counter to specific number
sudo pam_tally2 --user=username --reset=3

# Unlock a user account
sudo pam_tally2 --user=username --reset
```

## Security Scanning and Analysis

### lynis

Security auditing tool for Unix/Linux systems.

```bash
lynis [options] command
```

**Commands:**
- `audit`: Perform a security scan
- `update`: Update lynis
- `show`: Show information

**Options:**
- `--check-all`: Check all tests
- `--no-colors`: Don't use colors in output
- `--pentest`: Non-privileged pentesting mode
- `--quick`: Quick mode, fewer tests
- `--reverse-colors`: Reverse colors (for light backgrounds)

**Examples:**
```bash
# Run a full system audit
sudo lynis audit system

# Show security scan suggestions
sudo lynis show suggestions

# Run only specific test groups
sudo lynis audit system --tests-from-group malware,authentication

# Save scan results
sudo lynis audit system --auditor "Security Team" --report-file /tmp/lynis-report.dat
```

### nmap

Network exploration tool and security scanner. See [Network Management](07-network-management.md) for details.

### nikto

Web server scanner that tests for vulnerabilities.

```bash
nikto [options] -h host
```

**Options:**
- `-h host`: Host to scan
- `-p port`: Port to scan
- `-ssl`: Force SSL mode
- `-nossl`: Disable SSL
- `-output file`: Save output to file
- `-Format`: Specify output format (csv, htm, txt, xml)
- `-update`: Update plugins and databases
- `-Tuning`: Control scan detail

**Examples:**
```bash
# Basic scan
nikto -h example.com

# Scan HTTPS site
nikto -h example.com -ssl

# Scan specific port
nikto -h example.com -p 8443

# Save output to a file
nikto -h example.com -output nikto-results.txt

# Specify output format
nikto -h example.com -Format htm -output results.html

# Tuning scan (XSS and SQLi only)
nikto -h example.com -Tuning 9
```

### tcpdump

Captures and analyzes network traffic.

```bash
tcpdump [options] [expression]
```

**Options:**
- `-i interface`: Listen on specified interface
- `-c count`: Capture count packets and exit
- `-w file`: Write packets to file
- `-r file`: Read packets from file
- `-n`: Don't convert addresses to names
- `-v`: Verbose output
- `-X`: Show hex and ASCII format packet data
- `-S`: Print absolute TCP sequence numbers

**Examples:**
```bash
# Capture on specific interface
sudo tcpdump -i eth0

# Don't convert addresses to names
sudo tcpdump -n

# Capture specific protocol
sudo tcpdump tcp

# Capture traffic from/to host
sudo tcpdump host 192.168.1.100

# Capture traffic to specific port
sudo tcpdump port 80

# Capture traffic to specific port with hex output
sudo tcpdump -X port 80

# Save capture to file
sudo tcpdump -w capture.pcap

# Read from capture file
sudo tcpdump -r capture.pcap

# Complex filter
sudo tcpdump 'tcp port 80 and (src host 192.168.1.100 or dst host 192.168.1.100)'
```

### wireshark

Graphical network protocol analyzer, similar to tcpdump.

```bash
wireshark [options] [capture filter]
```

**Options:**
- `-i interface`: Capture from specific interface
- `-k`: Start capturing immediately
- `-f filter`: Set capture filter
- `-Y filter`: Set display filter
- `-r file`: Read from capture file
- `-w file`: Write to capture file

**Examples:**
```bash
# Start Wireshark
wireshark

# Capture from specific interface
wireshark -i eth0 -k

# Capture with filter
wireshark -i eth0 -f "port 80" -k

# Open capture file
wireshark -r capture.pcap

# Capture to file without GUI
wireshark -i eth0 -w capture.pcap -k
```

### tripwire

File integrity checking tool.

```bash
tripwire [options]
```

**Common Commands:**
- `--init`: Initialize the database
- `--check`: Run an integrity check
- `--update`: Update the database after changes
- `--update-policy`: Update the policy file
- `--test`: Test a policy file

**Examples:**
```bash
# Initialize the database
sudo tripwire --init

# Run an integrity check
sudo tripwire --check

# View report
sudo twprint --print-report --twrfile /var/lib/tripwire/report/hostname-timestamp.twr

# Update database after changes
sudo tripwire --update --twrfile /var/lib/tripwire/report/hostname-timestamp.twr

# Update policy
sudo tripwire --update-policy /etc/tripwire/twpol.txt
```

## Secure Configuration

### sshd_config

The SSH server configuration file, typically located at `/etc/ssh/sshd_config`.

**Important Settings:**
```
# Disable root login
PermitRootLogin no

# Use only SSH protocol version 2
Protocol 2

# Restrict SSH to specific users
AllowUsers user1 user2

# Restrict SSH to specific groups
AllowGroups sshusers

# Change default port
Port 2222

# Disable password authentication (use keys only)
PasswordAuthentication no

# Enable public key authentication
PubkeyAuthentication yes

# Maximum authentication attempts
MaxAuthTries 3

# Idle timeout interval (seconds)
ClientAliveInterval 300
ClientAliveCountMax 2

# Disable empty passwords
PermitEmptyPasswords no

# Disable X11 forwarding
X11Forwarding no

# Enable strict mode checking
StrictModes yes
```

After changing the configuration, restart the SSH service:
```bash
sudo systemctl restart sshd
```

### Kernel Security Parameters

Security-related kernel parameters can be set in `/etc/sysctl.conf` or in files under `/etc/sysctl.d/`.

**Important Security Parameters:**
```
# Disable IP forwarding
net.ipv4.ip_forward = 0

# Disable sending ICMP redirects
net.ipv4.conf.all.send_redirects = 0
net.ipv4.conf.default.send_redirects = 0

# Protect against SYN flood attacks
net.ipv4.tcp_syncookies = 1

# Ignore ICMP broadcasts
net.ipv4.icmp_echo_ignore_broadcasts = 1

# Ignore bogus ICMP responses
net.ipv4.icmp_ignore_bogus_error_responses = 1

# Log suspicious packets
net.ipv4.conf.all.log_martians = 1
net.ipv4.conf.default.log_martians = 1

# Do not accept source routed packets
net.ipv4.conf.all.accept_source_route = 0
net.ipv4.conf.default.accept_source_route = 0

# Protect against IP spoofing
net.ipv4.conf.all.rp_filter = 1
net.ipv4.conf.default.rp_filter = 1

# Disable IPv6 if not needed
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.default.disable_ipv6 = 1
net.ipv6.conf.lo.disable_ipv6 = 1

# Secure kernel memory protections
kernel.randomize_va_space = 2
kernel.kptr_restrict = 2
kernel.dmesg_restrict = 1
```

Apply changes:
```bash
sudo sysctl -p /etc/sysctl.conf
```

### umask

Sets the default file permissions for newly created files and directories.

```bash
umask [mask]
```

**Examples:**
```bash
# Show current umask
umask

# Set umask to restrict group and others write permission
umask 022

# Set umask to restrict group and others all permissions
umask 077

# Set system-wide umask in /etc/profile or /etc/login.defs
# Add or modify:
umask 022
```

### Secure Boot

UEFI Secure Boot verifies signature of bootloaders and kernel before executing them.

**Check Secure Boot Status:**
```bash
# Check if system is booted in UEFI mode
[ -d /sys/firmware/efi ] && echo "UEFI" || echo "BIOS"

# Check Secure Boot status
mokutil --sb-state
```

**Manage Secure Boot Keys:**
```bash
# Import a key
mokutil --import key.der

# Delete a key
mokutil --delete key.der

# List enrolled keys
mokutil --list-enrolled

# Disable secure boot
mokutil --disable-validation
```
