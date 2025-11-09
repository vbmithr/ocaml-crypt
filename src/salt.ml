type t = string

let base64 = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

(* Hacked from Random.State.make_self_init function. *)
external random_seed : unit -> int array = "caml_sys_random_seed"

let gen_base64 ?(seed = random_seed ()) n =
  let state = Random.State.make seed in
  String.init n @@ fun _ -> base64.[Random.State.int state 64]
