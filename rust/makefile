# All the rust!
RUST_SRC=$(wildcard *.rs)
RUST_NAMES=$(RUST_SRC:.rs=)
BUILD_NAMES=$(addprefix build/, $(RUST_NAMES))
TEST_NAMES=$(addprefix test/, $(RUST_NAMES))

RUST_COMPILED_DIR="build/"
RUST_TEST_DIR="test/"


all: $(RUST_COMPILED_DIR) $(RUST_TEST_DIR) \
	build/gpio \
	test/gpio

$(RUST_COMPILED_DIR):
	mkdir -p $(RUST_COMPILED_DIR)

$(RUST_TEST_DIR):
	mkdir -p $(RUST_TEST_DIR)

$(BUILD_NAMES): build/%: %.rs
	rustc --out-dir $(RUST_COMPILED_DIR) $<

$(TEST_NAMES): test/%: %.rs
	rustc --out-dir $(RUST_TEST_DIR) $<

clean:
	rm -rf $(RUST_COMPILED_DIR) $(RUST_TEST_DIR)
