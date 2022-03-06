from distutils.core import setup, Extension

def main():
    setup(name="calc",
          version="1.0.1",
          description="Python interface for the fputs C library function",
          author="namer",
          author_email="your_email@gmail.com",
          ext_modules=[Extension("calc", ["calcmodule.c"])])

if __name__ == "__main__":
    main()
