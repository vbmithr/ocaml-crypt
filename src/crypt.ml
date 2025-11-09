module Ffi = struct
  external crypt : string -> string -> string = "ml_crypt"
  external crypt_md5 : string -> string = "ml_crypt_md5"
end
