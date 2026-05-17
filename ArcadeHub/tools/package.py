#!/usr/bin/env python3
from pathlib import Path
src=Path('output/ArcadeHub')
out=Path('output/ArcadeHub.nwa')
if src.exists():
    out.write_bytes(src.read_bytes())
    print('Packaged', out)
else:
    print('Missing binary')
