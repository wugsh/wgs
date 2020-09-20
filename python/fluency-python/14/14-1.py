import re
import reprlib
from collections import abc

RE_WORD = re.compile('\w+')


class Sentence:
    
    def __init__(self, text):
        self.text = text
        self.words = RE_WORD.findall(text)

    def __getitem__(self, index):
        return self.words[index]

    #def __iter__(self, index):
    #    print("****")
    #    return self.words[index]

    def __len__(self):
        return len(self.words)

    def __repr__(self):
        return 'Sentence(%s)' % reprlib.repr(self.text)


if __name__ == '__main__':
    s = Sentence('"The time has come," the Walrus said,')   
    #print(word for word in s)
    #for word in s:
    #    print(word)
    #print(list(s))
    print(s.__len__())
    print(s[0])
    print(iter(s))
    print(isinstance(s, abc.Iterable))