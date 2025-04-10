# Miscellaneous Tools

This section covers various useful utilities and tools that don't fit into other categories but are helpful for a Linux system administrator or power user.

## tmux

A terminal multiplexer that allows you to run multiple terminal sessions within a single window.

```bash
tmux [options] [command]
```

**Options:**
- `-s session-name`: Start a new session with the specified name
- `-a`: Attach to existing session
- `-d`: Detach from session
- `-l`: List sessions
- `-c`: Execute command in a new session

**Common Key Bindings (after pressing prefix Ctrl+b):**
- `c`: Create a new window
- `p`: Switch to the previous window
- `n`: Switch to the next window
- `0-9`: Switch to window by number
- `%`: Split window vertically
- `"`: Split window horizontally
- `arrow keys`: Navigate between panes
- `d`: Detach from session
- `[`: Enter copy mode (use arrows to move, `q` to quit)
- `]`: Paste from buffer
- `:`: Enter command mode

**Examples:**
```bash
# Start a new session
tmux

# Start a named session
tmux new -s mysession

# List sessions
tmux ls

# Attach to a session
tmux attach -t mysession

# Create a new session and run a command
tmux new-session -s backup "rsync -a /home /backup"

# Kill a session
tmux kill-session -t mysession
```

## screen

Another terminal multiplexer (older than tmux but still useful).

```bash
screen [options]
```

**Options:**
- `-S session-name`: Start a new session with the specified name
- `-r`: Reattach to a detached screen session
- `-d`: Detach a screen session
- `-ls`: List running screen sessions
- `-x`: Attach to a session that is already attached elsewhere

**Common Key Bindings (after pressing prefix Ctrl+a):**
- `c`: Create a new window
- `p`: Switch to the previous window
- `n`: Switch to the next window
- `0-9`: Switch to window by number
- `S`: Split window horizontally
- `|`: Split window vertically
- `tab`: Navigate between regions
- `d`: Detach from session
- `[`: Enter copy mode
- `]`: Paste from buffer
- `:`: Enter command mode

**Examples:**
```bash
# Start a new session
screen

# Start a named session
screen -S mysession

# List sessions
screen -ls

# Reattach to a detached session
screen -r mysession

# Detach a running session
screen -d mysession

# Create a new session and run a command
screen -dmS backup rsync -a /home /backup
```

## ranger

A console file manager with VI key bindings.

```bash
ranger [options] [path]
```

**Options:**
- `--copy-config=file`: Create a copy of the specified configuration file
- `--clean`: Remove the unused directory from the cache
- `--choosefile=file`: Choose a file and store the result in the provided file
- `--choosedir=file`: Choose a directory and store the result in the provided file

**Key Bindings:**
- `h/j/k/l`: Navigation (left/down/up/right)
- `gg/G`: Go to top/bottom
- `H/M/L`: Go to top/middle/bottom of visible area
- `/`: Search
- `n/N`: Next/previous search result
- `f`: Find (search as you type)
- `space`: Select current file
- `yy`: Copy file
- `dd`: Cut file
- `pp`: Paste file
- `A`: Rename file with cursor at the end
- `i`: Rename file with cursor at the beginning
- `a`: Rename file with cursor after the extension
- `cw`: Rename selected part
- `dd`: Cut file(s)
- `dD`: Delete file(s)
- `q`: Quit

**Examples:**
```bash
# Start ranger
ranger

# Start in a specific directory
ranger /home/user/Documents

# Create default config files
ranger --copy-config=all
```

## bc

An arbitrary precision calculator language.

```bash
bc [options] [file]
```

**Options:**
- `-l`: Use the math library (enables sine, cosine, etc.)
- `-i`: Interactive mode
- `-q`: Quiet mode (don't print welcome message)

**Examples:**
```bash
# Start interactive bc
bc -l

# Calculate an expression
echo "10 / 3" | bc

# Calculate with precision
echo "scale=4; 10 / 3" | bc

# Calculate using math functions
echo "s(1)" | bc -l  # sine of 1 radian

# Perform calculations from a file
bc -l calculations.txt

# Convert from one base to another (decimal to binary)
echo "obase=2; 42" | bc

# Convert from binary to decimal
echo "ibase=2; 101010" | bc
```

## youtube-dlp

A command-line program to download videos from YouTube and other sites (fork of youtube-dl with more features and regular updates).

```bash
youtube-dlp [options] [url]
```

**Options:**
- `-f format`: Select video format
- `-o template`: Output filename template
- `-a file`: Read URLs from file
- `--write-sub`: Write subtitle file
- `--list-formats`: List available formats
- `--extract-audio`: Convert video to audio
- `--audio-format FORMAT`: Specify audio format (mp3, m4a, etc.)
- `--playlist-start NUMBER`: Start at playlist item
- `--playlist-end NUMBER`: End at playlist item

**Examples:**
```bash
# Download a video
youtube-dlp https://www.youtube.com/watch?v=dQw4w9WgXcQ

# List available formats
youtube-dlp --list-formats https://www.youtube.com/watch?v=dQw4w9WgXcQ

# Download specific format
youtube-dlp -f 22 https://www.youtube.com/watch?v=dQw4w9WgXcQ

# Download with custom filename
youtube-dlp -o "%(title)s.%(ext)s" https://www.youtube.com/watch?v=dQw4w9WgXcQ

# Extract audio only (convert to mp3)
youtube-dlp --extract-audio --audio-format mp3 https://www.youtube.com/watch?v=dQw4w9WgXcQ

# Download video with subtitles
youtube-dlp --write-sub https://www.youtube.com/watch?v=dQw4w9WgXcQ

# Download playlist
youtube-dlp https://www.youtube.com/playlist?list=PLxxx

# Download only items 3-10 from playlist
youtube-dlp --playlist-start 3 --playlist-end 10 https://www.youtube.com/playlist?list=PLxxx

# Update youtube-dlp
youtube-dlp -U
```

## ffmpeg

A complete, cross-platform solution to record, convert and stream audio and video.

```bash
ffmpeg [global options] {[input file options] -i input_file} ... {[output file options] output_file} ...
```

**Common Options:**
- `-i`: Input file
- `-c:v`: Video codec
- `-c:a`: Audio codec
- `-b:v`: Video bitrate
- `-b:a`: Audio bitrate
- `-r`: Frame rate
- `-s`: Frame size
- `-t`: Duration
- `-ss`: Start time
- `-to`: End time
- `-f`: Force format

**Examples:**
```bash
# Convert video format
ffmpeg -i input.mp4 output.avi

# Convert video with specific codec
ffmpeg -i input.mp4 -c:v libx264 -c:a aac output.mkv

# Extract audio from video
ffmpeg -i input.mp4 -vn output.mp3

# Compress video
ffmpeg -i input.mp4 -c:v libx264 -crf 23 output.mp4

# Trim video (start at 10s, end at 30s)
ffmpeg -i input.mp4 -ss 00:00:10 -to 00:00:30 -c:v copy -c:a copy output.mp4

# Resize video
ffmpeg -i input.mp4 -s 1280x720 output.mp4

# Extract frames from video
ffmpeg -i input.mp4 -r 1 frames/frame-%03d.jpg

# Combine images into video
ffmpeg -framerate 24 -pattern_type glob -i 'frames/*.jpg' -c:v libx264 output.mp4

# Add audio to video
ffmpeg -i video.mp4 -i audio.mp3 -c:v copy -c:a aac -shortest output.mp4

# Create a video from an image and audio
ffmpeg -loop 1 -i image.jpg -i audio.mp3 -c:v libx264 -c:a aac -shortest output.mp4
```

## pandoc

A universal document converter.

```bash
pandoc [options] [input-file]...
```

**Options:**
- `-f/--from FORMAT`: Specify input format
- `-t/--to FORMAT`: Specify output format
- `-o/--output FILE`: Write output to FILE
- `-s/--standalone`: Create standalone document
- `--template FILE`: Use FILE as template
- `--toc`: Include table of contents
- `--pdf-engine=ENGINE`: Use ENGINE for PDF output

**Examples:**
```bash
# Convert Markdown to HTML
pandoc -f markdown -t html -o output.html input.md

# Convert Markdown to PDF
pandoc input.md -o output.pdf

# Convert HTML to Markdown
pandoc -f html -t markdown -o output.md input.html

# Convert Markdown to DOCX
pandoc -o output.docx input.md

# Convert multiple files to a single output
pandoc -o combined.html input1.md input2.md input3.md

# Create standalone HTML with table of contents
pandoc -s --toc -o output.html input.md

# Convert with a custom template
pandoc --template=template.html -o output.html input.md
```

## ImageMagick

A suite of command-line utilities to create, edit, compose, or convert digital images.

**Main Commands:**
- `convert`: Convert between image formats and modify images
- `mogrify`: Transform images in-place
- `identify`: Describe the format and characteristics of an image
- `composite`: Compose images together
- `montage`: Create a composite image from multiple images
- `display`: Display images on screen (X11)

**Examples:**
```bash
# Convert image format
convert image.png image.jpg

# Resize image
convert input.jpg -resize 800x600 output.jpg

# Maintain aspect ratio, limit width
convert input.jpg -resize 800x output.jpg

# Crop image
convert input.jpg -crop 300x300+100+100 output.jpg

# Rotate image
convert input.jpg -rotate 90 output.jpg

# Add text to image
convert input.jpg -pointsize 24 -fill red -annotate +50+50 'Hello World' output.jpg

# Apply effects
convert input.jpg -charcoal 2 output.jpg

# Create a thumbnail
convert input.jpg -thumbnail 100x100 thumbnail.jpg

# Batch convert multiple images
mogrify -format jpg *.png

# Create a montage
montage *.jpg -geometry 200x200+10+10 montage.jpg

# Identify image information
identify image.jpg
```

## git

A distributed version control system.

```bash
git [options] [command] [arguments]
```

**Common Commands:**
- `init`: Create a new repository
- `clone`: Clone a repository
- `add`: Add files to staging area
- `commit`: Commit changes
- `status`: Show repository status
- `diff`: Show changes between commits
- `branch`: List, create, or delete branches
- `checkout`: Switch branches or restore files
- `merge`: Merge branches
- `pull`: Fetch from and integrate with another repository
- `push`: Update remote repository
- `log`: Show commit logs

**Examples:**
```bash
# Initialize a repository
git init

# Clone a repository
git clone https://github.com/username/repository.git

# Check status
git status

# Add files to staging
git add file.txt
git add .  # Add all files

# Commit changes
git commit -m "Commit message"

# Push changes to remote repository
git push origin main

# Pull changes from remote repository
git pull origin main

# Create a new branch
git branch new-feature

# Switch to a branch
git checkout new-feature

# Create and switch to a new branch
git checkout -b new-feature

# Merge a branch
git merge new-feature

# View commit history
git log

# View differences
git diff

# Reset changes
git reset --hard HEAD

# Show remotes
git remote -v

# Add a remote
git remote add origin https://github.com/username/repository.git
```

## grep, awk, sed

These text processing utilities are covered in detail in the [Text Processing](10-text-processing.md) section.

## cmatrix

A terminal-based "Matrix" screen saver.

```bash
cmatrix [options]
```

**Options:**
- `-a`: Asynchronous scroll
- `-b`: Bold characters on
- `-B`: All bold characters
- `-c`: Use console default colors
- `-C`: Use color X
- `-f`: Force the Linux $TERM type
- `-l`: Linux mode
- `-n`: Turn off bold characters
- `-o`: Use old-style scrolling
- `-r`: Rainbow mode
- `-s`: "Screen saver" mode
- `-u`: Update delay (0-9)
- `-x`: X window mode

**Examples:**
```bash
# Run cmatrix in default mode
cmatrix

# Run with rainbow colors
cmatrix -r

# Run in "screen saver" mode
cmatrix -s

# Run with bold characters
cmatrix -b
```

## neofetch

A command-line system information tool that displays system information alongside an ASCII logo of the Linux distribution.

```bash
neofetch [options]
```

**Options:**
- `--config FILE`: Specify a custom config file
- `--color_blocks on/off`: Enable/disable color blocks
- `--bar_char 'CHARACTER'`: Character for bars
- `--off`: Disable all colors and ASCII logo
- `--ascii_distro DISTRO`: Use custom distro art
- `--crop_mode mode`: Crop mode (normal, fit, fill)
- `--image IMAGE`: Display an image
- `--image_size SIZE`: Specify image size

**Examples:**
```bash
# Display system information
neofetch

# Use custom distro logo
neofetch --ascii_distro debian

# Show image instead of ASCII art
neofetch --image ~/image.png

# Disable color blocks
neofetch --color_blocks off
```

## calcurse

A text-based calendar and scheduling application.

```bash
calcurse [options]
```

**Options:**
- `-c file`: Specify the calendar file
- `-a file`: Specify the appointment file
- `-t file`: Specify the todo file
- `-i file`: Import iCal data
- `-x [format]`: Export data
- `-D dir`: Specify the configuration directory
- `-d date`: Start with specified date

**Key Bindings:**
- Arrow keys: Navigate
- `Tab`: Switch between panels
- `a`: Add an appointment
- `t`: Add a task
- `d`: Delete an item
- `e`: Edit an item
- `v`: View an item
- `g`: Go to specific date
- `q`: Quit

**Examples:**
```bash
# Start calcurse
calcurse

# Import iCal data
calcurse -i ical-file.ics

# Export data to iCal format
calcurse -x ical > my-calendar.ics

# Start with a specific date
calcurse -d 2023-06-01
```

## lolcat

Adds rainbow coloring to text output.

```bash
lolcat [options] [files]
```

**Options:**
- `-f`: Force color even when stdout is not a tty
- `-p`: Print plain output, no rainbow effect
- `-s`: Animate the rainbow effect
- `-a`: Animation speed
- `-d`: Duration of animation
- `-F`: Frequency of colors

**Examples:**
```bash
# Basic usage
ls -la | lolcat

# Show command output with rainbow effect
cat /etc/passwd | lolcat

# Animate the rainbow
fortune | lolcat -a -d 500

# Apply to a file
lolcat /etc/hosts
```

## cowsay

Generates ASCII art of a cow with a message.

```bash
cowsay [options] [message]
```

**Options:**
- `-b`: "Borg" mode (uses ==)
- `-d`: "Dead" mode (uses XX)
- `-g`: "Greedy" mode (uses $)
- `-p`: "Paranoid" mode (uses @@)
- `-s`: "Stoned" mode (uses **)
- `-t`: "Tired" mode (uses --)
- `-w`: "Wired" mode (uses OO)
- `-y`: "Youthful" mode (uses ..)
- `-f cowfile`: Use a specific cow file

**Examples:**
```bash
# Basic usage
cowsay "Hello, World!"

# Using a different cow file
cowsay -f tux "Linux is awesome!"

# Combine with fortune for random quotes
fortune | cowsay

# Dead cow mode
cowsay -d "I'm not feeling well"

# Pipe command output
uptime | cowsay
```

## ncdu

NCurses Disk Usage - a disk usage analyzer with an ncurses interface.

```bash
ncdu [options] [directory]
```

**Options:**
- `-x`: Don't cross filesystem boundaries
- `-r`: Read-only mode (disables file deletion)
- `-q`: Quiet mode (no user interface)
- `-e`: Enable extended information
- `-C`: Color scheme

**Key Bindings:**
- `up/down`: Navigate
- `right/enter`: Enter directory
- `left`: Go to parent directory
- `d`: Delete selected file/directory
- `n`: Sort by name
- `s`: Sort by size
- `C`: Sort by item count
- `g`: Show percentage/graph
- `i`: Show information
- `q`: Quit

**Examples:**
```bash
# Analyze current directory
ncdu

# Analyze specific directory
ncdu /var

# Don't cross filesystem boundaries
ncdu -x /

# Export result to file
ncdu -o output.file /home

# Import from file
ncdu -f output.file
```

## htop

An interactive process viewer (covered in more detail in [Process Management](09-process-management.md)).

## nmon

A performance monitoring tool for Linux.

```bash
nmon [options]
```

**Options:**
- `-f`: Save data to a file
- `-s seconds`: Time between each update
- `-c count`: Number of iterations
- `-t`: Include top processes
- `-x`: Enable all statistics

**Interactive Commands:**
- `h`: Show help
- `q`: Quit
- `c`: CPU stats
- `m`: Memory stats
- `d`: Disk stats
- `n`: Network stats
- `t`: Top processes
- `v`: Verbose mode
- `r`: Resources

**Examples:**
```bash
# Start nmon in interactive mode
nmon

# Capture data to a file (24 snapshots, 30 seconds apart)
nmon -f -s 30 -c 24

# Enable all monitoring
nmon -x
```

## sar

System Activity Reporter - collects, reports, and saves system activity information.

```bash
sar [options] [interval [count]]
```

**Options:**
- `-A`: Report all information
- `-u`: CPU utilization
- `-r`: Memory utilization
- `-b`: I/O and transfer rate statistics
- `-d`: Block device activity
- `-n`: Network statistics
- `-f file`: Extract data from file
- `-o file`: Save data to file
- `-s time`: Set start time
- `-e time`: Set end time

**Examples:**
```bash
# Report CPU usage every 2 seconds for 5 times
sar 2 5

# Report memory usage
sar -r 1 3

# Report all statistics
sar -A

# Save data to a file
sar -o output.file 2 10

# Extract data from a file
sar -f output.file

# Report network statistics
sar -n DEV 1 5
```

## pass

A password manager that follows the Unix philosophy.

```bash
pass [command] [arguments]
```

**Commands:**
- `init`: Initialize the password store
- `ls`: List passwords
- `show`: Show password
- `insert`: Insert a new password
- `edit`: Edit a password
- `generate`: Generate a new password
- `rm`: Remove a password
- `mv`: Move a password
- `cp`: Copy a password
- `git`: Run git command on the password store

**Examples:**
```bash
# Initialize password store
pass init "GPG-ID"

# Add a password
pass insert Email/gmail

# Generate a password
pass generate Email/outlook 15

# Show a password
pass Email/gmail

# Copy a password to clipboard
pass -c Email/gmail

# Edit a password
pass edit Email/gmail

# Remove a password
pass rm Email/gmail

# List all passwords
pass ls
```

## gpg

GNU Privacy Guard - encryption and signing tool.

```bash
gpg [options] [files]
```

**Common Commands:**
- `--encrypt`: Encrypt data
- `--decrypt`: Decrypt data
- `--sign`: Make a signature
- `--verify`: Verify a signature
- `--gen-key`: Generate a new key pair
- `--list-keys`: List keys
- `--import`: Import keys
- `--export`: Export keys
- `--delete-key`: Delete keys

**Examples:**
```bash
# Generate a key pair
gpg --gen-key

# List public keys
gpg --list-keys

# List secret keys
gpg --list-secret-keys

# Encrypt a file for a recipient
gpg --encrypt --recipient user@example.com document.txt

# Decrypt a file
gpg --decrypt document.txt.gpg > document.txt

# Sign a file
gpg --sign document.txt

# Verify a signature
gpg --verify document.txt.gpg

# Export a public key
gpg --export --armor user@example.com > pubkey.asc

# Import a public key
gpg --import pubkey.asc
```

## bat

A cat clone with syntax highlighting and Git integration.

```bash
bat [options] [files]
```

**Options:**
- `-p, --plain`: Show plain mode (no line numbers, etc.)
- `-l, --language`: Set the language for syntax highlighting
- `-H, --highlight-line`: Highlight specific lines
- `-n, --number`: Show line numbers
- `-A, --show-all`: Show all (non-printable characters)
- `--theme`: Set the theme for syntax highlighting
- `--list-themes`: List available themes
- `--list-languages`: List supported languages

**Examples:**
```bash
# View a file with syntax highlighting
bat script.py

# Show plain text without additional features
bat --plain file.txt

# View with a specific language
bat --language=json data.txt

# Highlight specific lines
bat --highlight-line 10:20 file.txt

# Use a specific theme
bat --theme=TwoDark file.txt

# List all themes
bat --list-themes

# Show multiple files
bat file1.txt file2.txt
```

## feh

A lightweight image viewer.

```bash
feh [options] [files/directories]
```

**Options:**
- `-F, --fullscreen`: Fullscreen mode
- `-d, --draw-filename`: Display filename
- `-Z, --auto-zoom`: Zoom to fit window
- `-r, --recursive`: Load files recursively from directories
- `--slideshow-delay seconds`: Set slideshow delay
- `--start-at file`: Start at specific file
- `-g, --geometry WxH`: Set window size
- `-z, --randomize`: Randomize filelist

**Examples:**
```bash
# View images
feh image.jpg

# View all images in a directory
feh directory/

# Slideshow with 5-second delay
feh --slideshow-delay 5 *.jpg

# Fullscreen view
feh -F image.jpg

# Recursive view of all images
feh -r directory/

# Randomized slideshow
feh -z --slideshow-delay 3 directory/

# Set window size
feh -g 800x600 image.jpg
```

## tldr

Simplified, community-driven man pages.

```bash
tldr [options] [command]
```

**Options:**
- `-l, --list`: List all available commands
- `-p, --platform`: Show page for specific platform
- `-u, --update`: Update local cache
- `-v, --version`: Show version information

**Examples:**
```bash
# Show simplified help for a command
tldr tar

# Show help for platform-specific command
tldr -p linux systemctl

# Update local cache
tldr --update

# List all available commands
tldr --list
```

## asciinema

Record and share terminal sessions.

```bash
asciinema [command] [options]
```

**Commands:**
- `rec`: Record terminal session
- `play`: Replay recorded session
- `cat`: Print full output of recorded session
- `upload`: Upload recorded session
- `auth`: Manage recordings ownership

**Options for rec:**
- `-i, --idle-time-limit`: Limit idle time
- `-t, --title`: Set title of the recording
- `-c, --command`: Command to record
- `-y, --yes`: Answer "yes" to all prompts
- `-q, --quiet`: Be quiet (suppress all notices/warnings)

**Examples:**
```bash
# Record a terminal session
asciinema rec

# Record with a title
asciinema rec -t "My Terminal Demo"

# Record with idle time limit of 2 seconds
asciinema rec -i 2

# Play a recording from a local file
asciinema play recording.cast

# Play a recording from asciinema.org
asciinema play https://asciinema.org/a/123456

# Upload a recording
asciinema upload recording.cast
```

## pfetch

A lightweight system information tool (similar to neofetch but faster).

```bash
pfetch
```

There are no command-line options, but you can set environment variables to customize the output:

```bash
# Show specific information
PF_INFO="ascii title os host kernel uptime pkgs memory" pfetch

# Use a different ASCII art
PF_ASCII="openbsd" pfetch

# Set colors
PF_COL1=4 PF_COL2=5 PF_COL3=6 pfetch
```

## xcompmgr

A simple composite manager for X.

```bash
xcompmgr [options]
```

**Options:**
- `-c`: Client-side compositing with soft shadows
- `-C`: Client-side compositing with shadows (without shaping)
- `-f`: Fade windows in/out
- `-F`: Fade windows in/out more slowly
- `-D time`: Specify fade-in time
- `-r radius`: Set shadow radius
- `-o opacity`: Set shadow opacity
- `-l offset`: Set shadow offset to the left
- `-t offset`: Set shadow offset to the top

**Examples:**
```bash
# Basic compositing with shadows
xcompmgr -c

# Compositing with fade effects
xcompmgr -c -f

# Custom shadow settings
xcompmgr -c -r 8 -o 0.7 -l -10 -t -10
```

## dmenu

A dynamic menu for X, typically used as an application launcher.

```bash
dmenu [options]
```

**Options:**
- `-b`: Place dmenu at the bottom
- `-f`: Grab the keyboard
- `-i`: Case-insensitive matching
- `-l lines`: Vertical list with specified number of lines
- `-p prompt`: Define a custom prompt
- `-fn font`: Set font
- `-nb color`: Set normal background color
- `-nf color`: Set normal foreground color
- `-sb color`: Set selected background color
- `-sf color`: Set selected foreground color

**Examples:**
```bash
# Basic application launcher
dmenu_run

# Custom prompt and at the bottom
dmenu_run -p "Run:" -b

# Case-insensitive with custom colors
dmenu_run -i -nb "#222222" -nf "#bbbbbb" -sb "#005577" -sf "#eeeeee"

# Create a custom menu
echo -e "option1\noption2\noption3" | dmenu -p "Choose:"

# Vertical list with 10 lines
ls | dmenu -l 10
```

## zathura

A lightweight document viewer with Vim-like keybindings.

```bash
zathura [options] file
```

**Options:**
- `-p page`: Open specific page
- `-f fullscreen`: Start in fullscreen mode
- `-P seconds`: Set presentation mode delay
- `-c config`: Use alternate config file

**Key Bindings:**
- `j/k`: Scroll down/up
- `h/l`: Scroll left/right
- `J/K`: Page down/up
- `gg`: Go to first page
- `G`: Go to last page
- `nG`: Go to page n
- `/`: Search
- `n/N`: Next/previous search result
- `a`: Adjust to width
- `s`: Adjust to height
- `f`: Toggle fullscreen
- `i`: Toggle inverted colors
- `r`: Rotate
- `+/-`: Zoom in/out
- `=`: Set zoom to 100%

**Examples:**
```bash
# Open a PDF file
zathura document.pdf

# Open a specific page
zathura -p 42 document.pdf

# Start in fullscreen mode
zathura -f document.pdf

# Presentation mode
zathura -P 5 presentation.pdf
```
