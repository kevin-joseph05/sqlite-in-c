# sqlite-in-c

## Scope

This is more of an exercise to understand how b-trees are used in sqlite's. We have a very limited set of commands (insert, select) and it's all held in memory. If I have time, I would like to explore deletion and updating.

## Decision log
**REPL**
I chose to read directly from stdin rather than use fgets or getline because I wanted a more granular understanding of what is going on. Also I forgot about fgets and that would have been a better implementation ngl 

