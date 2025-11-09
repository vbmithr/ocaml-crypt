# crypt

A tiny binding for the [Unix crypt] function without external dependencies.

## Installation 

You can install latest released version of the library by OPAM package manager:
```console
$ opam install crypt
```

## Usage

```ocaml
# #require "crypt";;

# Crypt.crypt ~derivation:Md5 ~salt:"GUBv0xjJ" "hello";;
- : string = "$1$GUBv0xjJ$rQSvX8r6cT7H/NItzzVNQ/"
```


[Unix crypt]: https://man7.org/linux/man-pages/man3/crypt.3.html
