# trimmy

This C program, `trimmy`, helps you verify if a file contain trailing whitespaces at the end of some lines. It can be useful for cleaning up code or text files where whitespace characters might cause unintended behavior or formatting issues.

## How to Use

1. Compile the program using a C compiler (e.g., `gcc`):

   ```bash
   make
   ```

2. Run the program with the name of the file you want to check:

   ```bash
   ./trimmy file1.txt
   ```

## Output

* If a file contains trailing whitespaces:
    - The file name will be displayed in yellow.
    - Each line with trailing whitespaces will be marked with a green `•` and highlighted.

* If a file does not contain trailing whitespaces:
    - No output will be shown for that file.

## Example Output

```
FILE: my_code.c

1  | int main() {••
2  |   return 0;•••
3  | }•
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
