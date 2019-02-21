#print the numbers from 1 to n
def printNumber(i,n):
    if i>n:return
    print(i,end = ' ')
    printNumber(i+1,n)
n = 10
print("I'm tail recursion:")
printNumber(1,n)

#print number from 1 to n in reverse order
def printReverseOrder(i,n):
    if i>n:return
    printReverseOrder(i+1,n)
    print(i,end =' ')
print("\nI'm non tail recursion because somthing else remaining after me:")
printReverseOrder(1,n)

#sum from 1 to n
def sumFrom1ton(i,n):
    if i>n:return 0
    return i+sumFrom1ton(i+1,n)
print('\nSum from 1 to n('+str(n)+'):',sumFrom1ton(1,10))

#given a list find max
def Maxi(a,i,n):
    if i==n:return -1
    return max(a[i],Maxi(a,i+1,n))
a = [4,3,6,8,1,7,5]
print("max of a is:",Maxi(a,0,len(a)))

#calculate GCD
def Gcd(p,q):
    if p==0:return q
    return Gcd(p%q,p)
p = 20
q = 15
#keep in mind p should always be greater than or equal to q
print("GCD of "+str(p)+' and '+str(q)+":",Gcd(p,q))
