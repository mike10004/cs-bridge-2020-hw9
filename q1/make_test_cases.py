#!/usr/bin/env python3

import os
import re
from collections import defaultdict

_ALPHABET = "abcdefghijklmnopqrstuvwxyz"
assert len(_ALPHABET) == 26
assert len(_ALPHABET) == len(set(_ALPHABET))


def write_expected(inputline, num_words_check, ofile):
    print("Please enter a line of text:", file=ofile)
    print(inputline, file=ofile)
    counts = defaultdict(int)
    num_words = len(list(filter(lambda w: w, re.split(r'[^A-Za-z]+', inputline))))
    assert num_words_check == num_words
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
        ("This is so, so crazy.", 5),
        ("Make sure memory is URGENT.", 5),
        ("The quick, brown fox jumps over the lazy dog!", 9),
        ("Come quick--everything is broken?", 5),
        ("What if? There is more than one sentence. What do we do?", 12),
        ("  x  * ", 1),
        ("  Let us see what happens now.  ?./* ", 6),
        ("degenerate...", 1),
        ("!@# $%^ &*()", 0),
        ("This,is,a,sentence,delimited,entirely,by,commas,", 8),
        ("Multiple spaces     between...words", 4),
    ]
    output_dir = os.path.join(os.getcwd(), 'test-cases')
    for case_id, linetuple in enumerate(test_lines):
        line, num_words_check = linetuple
        case_id = f"{case_id + 1:02d}"
        input_pathname = os.path.join(output_dir, f"{case_id}-input.txt")
        with open(input_pathname, 'w') as ofile:
            print(line, file=ofile)
        expected_pathname = os.path.join(output_dir, f"{case_id}-expected.txt")
        with open(expected_pathname, 'w') as ofile:
            write_expected(line, num_words_check, ofile)
    return 0


if __name__ == '__main__':
    exit(main())
