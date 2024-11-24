# Operator precedence Parser!!

This kind of Parser uses a table that defines precedence between pairs of terminals(commands).
As I said before, this parser is able to choose betwen multiple options and with it is able to parse ambigous gramar, because it has a precedence table, that tells him what to decide, without the need to backtracking as in top-parser.

Specifically on Minishell we'll work with comands and operators (&&, ||, |, ;).
So, this kind of parsing is able to understand which operations are needed to be done before others.

This operators have: Precedence (determined on a table we also need to give to the parser) and associativity( also a quantifier of precedence according to it's position on the string).

#### Non-deterministic
Explores multiple parsing paths because it can't always decide the correct rule with the current symbol alone. Meaning it needs to look ahead to decide. (Operator precedence parser is able to handle ambigous gramar).

	S → aS | bS | ε

#### What are the tools this parsing has?
	
		-> When to shift? Push current symbol to the stack
		-> When to reduce? Pop symbols off the stack to form a syntatic structure.
#### How is precedence defined?
		 - ( < ) ( top operator < next input symbol)
		 - ( > ) ( top operator > next input symbol)
		 - ( = ) ( they're equal)
#### What kinds can we find in Minishell Practie?

1.  **`|`** (pipe): Connects the output of one command to the input of another. This has relatively high precedence.
2.  **`&&`** (logical AND): Runs the second command only if the first succeeds.
3.  **`||`** (logical OR): Runs the second command only if the first fails.
4.  **`;`** (command separator): Runs commands in sequence, regardless of success/failure of previous commands.

#### The precedence order (from highest to lowest) generally is:

| Precedence | Operators                   | Description                | Associativity |
|------------|-----------------------------|----------------------------|---------------|
| 1          | `(` `)`                     | Grouping                   | N/A           |
| 2          | `|`                         | Pipe                       | Left          |
| 3          | `&&`, `||`                  | Logical AND, OR            | Left          |
| 4          | `<`, `>`, `>>`, `<<`        | Redirection                | Right         |
| 5          | `;`, `&`                    | Command terminator, background | Left      |

#### What are the parsing steps?

	- Initialize (empty stack with $ at the end)
	- Shift or Reduce
	- Repeat (until is fullly consumed, and only a single expresion is left on the stack with $ at the end)
	- END

#### Example applied to minishell
	- String -> [echo "Hello" && cat file.txt | grep "text" > output.txt || echo "Error"]
	I'll now walk through the stack at each major step:

1.  **`echo "Hello"`**:
    
    -   This is a command. Push it onto the stack as an operand.
    -   **Stack**: `["echo 'Hello'"]`
2.  **`&&`**:
    
    -   `&&` is a logical operator, which we push onto the stack.
    -   **Stack**: `["echo 'Hello'", "&&"]`
3.  **`cat file.txt`**:
    
    -   This is another command. Push it onto the stack as an operand for `&&`.
    -   **Stack**: `["echo 'Hello'", "&&", "cat file.txt"]`
4.  **`|`**:
    
    -   `|` (pipe) has a higher precedence than `&&`, so we handle it first.
    -   `cat file.txt` and the next command (`grep "text"`) will be linked by the `|` operator.
    -   Push `|` onto the stack.
    -   **Stack**: `["echo 'Hello'", "&&", ("cat file.txt", "|")]`
5.  **`grep "text"`**:
    
    -   This command follows `|`, so it is paired with `cat file.txt` through the pipe.
    -   **Stack**: `["echo 'Hello'", "&&", ("cat file.txt", "|", "grep 'text'")]`
6.  **`>`**:
    
    -   `>` has a higher precedence than `&&` and `|`, so it binds directly to `grep "text"`.
    -   Push `>` onto the stack.
    -   **Stack**: `["echo 'Hello'", "&&", ("cat file.txt", "|", "grep 'text'", ">")]`
7.  **`output.txt`**:
    
    -   `output.txt` is an argument for `>`, so it is added to form a complete redirection operation.
    -   **Stack**: `["echo 'Hello'", "&&", ("cat file.txt", "|", ("grep 'text'", ">", "output.txt"))]`
8.  **`||`**:
    
    -   `||` is a logical operator with a lower precedence than `&&`, so we can evaluate everything on the stack up to `&&` before adding `||`.
    -   **Stack** after processing `&&` and its operands: `[(("echo 'Hello'", "&&", ("cat file.txt", "|", ("grep 'text'", ">", "output.txt")))), "||"]`
9.  **`echo "Error"`**:
    
    -   Finally, add `echo "Error"` as the operand for `||`.
    -   **Stack**: `[("echo 'Hello'", "&&", ("cat file.txt", "|", ("grep 'text'", ">", "output.txt")), "||", "echo 'Error'")]`


Summary: 
	Basically what I understood is:
	It enters commands and operators into the stack as they are compared with other operators. When a operator with higher precedence is already inside the stack, the operation can be done.
It's a simpler and more compact way to do directly what we need for minishell.
Then, with this part being done, we have a string transformed into a structure that out machine can understand.