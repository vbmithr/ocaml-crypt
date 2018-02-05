all:
	jbuilder build @install @runtest-crypt
.PHONY: clean
clean:
	rm -rf _build
