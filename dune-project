(lang dune 3.6)

(name crypt)

(version 2.0)

(generate_opam_files true)

(authors
 "Vincent Bernardoff <vb@luminar.eu.org>"
 "Mikhail Lopatin <dx3mod@bk.ru>")

(maintainers
 "Vincent Bernardoff <vb@luminar.eu.org>"
 "Mikhail Lopatin <dx3mod@bk.ru>")

(license ISC)

(source
 (github vbmithr/ocaml-crypt))

(package
 (name crypt)
 (synopsis "A tiny binding for the Unix crypt function")
 (description "A tiny binding for the Unix crypt function")
 (depends ocaml dune-configurator))
