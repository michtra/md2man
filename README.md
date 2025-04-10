# md2man

A command-line tool to convert Markdown files into a fully-fledged HTML/CSS reference manual.

## Features

- Converts Markdown files to HTML
- Generates a complete reference manual with navigation
- Supports standard Markdown features
- Auto-generates table of contents
- Responsive design works on desktop and mobile
- Navigation indicators that show active pages
- Customizable templates for CSS and JavaScript

## Usage

```
md2man <input_dir> <output_dir> [title] [author]
```

- `input_dir`: Directory containing Markdown files
- `output_dir`: Directory where the HTML manual will be generated
- `title`: (Optional) Title of the manual (default: "Reference Manual")
- `author`: (Optional) Author name to be displayed in the manual

## Templates

md2man uses external template files for styling and JavaScript functionality:

- `templates/style.css`: CSS stylesheet template
- `templates/script.js`: JavaScript template

## Building from Source

### Prerequisites

- C++17 compatible compiler
- CMake 3.10 or higher

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/michtra/md2man
cd md2man

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

# Install (optional)
sudo make install

# Usage
cd <root>
build/md2man input out "Manual" "michtra"
```

## Example usage (Using the included examples/)

```bash
# Convert Markdown files in the 'examples/linux' directory to a manual in 'out'
md2man examples/linux out "Linux Reference Manual" "Michael Tran"

# Before running, you can customize the templates in the templates/ directory
```

## Markdown Support

The tool supports the following Markdown features:

- Headings (# to ######)
- Paragraphs
- Lists (ordered and unordered)
- Code blocks with syntax highlighting
- Inline formatting (bold, italic, code)
- Links and images
- Horizontal rules

## Output Structure

The generated manual includes:

- Index page with links to all documentation pages
- Content pages for each markdown file
- Navigation sidebar with active page indicators
- Table of contents for each page
- Responsive design for mobile and desktop

## License

MIT
