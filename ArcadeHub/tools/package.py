#!/usr/bin/env python3
"""Create a real NumWorks .nwa package.

This script intentionally refuses to create a fake .nwa by renaming/copying a desktop
binary. A valid .nwa must be produced by the official NumWorks packaging toolchain so
that metadata (name, icon, size) is present in the installer.
"""
from pathlib import Path
import shutil
import subprocess
import sys


def main() -> int:
    if len(sys.argv) != 3:
        print("Usage: tools/package.py <input-elf> <output-nwa>")
        return 2

    input_elf = Path(sys.argv[1])
    output_nwa = Path(sys.argv[2])

    if not input_elf.exists():
        print(f"[ERROR] Missing input binary: {input_elf}")
        return 1

    nwbuild = shutil.which("nwbuild")
    if not nwbuild:
        print("[ERROR] nwbuild not found in PATH.")
        print("        Refusing to generate fake .nwa from desktop binary.")
        print("        Install NumWorks tooling and build/package with nwbuild.")
        return 1

    output_nwa.parent.mkdir(parents=True, exist_ok=True)
    cmd = [nwbuild, str(input_elf), "-o", str(output_nwa)]
    result = subprocess.run(cmd, check=False)
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
