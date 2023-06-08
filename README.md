<h1 align="center">
	Get Next Line 📖
</h1>

<p align="center">
  <img src="https://i.imgur.com/U7aswVo.png" width="140" alt="grade" />
  <img src="https://i.imgur.com/Eg8m536.png" width="120" alt="m" />
</p>

---

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/PauloDavi/gnl_42?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/PauloDavi/gnl_42?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/PauloDavi/gnl_42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/PauloDavi/gnl_42?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/PauloDavi/gnl_42?color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> • </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> • </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

The design is intended to get the next line of an fd even if it reads a BUFFER_SIZE size of bypes at a time from the fd keeping it in memory between function calls with a static variable.

## 🛠️ Usage

> The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test othe cases.
Then simply run this command (change "<size>" with desired buffer size) :

```shell
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can also use this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
