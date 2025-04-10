# Network Management

These commands help you manage network connections, troubleshoot network issues, and transfer data over the network.

## ip

A powerful tool for showing and manipulating routing, devices, policy routing and tunnels. Replaces the older `ifconfig` command.

```bash
ip [options] object command
```

**Objects:**
- `addr`: Protocol (IP or IPv6) address on a device
- `link`: Network device
- `route`: Routing table entry
- `neigh`: ARP or NDISC cache entry

**Common commands:**
- `ip addr show`: Show IP addresses
- `ip link show`: Show network interfaces
- `ip route show`: Show routing table

**Examples:**
```bash
# Show all IP addresses
ip addr show

# Show information for a specific interface
ip addr show dev eth0

# Add an IP address to an interface
sudo ip addr add 192.168.1.10/24 dev eth0

# Delete an IP address from an interface
sudo ip addr del 192.168.1.10/24 dev eth0

# Bring an interface up/down
sudo ip link set eth0 up
sudo ip link set eth0 down

# Show routing table
ip route show

# Add a static route
sudo ip route add 192.168.2.0/24 via 192.168.1.1

# Delete a route
sudo ip route del 192.168.2.0/24
```

## ping

Sends ICMP ECHO_REQUEST packets to network hosts to check connectivity.

```bash
ping [options] destination
```

**Options:**
- `-c count`: Stop after sending count packets
- `-i interval`: Wait interval seconds between sending each packet
- `-W timeout`: Time to wait for a response, in seconds
- `-s packetsize`: Specify the number of data bytes to be sent
- `-4`: Use IPv4 only
- `-6`: Use IPv6 only

**Examples:**
```bash
# Simple ping
ping google.com

# Send 5 packets only
ping -c 5 8.8.8.8

# Send packets with 1 second interval
ping -i 1 example.com

# Use larger packet size (default is 56 bytes)
ping -s 1000 192.168.1.1
```

## traceroute

Prints the route packets take to a network host.

```bash
traceroute [options] destination
```

**Options:**
- `-n`: Do not resolve IP addresses to hostnames
- `-w timeout`: Wait timeout seconds for a response
- `-T`: Use TCP SYN for probes
- `-U`: Use UDP for probes (default)
- `-I`: Use ICMP ECHO for probes
- `-m max_hops`: Set maximum hop count (default is 30)

**Examples:**
```bash
# Trace route to a host
traceroute google.com

# Trace route with IP addresses only (no DNS lookup)
traceroute -n example.com

# Trace route using ICMP
traceroute -I 8.8.8.8

# Limit to 15 hops maximum
traceroute -m 15 github.com
```

## netstat

Displays network connections, routing tables, interface statistics, masquerade connections, and multicast memberships.

```bash
netstat [options]
```

**Options:**
- `-t`: Display TCP connections
- `-u`: Display UDP connections
- `-l`: Display listening sockets
- `-p`: Show the PID and name of the program
- `-n`: Don't resolve names
- `-r`: Display routing table
- `-i`: Display interface table
- `-s`: Display statistics by protocol

**Examples:**
```bash
# Show all active connections
netstat -a

# Show listening TCP ports
netstat -tln

# Show listening TCP ports with process information
sudo netstat -tlnp

# Show routing table
netstat -r

# Show network interface statistics
netstat -i

# Show statistics for all protocols
netstat -s
```

## ss

Another utility to investigate sockets, which is faster and provides more information than netstat.

```bash
ss [options] [filter]
```

**Options:**
- `-t`: Display TCP sockets
- `-u`: Display UDP sockets
- `-l`: Display listening sockets
- `-p`: Show process using socket
- `-n`: Do not resolve names
- `-s`: Print summary statistics
- `-4`: Display IPv4 sockets only
- `-6`: Display IPv6 sockets only

**Examples:**
```bash
# Show all listening TCP ports
ss -tl

# Show all established connections
ss -ta

# Show all listening TCP ports with process information
sudo ss -tlp

# Show only IPv4 connections
ss -4

# Show TCP connections to a specific port
ss -t dst :80

# Show statistics
ss -s
```

## dig

DNS lookup utility.

```bash
dig [options] name [type]
```

**Options:**
- `+short`: Display a terse answer
- `+noall +answer`: Show only the answer section
- `+trace`: Trace from the root nameservers
- `-t type`: Specify query type (A, MX, NS, etc.)
- `@server`: Query alternate name server

**Examples:**
```bash
# Lookup A record
dig example.com

# Lookup specific record type
dig example.com MX

# Get short answer
dig +short example.com

# Query specific DNS server
dig @8.8.8.8 example.com

# Trace resolution process
dig +trace example.com

# Reverse DNS lookup
dig -x 8.8.8.8
```

## nslookup

Query internet name servers interactively.

```bash
nslookup [options] [name] [server]
```

**Examples:**
```bash
# Simple lookup
nslookup example.com

# Query specific DNS server
nslookup example.com 8.8.8.8

# Interactive mode
nslookup
> set type=MX
> example.com
```

## host

DNS lookup utility (simpler than dig).

```bash
host [options] name [server]
```

**Options:**
- `-t type`: Specify query type (A, MX, NS, etc.)
- `-a`: Equivalent to -v -t ANY
- `-v`: Verbose output

**Examples:**
```bash
# Simple lookup
host example.com

# Lookup specific record type
host -t MX example.com

# Query specific DNS server
host example.com 8.8.8.8

# Verbose mode
host -v example.com
```

## ifconfig

Legacy command to configure network interfaces (use `ip` instead on modern systems).

```bash
ifconfig [interface] [options]
```

**Examples:**
```bash
# Show all interfaces
ifconfig

# Show specific interface
ifconfig eth0

# Assign IP address to interface
sudo ifconfig eth0 192.168.1.10 netmask 255.255.255.0

# Bring interface up/down
sudo ifconfig eth0 up
sudo ifconfig eth0 down
```

## route

Legacy command to show or manipulate the IP routing table (use `ip route` instead on modern systems).

```bash
route [options]
```

**Examples:**
```bash
# Show routing table
route -n

# Add default gateway
sudo route add default gw 192.168.1.1

# Add static route
sudo route add -net 192.168.2.0 netmask 255.255.255.0 gw 192.168.1.1
```

## curl

Transfers data to or from a server using various protocols.

```bash
curl [options] [URL]
```

**Options:**
- `-o file`: Write output to file
- `-O`: Write output to a file named like the remote file
- `-L`: Follow redirects
- `-i`: Include response headers in the output
- `-I`: Fetch headers only
- `-X method`: Specify request method (GET, POST, etc.)
- `-d data`: Send data in POST request
- `-H header`: Add header to request
- `-u user:pass`: Server user and password
- `-k`: Allow insecure connections
- `-v`: Verbose output

**Examples:**
```bash
# Fetch a webpage
curl https://example.com

# Save output to a file
curl -o output.html https://example.com

# Follow redirects
curl -L https://example.com

# Show response headers
curl -i https://example.com

# Fetch headers only
curl -I https://example.com

# POST request with data
curl -X POST -d "name=John&age=30" https://example.com/api

# Add custom headers
curl -H "Content-Type: application/json" https://example.com

# Authenticate
curl -u username:password https://example.com

# Verbose mode
curl -v https://example.com
```

## wget

Non-interactive network downloader.

```bash
wget [options] [URL]
```

**Options:**
- `-O file`: Write documents to file
- `-b`: Go to background after startup
- `-q`: Quiet mode
- `-c`: Resume broken download
- `-r`: Recursive download
- `-np`: Don't ascend to parent directory
- `-p`: Download all files needed to display HTML page
- `--limit-rate=rate`: Limit download rate
- `-U agent`: Identify as agent-string to the HTTP server
- `-P prefix`: Save files to prefix/..

**Examples:**
```bash
# Download a file
wget https://example.com/file.zip

# Save file with different name
wget -O custom-name.zip https://example.com/file.zip

# Continue interrupted download
wget -c https://example.com/large-file.iso

# Download recursively
wget -r -np https://example.com/docs/

# Limit download speed
wget --limit-rate=200k https://example.com/large-file.iso

# Download in background
wget -b https://example.com/large-file.iso
```

## ssh

OpenSSH client for secure remote login.

```bash
ssh [options] [user@]hostname [command]
```

**Options:**
- `-p port`: Connect to port on remote host
- `-i identity_file`: Identity file for public key authentication
- `-X`: Enable X11 forwarding
- `-L local:remote`: Forward local port to remote address
- `-R remote:local`: Forward remote port to local address
- `-V`: Display version number
- `-v`: Verbose mode

**Examples:**
```bash
# Connect to remote host
ssh user@example.com

# Connect to a specific port
ssh -p 2222 user@example.com

# Use specific identity file
ssh -i ~/.ssh/id_rsa user@example.com

# Forward local port to remote
ssh -L 8080:localhost:80 user@example.com

# Forward remote port to local
ssh -R 8080:localhost:80 user@example.com

# Execute command on remote host
ssh user@example.com 'ls -la'
```

## scp

Securely copy files between hosts on a network.

```bash
scp [options] [[user@]host1:]file1 ... [[user@]host2:]file2
```

**Options:**
- `-P port`: Connect to port on remote host
- `-r`: Recursively copy entire directories
- `-p`: Preserve modification times, access times, and modes
- `-q`: Quiet mode
- `-C`: Enable compression
- `-i identity_file`: Identity file for public key authentication

**Examples:**
```bash
# Copy local file to remote host
scp file.txt user@example.com:/path/to/destination/

# Copy remote file to local system
scp user@example.com:/path/to/file.txt local-file.txt

# Copy entire directory recursively
scp -r local-directory/ user@example.com:/path/to/destination/

# Use specific port
scp -P 2222 file.txt user@example.com:/path/to/destination/

# Copy with compression
scp -C large-file.zip user@example.com:/path/to/destination/
```

## rsync

Fast, versatile file copying tool for efficient transfers.

```bash
rsync [options] source destination
```

**Options:**
- `-a`: Archive mode (recursive, preserves permissions, etc.)
- `-v`: Verbose output
- `-z`: Compress file data during transfer
- `-h`: Human-readable output
- `-P`: Show progress and keep partially transferred files
- `--delete`: Delete extraneous files from destination
- `--exclude=pattern`: Exclude files matching pattern
- `-n`: Dry-run (show what would be done)

**Examples:**
```bash
# Sync local directory to another local directory
rsync -avh /source/directory/ /destination/directory/

# Sync from local to remote
rsync -avz /local/directory/ user@example.com:/remote/directory/

# Sync from remote to local
rsync -avz user@example.com:/remote/directory/ /local/directory/

# Sync with deletion (mirror)
rsync -avh --delete /source/ /destination/

# Exclude certain files
rsync -avh --exclude='*.tmp' /source/ /destination/

# Dry run to see what would happen
rsync -avhn /source/ /destination/
```

## nc (netcat)

Utility for reading from and writing to network connections.

```bash
nc [options] host port
```

**Options:**
- `-l`: Listen mode
- `-p port`: Local port
- `-u`: Use UDP instead of TCP
- `-v`: Verbose output
- `-z`: Zero-I/O mode (scan ports)
- `-w timeout`: Timeout for connects

**Examples:**
```bash
# Connect to a server
nc example.com 80

# Create a simple server
nc -l 8080

# Port scanning
nc -zv example.com 20-30

# Transfer file (receiver)
nc -l 1234 > received_file.txt

# Transfer file (sender)
nc example.com 1234 < file_to_send.txt

# Chat server (listener)
nc -l 1234

# Chat client
nc example.com 1234
```

## nmcli

Command-line tool for controlling NetworkManager.

```bash
nmcli [options] object command
```

**Objects:**
- `general`: NetworkManager status and permissions
- `networking`: Overall networking control
- `radio`: NetworkManager radio switches
- `connection`: NetworkManager's connections
- `device`: Devices managed by NetworkManager
- `agent`: NetworkManager secret agent or polkit agent

**Examples:**
```bash
# Show overall status
nmcli general status

# Show all connections
nmcli connection show

# Show active connections
nmcli connection show --active

# Connect to a WiFi network
nmcli device wifi connect SSID-Name password wireless-password

# Show available WiFi networks
nmcli device wifi list

# Turn WiFi on/off
nmcli radio wifi on
nmcli radio wifi off

# Show detailed information about a specific connection
nmcli connection show "connection-name"

# Create a new connection
nmcli connection add type ethernet ifname eth0 con-name "My Connection"
```

## nmap

Network exploration tool and security/port scanner.

```bash
nmap [options] target
```

**Options:**
- `-sS`: TCP SYN scan (default)
- `-sU`: UDP scan
- `-p ports`: Scan specified ports
- `-A`: Enable OS detection, version detection, script scanning, and traceroute
- `-T0-5`: Set timing template (higher is faster)
- `-v`: Increase verbosity level
- `-oN file`: Output in normal format to file

**Examples:**
```bash
# Simple scan of a host
nmap example.com

# Scan specific ports
nmap -p 80,443 example.com

# Scan a range of ports
nmap -p 1-100 example.com

# Scan all ports
nmap -p- example.com

# Aggressive scan
nmap -A example.com

# Scan network range
nmap 192.168.1.0/24

# UDP scan
nmap -sU example.com

# Save output to file
nmap -oN scan-results.txt example.com
```

## iptables

Administration tool for IPv4 packet filtering and NAT.

```bash
iptables [options] command chain rule-specification
```

**Commands:**
- `-A`: Append to chain
- `-D`: Delete matching rule
- `-I`: Insert in chain
- `-L`: List the rules in a chain
- `-F`: Flush (delete all rules)
- `-P`: Set the policy for a chain

**Common chains:**
- `INPUT`: Packets destined for local sockets
- `FORWARD`: Packets being routed through the system
- `OUTPUT`: Packets generated locally

**Examples:**
```bash
# List all rules
sudo iptables -L

# List rules with line numbers and packet counts
sudo iptables -L -v --line-numbers

# Allow incoming SSH connections
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT

# Block an IP address
sudo iptables -A INPUT -s 192.168.1.10 -j DROP

# Allow established connections
sudo iptables -A INPUT -m state --state ESTABLISHED,RELATED -j ACCEPT

# Set default policy
sudo iptables -P INPUT DROP

# Delete a rule by number
sudo iptables -D INPUT 3

# Flush all rules
sudo iptables -F

# Save rules (Debian/Ubuntu)
sudo iptables-save > /etc/iptables/rules.v4
```
