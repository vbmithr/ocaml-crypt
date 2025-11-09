# crypt

A tiny binding for the [Unix crypt] function provides a high-level interface.

* [API references](https://ocaml.org/p/crypt/latest/doc/index.html)

## Installation 

You can install the latest released version of the library using the OPAM package manager.
```console
$ opam install crypt
```

Alternatively, you can pin the development (upstream) version.
```console
$ opam pin crypt.dev https://github.com/vbmithr/ocaml-crypt.git
```

## Quick Start

The `Crypt` module contains only one function, `crypt`, with several parameters.

```ocaml
# #require "crypt";;

# Crypt.crypt ~salt:"GUBv0xjJ" "hello";;
- : string = "GUpsIDCLVu8AY"

# Crypt.crypt ~derivation:Md5 ~salt:"GUBv0xjJ" "hello";;
- : string = "$1$GUBv0xjJ$rQSvX8r6cT7H/NItzzVNQ/"
```

If you don't provide any salt, a new salt will be generated every time the function is called.

```ocaml
# Crypt.crypt "hello";;
- : string = "QwD.wi5nLT/0s"

# Crypt.crypt "hello";;
- : string = "MYM.5hv5Lk2Mg"
```

For a deterministic generation, you should use one salt that you can generate using
the `Crypt.Salt` module or another external module.

```ocaml
# let salt = Crypt.Salt.gen_base64 9;;
val salt : string = "dHiPl3q99"

# Crypt.crypt ~salt "hello";;
- : string = "dHDdeFGUWcGyQ"
```

## References

- [Wikipedia article: crypt (Unix)](https://en.wikipedia.org/wiki/Crypt_(Unix))
- [crypt(3)](https://man7.org/linux/man-pages/man3/crypt.3.html)

## License

The project is licensed under the [ISC License](./LICENSE), which allows for all permissions. 
Just use it and enjoy yourself without fear.

[Unix crypt]: https://man7.org/linux/man-pages/man3/crypt.3.html
