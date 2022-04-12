from heapq import heappush, heappop, heapify
from collections import defaultdict

def encode(symb2freq):
    """Huffman encode the given dict mapping symbols to weights"""
    heap = [[wt, [sym, ""]] for sym, wt in symb2freq.items()]
    heapify(heap)
    while len(heap) > 1:
        lo = heappop(heap)
        hi = heappop(heap)
        for pair in lo[1:]:
            pair[1] = '0' + pair[1]
        for pair in hi[1:]:
            pair[1] = '1' + pair[1]
        heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])
    return sorted(heappop(heap)[1:], key=lambda p: (len(p[-1]), p))
txt = r''' 	0.2100000000
a	0.0582200000
b	0.0106500000
c	0.0191700000
d	0.0333700000
e	0.0923000000
f	0.0156200000
g	0.0142000000
h	0.0440200000
i	0.0489900000
j	0.0011360000
k	0.0057510000
l	0.0284000000
m	0.0191700000
n	0.0475700000
o	0.0553800000
p	0.0134900000
q	0.0007810000
r	0.0418900000
s	0.0440200000
t	0.0681600000
u	0.0191700000
v	0.0068870000
w	0.0170400000
x	0.0010650000
y	0.0142000000
z	0.0005538000
A	0.0024600000
B	0.0004500000
C	0.0008100000
D	0.0014100000
E	0.0039000000
F	0.0006600000
G	0.0006000000
H	0.0018600000
I	0.0020700000
J	0.0000480000
K	0.0002430000
L	0.0012000000
M	0.0008100000
N	0.0020100000
O	0.0023400000
P	0.0005700000
Q	0.0000330000
R	0.0017700000
S	0.0018600000
T	0.0028800000
U	0.0008100000
V	0.0002910000
W	0.0007200000
X	0.0000450000
Y	0.0006000000
Z	0.0000234000
.	0.0109879808
,	0.0103653846
;	0.0005384615
:	0.0005721154
!	0.0005552885
?	0.0009423077
’	0.0040889423
"	0.0044927885
-	0.0025745192
~	0.0001393483
`	0.0001393483
@	0.0001393483
#	0.0001393483
$	0.0001393483
%	0.0001393483
^	0.0001393483
&	0.0001393483
*	0.0001393483
(	0.0001393483
)	0.0001393483
_	0.0001393483
+	0.0001393483
=	0.0001393483
{	0.0001393483
}	0.0001393483
[	0.0001393483
]	0.0001393483
|	0.0001393483
\	0.0001393483
>	0.0001393483
<	0.0001393483
/	0.0001393483'''
symb2freq = {};
for row in txt.split("\n"):
    el = row.split("\t");
    symb2freq[el[0]] = float(el[1]);


huff = encode(symb2freq)
print("Symbol\tWeight\tHuffman Code")
for p in huff:
    print("%s\t%s\t%s" % (p[0], symb2freq[p[0]], p[1]))
