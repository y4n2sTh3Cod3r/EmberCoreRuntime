# build.py
import os
from glob import glob
from setuptools import setup, Extension
from Cython.Build import cythonize
import subprocess

# Collect all pyx modules under src/
def build():
    pyx_files = glob(os.path.join("src", "**", "*.pyx"), recursive=True)

    # Create one Extension per file
    exts = [
        Extension(
            "runtime",
            sources=pyx_files,
            language="c++",
            include_dirs=["src"],
        )
    ]

    setup(
        name="embercore_runtime",
        version="0.1",
        ext_modules=cythonize(
            exts,
            compiler_directives={"language_level": "3"},
            annotate=False
        ),
        zip_safe=False,
    )

    genProc = subprocess.Popen(
        "cd EmberCoreRuntime && stubgen",
        shell=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )

    genProc.wait()

build()