## trimmy

This C program, `trimmy`, helps you verify trailing whitespaces at the end of lines in files. It's designed to be cross-platform and works on both Linux and Windows.

## Features

- Checks for trailing whitespaces at the end of lines.
- Handles multiple files specified as command-line arguments.
- Provides visual feedback using color highlighting.

## How to Use

### Linux/macOS

1. **Prerequisites Ensure you have a C compiler (`gcc`) installed.**
2. **Compile**
   ```bash
   make
   ```
3. **Run**
   ```bash
   ./trimmy file1.txt file2.txt
   ```

### Windows

1. **Prerequisites**
   - Download and install the [w64devkit](https://github.com/skeeto/w64devkit) for Windows. This provides Unix-like utilities like `rm` and `gcc` that work with the `makefile`.
2. **Compile Open a command prompt or terminal and navigate to the project directory. Then, run:**
   ```bash
   make
   ```
3. **Run Use the compiled executable (`trimmy.exe`) to check your files:**
   ```bash
   trimmy.exe file1.txt file2.txt
   ```

### Output

* If a file contains trailing whitespaces:
    - The file name will be displayed.
    - Trailing whitespaces will be marked with a green `•`.

* If a file does not contain trailing whitespaces:
    - No output will be shown for that file.

### Example Output (Linux/macOS)

```
FILE: my_code.c

1  | int main() {•••
3  | }••
```

## License

This program is licensed under the MIT License. Refer to the [LICENSE](LICENSE) file for details.
