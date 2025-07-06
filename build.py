# build.py
import os
from glob import glob
from setuptools import setup, Extension
from Cython.Build import cythonize

# Collect all pyx modules under src/
pyx_files = glob(os.path.join("src", "**", "*.pyx"), recursive=True)

# Create one Extension per file
exts = [
    Extension(
        os.path.splitext(os.path.relpath(path, "src"))[0].replace(os.sep, "."),
        [path],
        language="c++",
        include_dirs=["src"],
    )
    for path in pyx_files
]

setup(
    name="embercore_runtime",
    version="0.1",
    ext_modules=cythonize(
        exts,
        compiler_directives={"language_level": "3"},
        annotate=False,
    ),
    zip_safe=False,
)