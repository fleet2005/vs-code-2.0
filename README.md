# Advanced Copy Paste Extension

A powerful VS Code extension that provides advanced copy-paste functionality with multiple data structure support.

## Features

- Multiple data structure support (Array, Stack, Queue)
- Customizable keyboard shortcuts
- Display stored content
- Easy switching between data structures
- Clear storage functionality

## Keybindings

### Array Mode
- `Ctrl+C` (once) - Add to array[0]
- `Ctrl+C` (twice) - Add to array[1]
- `Ctrl+C` (thrice) - Add to array[2]
- `Ctrl+V` (once) - Access array[0]
- `Ctrl+V` (twice) - Access array[1]
- `Ctrl+V` (thrice) - Access array[2]

### Stack Mode
- `Ctrl+C` - Push to stack
- `Ctrl+V` - Pop from stack

### Queue Mode
- `Ctrl+C` - Enqueue
- `Ctrl+V` - Dequeue

### Generic Commands
- `Ctrl+0` - Display content at index 0
- `Ctrl+1` - Display content at index 1
- `Ctrl+2` - Display content at index 2
- `Ctrl+4` - Switch data structure
- `Ctrl+5` - Clear stored content

## Requirements

- Visual Studio Code 1.85.0 or higher
- C++ compiler (MSVC, GCC, or Clang)

## Installation

1. Download the VSIX file
2. Open VS Code
3. Go to Extensions view (Ctrl+Shift+X)
4. Click on the "..." menu
5. Select "Install from VSIX..."
6. Choose the downloaded VSIX file

## Usage

1. Select text and use the appropriate keyboard shortcuts to copy/paste
2. Use Ctrl+4 to switch between different data structures
3. Use Ctrl+0, Ctrl+1, Ctrl+2 to view stored content
4. Use Ctrl+5 to clear the current storage

## Extension Settings

This extension contributes the following settings:

* `advancedCopyPaste.dataStructure`: Choose the default data structure (array/stack/queue)
* `advancedCopyPaste.maxArraySize`: Maximum size for array storage (default: 3)

## Known Issues

None at the moment.

## Release Notes

### 0.0.1

Initial release of Advanced Copy Paste extension.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This extension is licensed under the MIT License. 