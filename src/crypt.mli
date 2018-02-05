val crypt: string -> string -> string -> int
(** [crypt buf key salt] writes the result of crypt(3)([key], [salt])
    in [buf], and returns its length. *)

val crypt_md5: string -> string -> int
(** [crypt_md5 buf key] write a password in the MD5 format suitable
    for inclusion in /etc/shadow, autogenerating the salt, if [buf],
    and returns its length. See
    http://www.gnu.org/software/libc/manual/html_node/crypt.html for
    the implementation. *)
