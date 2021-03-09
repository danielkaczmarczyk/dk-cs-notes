# Various

using the system pastebin register for copying:

```
"*y "*p
```
[link](https://stackoverflow.com/questions/3961859/how-to-copy-to-clipboard-in-vim)

# Tip 1

`.` repeats the last action
`>G` indents until the end of file

# Tip 2

`A` is just `$a`

# Tip 3

`f+` finds next plus
`s` removes character and places cursor there in insert mode. equivalent to `xi`
`;` moves to the next instance of whatever `f` found last time

# Tip 4

Every vim repeatable action has a reverse button.

# Tip 5

`*` executes a search for the word under cursor. you can navigate then using your usual `n | N`.

# Tip 6

--

# Tip 7

--

# Tip 8

Chunk your undos

The `u` key rigters the undo command, which reverts the most recent change. Remember that the `u` key will undo the last _change_, and a change counts as everything we type or delete between the time of entering insert mode to time when we return to normal mode. 

Beware that moving around in insert mode resets the change. ( Only possible with arrow keys )


