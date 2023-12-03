## permutations

Simple command-line program that generates all permutations of a given string or a list of words. <br>
It will happily generate duplicates if there are duplicates in the input, pipe to ```sort -u``` if you want to get rid of them.

```
Features:
- Generate all permutations of a given string.
- Generate all permutations of a list of words.
- There is nothing more to it.


Usage:
- ./permutations <[WORD] | [WORD_ONE] [WORD_TWO] [...]>

Building:
- Compile with any C compiler.
``````

### Examples:
```./permutations 123```

Output:
```
123
132
213
231
312
321
```

```./permutations 1 2 3```

Output:
```
1, 2, 3
1, 3, 2
2, 1, 3
2, 3, 1
3, 1, 2
3, 2, 1
```
