# Package Management

These commands help you install, update, and manage software packages on your Linux system. Different Linux distributions use different package management systems.

## APT (Debian, Ubuntu)

The Advanced Package Tool (APT) is a package management system used by Debian-based distributions.

### apt / apt-get

Manages packages: installs, removes, and updates packages.

```bash
apt [options] command
apt-get [options] command
```

**Common commands:**
- `update`: Update package list
- `upgrade`: Upgrade installed packages
- `install`: Install packages
- `remove`: Remove packages
- `autoremove`: Remove automatically installed packages no longer needed
- `purge`: Remove packages and configuration files
- `search`: Search for packages
- `show`: Show package details
- `list`: List packages

**Options:**
- `-y`: Automatic yes to prompts
- `--no-install-recommends`: Do not install recommended packages
- `-s`: Simulate actions
- `-f`: Fix broken dependencies

**Examples:**
```bash
# Update package list
sudo apt update

# Upgrade all packages
sudo apt upgrade

# Full system upgrade (may add or remove packages)
sudo apt full-upgrade

# Install a package
sudo apt install package-name

# Install multiple packages
sudo dnf install package1 package2 package3

# Remove a package
sudo dnf remove package-name

# Remove unused dependencies
sudo dnf autoremove

# Search for a package
dnf search keyword

# Show information about a package
dnf info package-name

# List installed packages
dnf list installed

# List available packages
dnf list available

# Clean all caches
sudo dnf clean all

# List package groups
dnf group list

# Install a package group
sudo dnf group install "Development Tools"
```

### rpm

Low-level package manager for RPM-based systems.

```bash
rpm [options] action
```

**Actions:**
- `-i`: Install package
- `-U`: Upgrade package
- `-e`: Erase (remove) package
- `-q`: Query package
- `-V`: Verify package
- `-F`: Freshen package (upgrade only if installed)

**Options:**
- `--force`: Force operation
- `--nodeps`: Do not check dependencies
- `-v`: Verbose
- `-h`: Print hash marks during installation

**Examples:**
```bash
# Install an RPM package
sudo rpm -ivh package.rpm

# Upgrade an RPM package
sudo rpm -Uvh package.rpm

# Remove a package
sudo rpm -e package-name

# Query if a package is installed
rpm -q package-name

# List all installed packages
rpm -qa

# Find which package owns a file
rpm -qf /path/to/file

# List files in a package
rpm -ql package-name

# Verify a package
rpm -V package-name
```

## Pacman (Arch Linux)

Package manager for Arch Linux and its derivatives.

```bash
pacman [options] action
```

**Actions:**
- `-S`: Synchronize packages (install/update)
- `-R`: Remove packages
- `-Q`: Query the package database
- `-T`: Check dependencies
- `-U`: Upgrade or add a local package
- `-F`: Query the files database

**Options:**
- `-y`: Refresh package database
- `-u`: Upgrade installed packages
- `-s`: Search for packages
- `-i`: View package information
- `-c`: Remove old packages from cache
- `-n`: Don't check dependencies
- `-d`: Skip dependency version checks

**Examples:**
```bash
# Update package database
sudo pacman -Sy

# Update all packages
sudo pacman -Syu

# Install a package
sudo pacman -S package-name

# Install multiple packages
sudo pacman -S package1 package2 package3

# Remove a package
sudo pacman -R package-name

# Remove a package and its dependencies
sudo pacman -Rs package-name

# Search for packages
pacman -Ss keyword

# Show information about a package
pacman -Si package-name

# List installed packages
pacman -Q

# List explicitly installed packages
pacman -Qe

# Clear package cache
sudo pacman -Sc

# Find which package owns a file
pacman -Qo /path/to/file

# List files owned by a package
pacman -Ql package-name
```

## Snap

Universal package system designed to work across many Linux distributions.

```bash
snap [options] command
```

**Common commands:**
- `install`: Install a snap
- `remove`: Remove a snap
- `list`: List installed snaps
- `find`: Find snaps in the store
- `refresh`: Update installed snaps
- `info`: Show detailed information

**Examples:**
```bash
# Install a snap
sudo snap install package-name

# Install a snap from a specific channel
sudo snap install package-name --channel=edge

# Remove a snap
sudo snap remove package-name

# List installed snaps
snap list

# Search for snaps
snap find keyword

# Show detailed information about a snap
snap info package-name

# Update all snaps
sudo snap refresh

# Update a specific snap
sudo snap refresh package-name
```

## Flatpak

Another universal package system for distributing desktop applications.

```bash
flatpak [options] command
```

**Common commands:**
- `install`: Install an application
- `uninstall`: Remove an application
- `list`: List installed applications
- `search`: Search for applications
- `update`: Update installed applications
- `info`: Show information about an application

**Examples:**
```bash
# Add Flathub repository
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

# Install an application
flatpak install flathub org.application.Name

# Remove an application
flatpak uninstall org.application.Name

# List installed applications
flatpak list

# Search for applications
flatpak search keyword

# Update all applications
flatpak update

# Show information about an application
flatpak info org.application.Name
``` packages
sudo apt install package1 package2 package3

# Install without recommended packages
sudo apt install --no-install-recommends package-name

# Remove a package
sudo apt remove package-name

# Remove a package and its configuration files
sudo apt purge package-name

# Remove unused dependencies
sudo apt autoremove

# Search for packages
apt search keyword

# Show information about a package
apt show package-name

# List installed packages
apt list --installed

# List upgradable packages
apt list --upgradable
```

### apt-cache

Query the APT package cache.

```bash
apt-cache [options] command
```

**Commands:**
- `search`: Search for packages
- `show`: Show package records
- `policy`: Show policy settings
- `depends`: Show dependencies
- `rdepends`: Show reverse dependencies

**Examples:**
```bash
# Search for packages
apt-cache search keyword

# Show package information
apt-cache show package-name

# Show package dependencies
apt-cache depends package-name

# Show what depends on a package
apt-cache rdepends package-name

# Show package policy
apt-cache policy package-name
```

### dpkg

Low-level package manager for Debian-based systems.

```bash
dpkg [options] action
```

**Actions:**
- `-i`: Install package
- `-r`: Remove package
- `-P`: Purge package
- `-l`: List packages
- `-s`: Report package status
- `-S`: Search for packages containing file
- `-L`: List files in installed package

**Examples:**
```bash
# Install a .deb package
sudo dpkg -i package.deb

# Remove an installed package
sudo dpkg -r package-name

# List all installed packages
dpkg -l

# List all installed packages with a pattern
dpkg -l 'python*'

# Show status of a package
dpkg -s package-name

# Find which package owns a file
dpkg -S /path/to/file

# List files installed by a package
dpkg -L package-name
```

## YUM/DNF (Fedora, RHEL, CentOS)

DNF (Dandified YUM) is the next-generation version of YUM, used in newer versions of Fedora, RHEL, and CentOS.

### dnf / yum

Manages packages on RPM-based systems.

```bash
dnf [options] command
yum [options] command
```

**Common commands:**
- `install`: Install packages
- `update`: Update packages
- `remove`: Remove packages
- `search`: Search for packages
- `info`: Display package information
- `list`: List packages
- `clean`: Clean cache
- `autoremove`: Remove unused dependencies

**Options:**
- `-y`: Automatic yes to prompts
- `--nobest`: Don't try to install best candidates
- `--enablerepo=repo`: Enable disabled repository
- `--disablerepo=repo`: Disable enabled repository

**Examples:**
```bash
# Update package database
sudo dnf check-update

# Update all packages
sudo dnf update

# Install a package
sudo dnf install package-name

# Install multiple
