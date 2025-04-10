# Text Processing

These commands help you view, manipulate, search, and transform text files on your Linux system.

## cat

Concatenates and displays file contents.

```bash
cat [options] [file(s)]
```

**Options:**
- `-n`: Number all output lines
- `-b`: Ignore whitespace changes
- `-B`: Ignore blank lines
- `-w`: Ignore all whitespace
- `-E`: Ignore tab expansion
- `-r`: Recursively compare directories
- `-N`: Treat absent files as empty

**Examples:**
```bash
# Compare two files
diff file1.txt file2.txt

# Unified format (for patches)
diff -u file1.txt file2.txt > changes.patch

# Side-by-side comparison
diff -y file1.txt file2.txt

# Ignore whitespace changes
diff -w file1.txt file2.txt

# Compare directories
diff -r dir1/ dir2/

# Create patch file
diff -Naur original/ modified/ > changes.patch
```

## comm

Compares two sorted files line by line.

```bash
comm [options] file1 file2
```

**Options:**
- `-1`: Suppress lines unique to file1
- `-2`: Suppress lines unique to file2
- `-3`: Suppress lines common to both files

**Examples:**
```bash
# Compare two sorted files
comm sorted1.txt sorted2.txt

# Show only lines unique to first file
comm -23 sorted1.txt sorted2.txt

# Show only lines unique to second file
comm -13 sorted1.txt sorted2.txt

# Show only lines common to both files
comm -12 sorted1.txt sorted2.txt
```

## fold

Wraps each input line to fit specified width.

```bash
fold [options] [file(s)]
```

**Options:**
- `-w width`: Use width columns instead of 80
- `-s`: Break at spaces
- `-b`: Count bytes rather than columns

**Examples:**
```bash
# Wrap lines to 40 columns
fold -w 40 file.txt

# Wrap at spaces (avoid breaking words)
fold -w 40 -s file.txt
```

## fmt

Simple text formatter.

```bash
fmt [options] [file(s)]
```

**Options:**
- `-w width`: Maximum line width (default is 75)
- `-s`: Split lines only
- `-u`: Uniform spacing (one space between words, two after sentences)

**Examples:**
```bash
# Format with 60-column width
fmt -w 60 file.txt

# Format with uniform spacing
fmt -u file.txt
```

## column

Formats input into multiple columns.

```bash
column [options] [file(s)]
```

**Options:**
- `-t`: Create a table
- `-s delimiter`: Specify delimiter character
- `-n`: Don't merge multiple adjacent delimiters
- `-o delimiter`: Use delimiter as output column separator

**Examples:**
```bash
# Format in columns
ls | column

# Format delimited file as table
column -t -s, file.csv

# Format with custom output delimiter
column -t -s, -o '|' file.csv
```

## tee

Reads from standard input and writes to standard output and files.

```bash
tee [options] [file(s)]
```

**Options:**
- `-a`: Append to files
- `-i`: Ignore interrupt signals

**Examples:**
```bash
# Write output to both terminal and file
command | tee output.txt

# Append to existing file
command | tee -a output.txt

# Write to multiple files
command | tee file1.txt file2.txt

# Use in a pipeline
command1 | tee output.txt | command2
```

## xargs

Builds and executes commands from standard input.

```bash
xargs [options] [command]
```

**Options:**
- `-0`: Input items are terminated by null, not whitespace
- `-d delimiter`: Use delimiter as input item delimiter
- `-n max-args`: Use at most max-args per command line
- `-I replace-str`: Replace replace-str in command with input
- `-p`: Prompt before executing each command
- `-t`: Print commands before executing

**Examples:**
```bash
# Simple usage
find . -name "*.txt" | xargs cat

# Replace string in command
find . -name "*.txt" | xargs -I{} cp {} /backup/

# Limit arguments per command
find . -name "*.txt" | xargs -n 2 echo

# Null-terminated input (good for filenames with spaces)
find . -name "*.txt" -print0 | xargs -0 cat

# Prompt before execution
find . -name "*.txt" | xargs -p rm
```

## jq

Command-line JSON processor.

```bash
jq [options] filter [file(s)]
```

**Options:**
- `-r`: Raw output
- `-s`: Read all inputs into an array
- `-c`: Compact output
- `-M`: Monochrome output
- `-f file`: Read filter from file

**Examples:**
```bash
# Pretty-print JSON
cat file.json | jq '.'

# Extract specific field
cat file.json | jq '.name'

# Extract nested field
cat file.json | jq '.user.address.city'

# Format array elements
cat file.json | jq '.users[]'

# Filter array
cat file.json | jq '.users[] | select(.age > 30)'

# Transform data
cat file.json | jq '.users[] | {name: .name, age: .age}'

# Count elements
cat file.json | jq '.users | length'

# Raw output (no quotes)
cat file.json | jq -r '.name'
``` Number non-blank output lines
- `-s`: Suppress repeated empty output lines
- `-A`: Show all non-printing characters
- `-T`: Show tabs as ^I
- `-E`: Show end of line as $

**Examples:**
```bash
# Display file contents
cat file.txt

# Show line numbers
cat -n file.txt

# Concatenate multiple files
cat file1.txt file2.txt > combined.txt

# Create a file with content
cat > newfile.txt
This is a line of text.
Press Ctrl+D to save and exit

# Append to an existing file
cat >> file.txt
Additional text
Press Ctrl+D to save and exit
```

## less

A pager that allows backward and forward navigation through file contents.

```bash
less [options] file
```

**Options:**
- `-N`: Show line numbers
- `-i`: Case-insensitive search
- `-g`: Highlight only the last match of search
- `-S`: Chop long lines (instead of wrapping)
- `-F`: Quit if entire file can be displayed on first screen

**Navigation Commands (when less is running):**
- `q`: Quit
- `Space` or `f`: Forward one page
- `b`: Backward one page
- `g`: Go to first line
- `G`: Go to last line
- `/pattern`: Search forward for pattern
- `?pattern`: Search backward for pattern
- `n`: Repeat previous search
- `N`: Repeat previous search in reverse direction
- `h`: Display help

**Examples:**
```bash
# View a file with less
less file.txt

# Show line numbers
less -N file.txt

# Case-insensitive viewing
less -i file.txt

# View with line wrap disabled
less -S file.txt
```

## more

A simple pager for viewing text one screen at a time (forward only).

```bash
more [options] file
```

**Options:**
- `-d`: Display "Press space to continue, 'q' to quit" prompt
- `-s`: Squeeze multiple blank lines into one

**Examples:**
```bash
# View a file with more
more file.txt

# View multiple files
more file1.txt file2.txt

# View with helpful prompts
more -d file.txt
```

## head

Displays the beginning of a file.

```bash
head [options] [file(s)]
```

**Options:**
- `-n number`: Display first number lines (default: 10)
- `-c number`: Display first number bytes
- `-q`: Quiet mode (no headers for multi-file input)

**Examples:**
```bash
# Show first 10 lines
head file.txt

# Show first 20 lines
head -n 20 file.txt

# Show first 100 bytes
head -c 100 file.txt

# Show first 5 lines of multiple files
head -n 5 file1.txt file2.txt
```

## tail

Displays the end of a file.

```bash
tail [options] [file(s)]
```

**Options:**
- `-n number`: Display last number lines (default: 10)
- `-c number`: Display last number bytes
- `-f`: Follow file as it grows
- `-F`: Follow file by name (if file is rotated)
- `-q`: Quiet mode (no headers for multi-file input)

**Examples:**
```bash
# Show last 10 lines
tail file.txt

# Show last 20 lines
tail -n 20 file.txt

# Show last 100 bytes
tail -c 100 file.txt

# Follow file updates in real-time
tail -f /var/log/syslog

# Follow file updates even if file is rotated
tail -F /var/log/syslog
```

## grep

Searches for patterns in text.

```bash
grep [options] pattern [file(s)]
```

**Options:**
- `-i`: Ignore case
- `-v`: Invert match (show lines that don't match)
- `-n`: Show line numbers
- `-r`: Recursive search in directories
- `-l`: Show only filenames of matching files
- `-c`: Show only count of matching lines
- `-A num`: Show num lines after match
- `-B num`: Show num lines before match
- `-C num`: Show num lines before and after match
- `-E`: Extended regular expressions (same as egrep)
- `-w`: Match whole words only
- `-e pattern`: Specify multiple patterns
- `--color`: Highlight matching text

**Examples:**
```bash
# Search for pattern in file
grep "error" logfile.txt

# Case-insensitive search
grep -i "error" logfile.txt

# Show line numbers
grep -n "error" logfile.txt

# Search recursively in directory
grep -r "TODO" /path/to/project/

# Show 2 lines before and after match
grep -C 2 "error" logfile.txt

# Show only filenames containing matches
grep -l "error" *.log

# Count occurrences
grep -c "error" logfile.txt

# Match whole words only
grep -w "error" logfile.txt

# Use regular expressions
grep -E "error|warning" logfile.txt

# Show lines that don't match
grep -v "success" logfile.txt
```

## sed

Stream editor for filtering and transforming text.

```bash
sed [options] 'command' [file(s)]
```

**Options:**
- `-e script`: Add script to commands to be executed
- `-f file`: Add contents of script-file to commands
- `-i[suffix]`: Edit files in place (makes backup if suffix supplied)
- `-n`: Suppress automatic printing of pattern space

**Common commands:**
- `s/pattern/replacement/`: Substitute
- `d`: Delete pattern space
- `p`: Print pattern space
- `a\text`: Append text
- `i\text`: Insert text
- `c\text`: Change text
- `y/source/dest/`: Transliterate characters

**Examples:**
```bash
# Replace first occurrence of pattern in each line
sed 's/old/new/' file.txt

# Replace all occurrences of pattern in each line
sed 's/old/new/g' file.txt

# Replace on specific line number
sed '3s/old/new/' file.txt

# Replace in line range
sed '2,5s/old/new/g' file.txt

# Delete specific lines
sed '2,5d' file.txt

# Delete lines matching pattern
sed '/pattern/d' file.txt

# Print only lines matching pattern
sed -n '/pattern/p' file.txt

# Append text after line
sed '2a\New line text' file.txt

# Multiple commands
sed -e 's/old/new/g' -e '/pattern/d' file.txt

# Edit file in-place
sed -i 's/old/new/g' file.txt

# Edit file in-place with backup
sed -i.bak 's/old/new/g' file.txt
```

## awk

Pattern scanning and processing language.

```bash
awk [options] 'program' [file(s)]
```

**Options:**
- `-F fs`: Specify field separator (default is whitespace)
- `-f file`: Read program from file
- `-v var=value`: Assign value to variable
- `-W option`: Set implementation-specific option

**Program structure:**
```
pattern { action }
```

**Built-in variables:**
- `$0`: Entire line
- `$1, $2, ...`: Fields
- `NF`: Number of fields
- `NR`: Record number (line number)
- `FS`: Field separator
- `RS`: Record separator
- `OFS`: Output field separator
- `ORS`: Output record separator

**Examples:**
```bash
# Print specific columns (fields)
awk '{print $1, $3}' file.txt

# Use custom field separator
awk -F, '{print $1, $3}' csv_file.csv

# Print lines matching pattern
awk '/pattern/' file.txt

# Conditional actions
awk '$3 > 100 {print $1, $3}' file.txt

# Calculate sum
awk '{sum += $1} END {print "Sum:", sum}' numbers.txt

# Print line numbers and lines
awk '{print NR, $0}' file.txt

# Format output
awk '{printf "%-10s %s\n", $1, $2}' file.txt

# Process specific fields
awk -F: '{print "Username: " $1 ", Shell: " $NF}' /etc/passwd

# Multiple patterns and actions
awk '$1 == "ERROR" {print "Error on line", NR} 
     $1 == "WARNING" {print "Warning on line", NR}' logfile.txt
```

## sort

Sorts lines of text files.

```bash
sort [options] [file(s)]
```

**Options:**
- `-n`: Numeric sort
- `-r`: Reverse order
- `-f`: Ignore case
- `-u`: Unique only (remove duplicates)
- `-t char`: Use char as field separator
- `-k pos1[,pos2]`: Sort by key starting at pos1 and ending at pos2
- `-h`: Human numeric sort (e.g., 2K, 1G)
- `-V`: Version number sort
- `-b`: Ignore leading blanks
- `-o file`: Write result to file

**Examples:**
```bash
# Simple sort
sort file.txt

# Numeric sort
sort -n numbers.txt

# Reverse sort
sort -r file.txt

# Sort and remove duplicates
sort -u file.txt

# Sort by specific column (field)
sort -k 2 file.txt

# Sort by 3rd field numerically
sort -k 3n file.txt

# Sort by multiple fields
sort -k 1,1 -k 2n file.txt

# Sort using custom delimiter
sort -t: -k 3n /etc/passwd

# Human-readable size sort
ls -lh | sort -k 5h

# Version number sort
sort -V versions.txt

# Sort and save result
sort file.txt -o sorted_file.txt
```

## uniq

Reports or filters out repeated lines.

```bash
uniq [options] [input [output]]
```

**Options:**
- `-c`: Prefix lines with count
- `-d`: Only print duplicate lines, one for each group
- `-u`: Only print unique lines
- `-i`: Ignore case
- `-f num`: Skip first num fields
- `-s chars`: Skip first chars characters

**Examples:**
```bash
# Remove consecutive duplicate lines
uniq file.txt

# Count occurrences
uniq -c file.txt

# Show only duplicate lines
uniq -d file.txt

# Show only unique lines
uniq -u file.txt

# Ignore case when comparing
uniq -i file.txt

# Skip fields when comparing
uniq -f 2 file.txt

# Often used with sort
sort file.txt | uniq
sort file.txt | uniq -c
```

## cut

Removes sections from each line.

```bash
cut [options] [file(s)]
```

**Options:**
- `-c list`: Select only these characters
- `-f list`: Select only these fields
- `-d delim`: Use delim as field delimiter (default: TAB)
- `--complement`: Invert selection
- `-s`: Do not print lines without delimiter

**Examples:**
```bash
# Extract characters by position
cut -c 1-5 file.txt

# Extract specific character positions
cut -c 1,3,5-7 file.txt

# Extract fields from CSV file
cut -d, -f 1,3 file.csv

# Extract fields from colon-delimited file
cut -d: -f 1,7 /etc/passwd

# Extract everything except specified fields
cut -d, -f 2 --complement file.csv
```

## paste

Merges lines of files horizontally.

```bash
paste [options] [file(s)]
```

**Options:**
- `-d list`: Use characters from list as delimiters
- `-s`: Paste one file at a time instead of in parallel

**Examples:**
```bash
# Combine two files side by side (tab-separated)
paste file1.txt file2.txt

# Combine with custom delimiter
paste -d, file1.txt file2.txt

# Combine all files into one line per file
paste -s file1.txt file2.txt

# Combine with multiple delimiters (rotating)
paste -d ",:;" file1.txt file2.txt file3.txt
```

## tr

Translates or deletes characters.

```bash
tr [options] set1 [set2]
```

**Options:**
- `-d`: Delete characters in set1
- `-s`: Squeeze repeated characters in set1
- `-c`: Complement set1
- `-t`: Truncate set1 to length of set2

**Examples:**
```bash
# Convert lowercase to uppercase
cat file.txt | tr 'a-z' 'A-Z'

# Delete specific characters
cat file.txt | tr -d 'aeiou'

# Squeeze repeated characters
cat file.txt | tr -s ' '

# Replace newlines with spaces
cat file.txt | tr '\n' ' '

# Remove all non-printable characters
cat file.txt | tr -cd '[:print:]'

# Replace multiple characters
cat file.txt | tr '{}' '()'
```

## wc

Counts lines, words, and characters.

```bash
wc [options] [file(s)]
```

**Options:**
- `-l`: Count lines only
- `-w`: Count words only
- `-c`: Count characters only
- `-m`: Count characters only (taking multibyte characters into account)
- `-L`: Print the length of the longest line

**Examples:**
```bash
# Count lines, words, and characters
wc file.txt

# Count only lines
wc -l file.txt

# Count only words
wc -w file.txt

# Count characters
wc -c file.txt

# Count multibyte characters
wc -m file.txt

# Get length of longest line
wc -L file.txt

# Count lines in multiple files
wc -l file1.txt file2.txt

# Count lines in all text files
wc -l *.txt
```

## diff

Compares files line by line.

```bash
diff [options] file1 file2
```

**Options:**
- `-u`: Unified format
- `-y`: Side-by-side format
- `-i`: Ignore case differences
- `-w`: Ignore whitespace
