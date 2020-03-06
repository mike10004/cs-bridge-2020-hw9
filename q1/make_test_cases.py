#!/usr/bin/env python3

import os
import re
from collections import defaultdict

_ALPHABET = "abcdefghijklmnopqrstuvwxyz"
assert len(_ALPHABET) == 26
assert len(_ALPHABET) == len(set(_ALPHABET))


def write_expected(inputline, ofile):
    print("Please enter a line of text:", file=ofile)
    print(inputline, file=ofile)
    counts = defaultdict(int)
    num_words = len(list(filter(lambda w: w, re.split(r'[^A-Za-z]+', inputline))))
    for ch in inputline:
        ch = ch.lower()
        if ch in _ALPHABET:
            counts[ch] += 1
    print(f"{num_words}\twords", file=ofile)
    for ch in sorted(counts.keys()):
        n = counts[ch]
        print(f"{n}\t{ch}", file=ofile)


def main():
    test_lines = [
        "This is so, so crazy.",
        "Make sure memory is URGENT.",
        "The quick, brown fox jumps over the lazy dog!",
        "Come quick--everything is broken?",
        "What if? There is more than one sentence. What do we do?"
    ]
    output_dir = os.path.join(os.getcwd(), 'test-cases')
    for case_id, line in enumerate(test_lines):
        case_id = f"{case_id + 1:02d}"
        input_pathname = os.path.join(output_dir, f"{case_id}-input.txt")
        with open(input_pathname, 'w') as ofile:
            print(line, file=ofile)
        expected_pathname = os.path.join(output_dir, f"{case_id}-expected.txt")
        with open(expected_pathname, 'w') as ofile:
            write_expected(line, ofile)
    return 0


if __name__ == '__main__':
    exit(main())
