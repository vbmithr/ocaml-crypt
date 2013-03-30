(* Binding to the crypt(3) function. Refer to the man page for more
   information *)
val crypt: string -> string -> string

(* [crypt_md5 key] generate a password in the MD5 format suitable for
   inclusion in /etc/shadow, autogenerating the salt. See
   http://www.gnu.org/software/libc/manual/html_node/crypt.html for
   the implementation. *)
val crypt_md5: string -> string
