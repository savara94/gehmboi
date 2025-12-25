.PHONY: init help build run clean bootstrap check-format format-inline

# Default variables (can be overridden via command line)
CMAKE ?= cmake
CMAKE_MAKE_PROGRAM ?= ninja
C_COMPILER ?= gcc
CXX_COMPILER ?= g++
PRESET ?= vcpkg
BUILD_DIR ?= build
RUN_BIN ?= gehmboi
RUN_CMD := ./$(BUILD_DIR)/$(RUN_BIN)
VCPKG_DIR ?= vcpkg
VCPKG_ROOT := $(abspath $(VCPKG_DIR))
export VCPKG_ROOT

CMAKE_ARGS := -DCMAKE_MAKE_PROGRAM=$(CMAKE_MAKE_PROGRAM) -DCMAKE_C_COMPILER=$(C_COMPILER) -DCMAKE_CXX_COMPILER=$(CXX_COMPILER) --preset=$(PRESET)

BASE ?= HEAD

init:
	@printf "Running: $(CMAKE) $(CMAKE_ARGS)\n"
	@$(CMAKE) $(CMAKE_ARGS)

build:
	@printf "Running: $(CMAKE) --build $(BUILD_DIR)\n"
	@$(CMAKE) --build $(BUILD_DIR)

run:
	@printf "Running: $(RUN_CMD)\n"
	@$(RUN_CMD)

clean:
	@printf "Removing: $(BUILD_DIR)\n"
	@rm -rf $(BUILD_DIR)

bootstrap:
	@printf "Cloning vcpkg into: $(VCPKG_ROOT)\n"
	@git clone --depth 1 git@github.com:microsoft/vcpkg.git $(VCPKG_ROOT)

check-format:
	@printf "Running clang-format check for commit: $(BASE)\n"
	@git clang-format --style=file --commit $(BASE) --diff

format-inline:
	@printf "Applying clang-format for commit: $(BASE)\n"
	@git clang-format --style=file --commit $(BASE)

help:
	@printf "Usage: make init [CMAKE=cmake] [CMAKE_MAKE_PROGRAM=ninja] [C_COMPILER=gcc] [CXX_COMPILER=g++] [PRESET=default]\n"
	@printf "       make build [BUILD_DIR=build]\n"
	@printf "       make run [BUILD_DIR=build] [RUN_BIN=gehmboi]\n"
	@printf "       make clean [BUILD_DIR=build]    # remove build directory\n"
	@printf "       make bootstrap [VCPKG_DIR=vcpkg] # clone vcpkg repo into directory\n"
	@printf "       make check-format [BASE=<sha>]  # run git clang-format --commit <sha> --diff (defaults to HEAD)\n"
	@printf "       make format-inline [BASE=<sha>]   # apply git clang-format --commit <sha> -f (defaults to HEAD)\n"

