module Ffi = struct
  external crypt : string -> string -> string = "ml_crypt"
end

type key_derivation = Md5 | Sha256 | Sha512

let pp_key_derivation fmt derivation =
  Format.pp_print_string fmt
  @@ match derivation with Md5 -> "1" | Sha256 -> "5" | Sha512 -> "6"

let crypt ?derivation ?salt key =
  let salt = match salt with None -> Salt.gen_base64 9 | Some salt -> salt in

  match derivation with
  | None -> Ffi.crypt key salt
  | Some derivation ->
      Format.asprintf "$%a$%s" pp_key_derivation derivation salt
      |> Ffi.crypt key

module Salt = Salt
