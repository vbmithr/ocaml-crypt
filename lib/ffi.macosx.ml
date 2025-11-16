external crypt : string -> string -> string = "ml_crypt"
external encrypt : bytes -> int -> unit = "ml_macosx_encrypt"
external setkey : string -> unit = "ml_macosx_setkey"

(** [crypt key salt] - crypt *)
let crypt =
  let mutex = Mutex.create () in
  fun[@inline] key opts ->
    (* Do not use Mutex.protect to support older versions until the LTS release. *)
    Fun.protect
      (fun () ->
        Mutex.lock mutex;
        crypt key opts)
      ~finally:(fun () -> Mutex.unlock mutex)
