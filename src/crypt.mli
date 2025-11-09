(** A tiny binding for the Unix crypt function. *)

type key_derivation =
  | Md5
  | Sha256
  | Sha512  (** The glibc2's additional encryption algorithms. *)

val crypt : ?derivation:key_derivation -> salt:string -> string -> string
(** [crypt ?derivation ~salt key] is the password encryption function. It is
    based on the Data Encryption Standard algorithm with variations intended
    (among other things) to discourage use of hardware implementations of a key
    search.

    @param salt salt is a two-character string chosen from the set [a-zA-Z0-9./]
    @param key key is a user's typed password

    @return encrypted password

    @raise Failure if hashing fails *)
