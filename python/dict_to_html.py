from multimethod import multimethod
from pprint import pprint

"""
terminal : only string a terminal
non-terminal : only a dict is a non terminal.
if a same tag apprers more than once, just adda unique string to the key.
if there is any attribute, pass it using spacial key 'attr'
every non 'attr' key is a HTML tag!
That is all!.

Your write 100% python script to generate HTML doc.
Why: you need to learn nothing new except generic Python Language.
Compare this with any tool like mako or statit site generator.
"""

head = {
    'meta' : 'meta',
}

body = {
    'p unique1': {
        'attr': '',
        'p unique1': '',
        'p unique1': {
            'attr': 'id="1"',
            'content': 'hello world',
        },
    },
    'p unique1': 'this is a para', # literal content. no attribute
}

html_doc = {
    'html': {
        'head': head,
        'body': body,
    }
}

print(f'{pprint(html_doc)}')
