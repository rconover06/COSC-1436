# Syntax Cheatsheet

## Special Characters
Character | Name | Description
----------|------|------------
  `//` | Double slash    | Marks the beginning of a comment
  `#`  | Pound sign      |Beginning of  a preprocesor directive
  `<>` | Brackets        | Enclose a filename when used with the #include directive
  `()` | Parentheses     | Used with naming a function
  `{}` | Braces          | Enclose a group of statements
  `""` | Quotation Marks |Enclose a string of characters
  `;`  | semicolon       | Marks the end of a complete programming statement

## Common Keywords
. | . | . | . | . 
-----------|--------------|---------------|-------------------|----------
alignas    | const        | **for**       | private           | throw
alignof    | constexpr    | friend        | protected         | true
and        | const_cast   | goto          | public            | try
and_eq     | continue     | **if**        | register          | typedef 
asm        | decltype     | inline        | reinterpret_cast  | typeid
auto       | default      | **int**       | **return**        | typename
bitand     | delete       | long          | short             | union
bitor      | do           | mutable       | signed            | unsigned
bool       | **double**   | **namespace** | sizeof            | **using**
break      | dynamic_cast | new           | static            | virtual
case       | **else**     | noexcept      | static_assert     | void
catch      | enum         | not           | static_cast       | volatile
char       | explicit     | not_eq        | struct            | wchar_t
char16_t   | export       | nullptr       | switch            | while
char32_t   | extern       | operator      | template          | xor
class      | false        | or            | this              | xor_eq
compl      | **float**    | or_eq         | threadpool        | 


## Identifiers
  Programmer defined word to name: variables, constant, function, class, etc.
  
  Rules:
  
      * Identifiers are case sensative
      * Must start with an alpha character or an underscore
      * May consist *only* of alpha characters, digits, and underscores
    
  Naming Convention:
  
      * Start variables with lowercase
      * Start constants with upper case
      * Do not start personal variables with underscore
      * Make names meaningful

## Common Escape Sequences
Escape Sequence | Name | Description
----------------|------|------------
  `\n`  | newline         | causes cursor to next line for subsequent printing
  `endl`| newline         | causes cursor to next line for subsequent printing(quotes not needed)
  `\t`  | horizontal tab  | causes cursor to skip over to the next tab stop
  `\a`  | alarm           | causes computer to beep
  `\b`  | backspace       | causes the cursor to backup, or move left one position
  `\r`  | return          | causes the cursor to go to the beginning of the current line(NOT THE NEXT LINE)
  `\\`  | backslash       | causes a backslash to be printed
  `\'`  | single quote    | causes a single quotation mark to be printed
  `\"`  | double quote    | causes a double quotation mark to be printed

