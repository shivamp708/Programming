n = int(input())
if n%2==0:
    for i in range(n//2):
        print('@')
    s = 0
    for i in range(n//2+1,n+2):
        if i>=n:
            print('@'+s*' '+n*'*'+((n**2-n+1)-s-n)*' '+'@')
        else:
            print('@'+s*' '+n*'*')
        s+=n-1
    for i in range(n//2-1):
        print((s+1)*' '+n*'*'+((n**2-n+1)-s-n)*' '+'@')
        s+=n-1
    for i in range(n//2):
        print((n**2-n+2)*' '+'@')


""" output
  n = 4
@
@
@****
@   ****      @
@      ****   @
          ****@
              @
              @
"""
