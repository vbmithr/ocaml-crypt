all:
	dune build @install @runtest-crypt
.PHONY: clean
clean:
	dune clean
