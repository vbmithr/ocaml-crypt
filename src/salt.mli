type t = string

val gen_base64 : ?seed:int array -> int -> t
(** [gen_base64 ?seed length] returns generated BASE64 string salt.

    @param seed
      If the seed is not passed, then get a random seed from the system. *)
