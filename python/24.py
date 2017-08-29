print "Let's practice eventhing."

print 'you\'d need to know \' bout escape with \\ that do \n newlinws and \t tabs'

poem = """
\t the dog is you 
I am a student.
cannot disscern \n the needs of love

\n\twhere there is none.
"""


print '--------------------------------'
print poem
print '--------------------------------'

five = 10 - 2 + 3 - 6
print 'The should be five : %s' % five

def secret_formula(started):
    je = started * 500
    ja = je / 1000
    cr = ja / 10
    return je, ja, cr

st = 10000
be, ja, cr = secret_formula(st)

print "we'd have %d beans, %d  %d" % (be, ja, cr)

st = st / 10
print "%d %d %d" %secret_formula(st)
