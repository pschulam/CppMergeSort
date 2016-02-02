"""Generate a list of random words.

Usage: genwords.py NUM SEED

"""

import random

from docopt import docopt


_WORDS = '/usr/share/dict/words'


def main(num_words, seed):
    """Entry point of the script."""
    random.seed(seed)
    with open(_WORDS) as f:
        words = [l.strip() for l in f]

    random.shuffle(words)

    for word in words[:num_words]:
        print(word)


if __name__ == '__main__':
    ARGS = docopt(__doc__)
    main(int(ARGS['NUM']), int(ARGS['SEED']))
