# minishell

Recoding our own little bash

### Usage
``make`` create ``minishell``  
``make bonus`` create ``minishell`` with additional features  
``./minishell``

### Main features
- Minishell runs executables from an absolute, relative or environment PATH (/bin/ls or ls), including arguments or options.
- A few of the functions are "built-in", meaning we don't call the executable. It's the case for echo, pwd, cd, env, export, unset and exit.
- You can separate commands with ;
- ' and " work the same as bash, except for multiline commands.
- Redirections > >> < and pipes | work the same as bash  except for file descriptor aggregation.
- Environment variables are handled, like $HOME, including the return code $?.
- Finally, you can use Ctrl-C to interrupt and Ctrl-\ to quit a program, as well as Ctrl-D to throw an EOF, same as in bash.

### Additional features

- wilcard * like in bash
- Redirection <<
- Сommand history
- &&, || like in bash
- Line editing:
  - edit the line where the cursor is located
  - move the cursor left and right
  - use up and down arrows to navigate through the command history
  - Move directly by word towards the left or the right using ctrl+LEFT and ctrl+RIGHT.
  - Cut(ctrl+u), copy(ctrl+t), and/or paste(ctrl+y) all characters from the beginning of the line to the cursor position(linux only).
  - Go directly to the beginning or the end of a line by pressing home and end.  
