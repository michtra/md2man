# File Management

These commands help you create, modify, move, and delete files and directories on your Linux system.

## cat

Concatenates and displays file contents.

```bash
cat [options] [file(s)]
```

**Options:**
- `-n`: Number all output lines
- `-A`: Show all non-printing characters
- `-b`: Number non-blank output lines
- `-s`: Suppress repeated empty output lines

**Examples:**
```bash
# Display file contents
cat file.txt

# Display file with line numbers
cat -n file.txt

# Concatenate multiple files
cat file1.txt file2.txt > combined.txt
```

## touch

Creates a new empty file or updates the timestamp of an existing file.

```bash
touch [options] file(s)
```

**Options:**
- `-a`: Change only the access time
- `-m`: Change only the modification time
- `-c`: Do not create any files
- `-t STAMP`: Use [[CC]YY]MMDDhhmm[.ss] instead of current time

**Examples:**
```bash
# Create a new empty file
touch newfile.txt

# Update timestamp without creating if file doesn't exist
touch -c existing.txt

# Set specific timestamp
touch -t 202504101200 file.txt
```

## mkdir

Creates directories.

```bash
mkdir [options] directory(s)
```

**Options:**
- `-p`: Create parent directories as needed
- `-m MODE`: Set file mode (permissions)
- `-v`: Print a message for each created directory

**Examples:**
```bash
# Create a directory
mkdir data

# Create nested directories
mkdir -p projects/web/css

# Create directory with specific permissions
mkdir -m 755 scripts
```

## cp

Copies files and directories.

```bash
cp [options] source destination
```

**Options:**
- `-r`: Copy directories recursively
- `-i`: Prompt before overwrite
- `-u`: Copy only when the source file is newer
- `-v`: Verbose mode
- `-p`: Preserve file attributes (mode, ownership, timestamps)
- `-a`: Archive mode (same as -dR --preserve=all)

**Examples:**
```bash
# Copy a file
cp file.txt backup/

# Copy a directory and its contents
cp -r directory/ backup/

# Copy with confirmation before overwriting
cp -i important.txt backup/

# Copy preserving attributes
cp -p config.txt /etc/
```

## mv

Moves or renames files and directories.

```bash
mv [options] source destination
```

**Options:**
- `-i`: Prompt before overwrite
- `-u`: Move only when the source file is newer
- `-v`: Verbose mode
- `-f`: Force move by overwriting destination without prompt

**Examples:**
```bash
# Rename a file
mv oldname.txt newname.txt

# Move a file to another directory
mv file.txt /home/user/documents/

# Move with confirmation before overwriting
mv -i important.txt /backup/
```

## rm

Removes files or directories.

```bash
rm [options] file(s)
```

**Options:**
- `-r`: Remove directories and their contents recursively
- `-i`: Prompt before removal
- `-f`: Force removal without prompting
- `-v`: Verbose mode

**Examples:**
```bash
# Remove a file
rm file.txt

# Remove a directory and its contents
rm -r directory/

# Remove with confirmation
rm -i important.txt

# Force remove without warning
rm -f unwanted.txt
```

## rmdir

Removes empty directories.

```bash
rmdir [options] directory(s)
```

**Options:**
- `-p`: Remove directory and its empty ancestors
- `-v`: Verbose mode

**Examples:**
```bash
# Remove an empty directory
rmdir emptydir/

# Remove nested empty directories
rmdir -p parent/child/grandchild/
```

## ln

Creates links between files.

```bash
ln [options] target link_name
```

**Options:**
- `-s`: Create a symbolic link instead of a hard link
- `-f`: Force remove existing destination files
- `-i`: Prompt whether to remove existing destination files

**Examples:**
```bash
# Create a hard link
ln target.txt link.txt

# Create a symbolic link
ln -s /path/to/target symlink

# Create a symbolic link to a directory
ln -s /var/www/html webroot
```

## chmod

Changes file permissions.

```bash
chmod [options] mode file(s)
```

**Modes:**
- Octal: `chmod 755 file.txt`
- Symbolic: `chmod u+x file.txt`

**Common permissions:**
- `400`: Read by owner
- `600`: Read and write by owner
- `644`: Read by owner, read by group, read by others
- `700`: Read, write, execute by owner
- `755`: Read, write, execute by owner; read, execute by group and others
- `777`: Read, write, execute by everyone

**Examples:**
```bash
# Make a file executable by owner
chmod u+x script.sh

# Set read/write permissions for owner, read for others
chmod 644 file.txt

# Apply permissions recursively to a directory
chmod -R 755 directory/
```

## chown

Changes file owner and group.

```bash
chown [options] owner[:group] file(s)
```

**Options:**
- `-R`: Operate on files and directories recursively
- `-c`: Like verbose but report only when a change is made
- `-f`: Suppress most error messages

**Examples:**
```bash
# Change owner of a file
sudo chown user1 file.txt

# Change owner and group
sudo chown user1:group1 file.txt

# Change ownership recursively
sudo chown -R www-data:www-data /var/www/
```

## diff

Compares files line by line.

```bash
diff [options] file1 file2
```

**Options:**
- `-y`: Side-by-side comparison
- `-i`: Ignore case differences
- `-b`: Ignore whitespace differences
- `-u`: Unified format output
- `-r`: Recursively compare directories

**Examples:**
```bash
# Compare two files
diff file1.txt file2.txt

# Side-by-side comparison
diff -y file1.txt file2.txt

# Unified format (for patches)
diff -u original.txt modified.txt > changes.patch
```

## file

Determines file type.

```bash
file [options] file(s)
```

**Options:**
- `-i`: Output MIME type strings
- `-b`: Brief mode (no filename)
- `-z`: Look inside compressed files

**Examples:**
```bash
# Check file type
file document.pdf

# Show MIME type
file -i image.jpg
```

## du

Estimates file space usage.

```bash
du [options] [file(s)]
```

**Options:**
- `-h`: Human-readable output
- `-s`: Display only a total for each argument
- `-a`: Show sizes for all files, not just directories
- `-c`: Produce a grand total

**Examples:**
```bash
# Show directory sizes in human-readable format
du -h /home/user

# Show total size of a directory
du -sh /var/log

# Show sizes of all files and directories
du -ah /etc
```

## gzip/gunzip

Compresses or decompresses files.

```bash
gzip [options] file(s)
gunzip [options] file(s).gz
```

**Options (gzip):**
- `-d`: Decompress
- `-k`: Keep original file
- `-1..9`: Compression level (1=fast, 9=best)
- `-v`: Verbose mode

**Examples:**
```bash
# Compress a file
gzip large_file.txt

# Compress with maximum compression
gzip -9 large_file.txt

# Compress while keeping the original
gzip -k large_file.txt

# Decompress a file
gunzip file.txt.gz
```

## tar

Archives files.

```bash
tar [options] [archive-file] [file(s)]
```

**Options:**
- `-c`: Create archive
- `-x`: Extract archive
- `-f`: Use archive file
- `-v`: Verbose output
- `-z`: Filter archive through gzip
- `-j`: Filter archive through bzip2
- `-t`: List contents of archive

**Examples:**
```bash
# Create a tar archive
tar -cf archive.tar file1 file2

# Create a compressed tar archive (tarball)
tar -czf archive.tar.gz directory/

# Extract a tar archive
tar -xf archive.tar

# Extract a compressed tar archive
tar -xzf archive.tar.gz

# List contents of an archive
tar -tf archive.tar
```

## zip/unzip

Creates or extracts ZIP archives.

```bash
zip [options] zipfile file(s)
unzip [options] zipfile
```

**Options (zip):**
- `-r`: Recursively include directories
- `-u`: Update existing entries
- `-q`: Quiet mode
- `-9`: Maximum compression

**Options (unzip):**
- `-l`: List archive contents without extracting
- `-o`: Overwrite files without prompting
- `-d dir`: Extract files into directory

**Examples:**
```bash
# Create a zip archive
zip archive.zip file1 file2

# Create a zip archive with a directory
zip -r archive.zip directory/

# Extract a zip archive
unzip archive.zip

# List contents of a zip archive
unzip -l archive.zip
```

## fzf

A command-line fuzzy finder for files, commands, and more.

```bash
fzf [options]
```

**Options:**
- `--preview 'command'`: Display preview window
- `-m`: Enable multi-selection
- `--height=40%`: Specify height of the fzf window

**Examples:**
```bash
# Find a file interactively
vim $(fzf)

# Search with preview
fzf --preview 'cat {}'

# Use with history search
history | fzf
```

## sha256sum

Compute and check SHA256 message digest.

```bash
sha256sum [options] [file(s)]
```

**Options:**
- `-c`: Read SHA256 sums from the FILEs and check them
- `-b`: Read in binary mode

**Examples:**
```bash
# Generate checksum for a file
sha256sum file.iso > file.iso.sha256

# Verify checksum
sha256sum -c file.iso.sha256
```
