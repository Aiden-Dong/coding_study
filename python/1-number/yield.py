def iterator_res(n):
    for it in range(n):
        yield it**2;

for i in iterator_res(5):
    print i;


res = iterator_res(10);

print res.next();
print res.next();
