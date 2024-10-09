# ICPC Cheatsheet

A LaTeX project containing essential algorithms, data structures, and problem-solving techniques for ICPC contests.

## Getting started

To build the LaTeX document, you'll need a latex distribution.
On debian-based distros, you can run this to install all you nned:

```bash
sudo apt install texlive texlive-latex-extra texlive-fonts-recommended texlive-science
```

## Build the document

To compile the LaTeX source code into a PDF, run the following command:

```bash
pdflatex -output-directory=.build/pdf -jobname=cheatsheet template.tex
```

## Project Structure

The repository is organized as follows:

- `/src` - LaTeX code of the document
- `/code` - C++ code included in the document
- `/template.tex` - Root of the LaTeX document, contains various formatting settings
