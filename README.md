# Polarize
A simple hash function. I'm not sure if it's secure, but i just wanted to share it.
You can use the function in python with `plrz.hash`, and use it in c linking it against the same library, using the symbol `char * pzash(char *str)`.
#Requirements
If you won't be using the hash function in python, then you don't strictly require python after removing every reference, So: `C Compiler & Python (Optional)`
#How to compile
You can compile the library using `(compiler) plrz.c -o plrz.so -shared -fPIC [$(python3-config --cflags --ldflags) for python]`
