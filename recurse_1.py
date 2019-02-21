#Recursion
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

#calculate sum of digit of numbers
def sumOfDigits(i):
    if i//10==0:
        return i
    return i%10 + sumOfDigits(i//10)
print('sum of digits of '+str(5867)+':',sumOfDigits(5867))


#given 2d list with some value can you reach from 0,0 to n,m by taking jump of position values

d = [[2,3,2,8],[4,1,23,8],[2,3,1,1]]
m = 3
n = 4
def reachAtEnd(d,i,j,m,n):
    if i>=m or j>=n:
        return False
    if i==m-1 and j==n-1:
        return True
    #print(i,j)
    return reachAtEnd(d,i+d[i][j],j,m,n) or reachAtEnd(d,i,j+d[i][j],m,n)
print('can i reach:',reachAtEnd(d,0,0,m,n))

#given 2d list with some value can you reach from 0,0 to n,m by taking jump of position values
#count total ways to reach at the end

d = [[2,3,2,8],[4,1,23,8],[2,3,1,1]]
m = 3
n = 4
def reachAtEnd(d,i,j,m,n):
    if i>=m or j>=n:
        return False
    if i==m-1 and j==n-1:
        return True
    #print(i,j)
    return reachAtEnd(d,i+d[i][j],j,m,n) + reachAtEnd(d,i,j+d[i][j],m,n)
print('total ways to reach:',reachAtEnd(d,0,0,m,n))

#given 2d list with some value can you reach from 0,0 to n,m by taking jump of position values
#some twist with problem is that if there is any block state at any position then you can not
#follow that path to reach over there..block state will be shown by -1
#d = [[2,3,-1,8],[4,1,23,8],[2,3,-1,1]]
d = [[1,-1,-1,1],[1,1,1,-1],[-1,-1,1,-1],[1,-1,1,1]]
m = 4
n = 4
def reachAtEnd(d,i,j,m,n):
    if i>=m or j>=n:
        return False
    if d[i][j]==-1:
        return False
    if i==m-1 and j==n-1:
        return True
    #print(i,j)
    x,y = 0,0
    if d[i][j]!=-1:
        x = reachAtEnd(d,i+d[i][j],j,m,n)
    if d[i][j]!=-1:
        y = reachAtEnd(d,i,j+d[i][j],m,n)
    return x or y 
print('can i reach:',reachAtEnd(d,0,0,m,n))


#total ways to reach with blocking state
d = [[1,-1,-1,1],[2,1,1,-1],[-1,1,1,-1],[1,1,1,1]]
m = 4
n = 4
def reachAtEnd(d,i,j,m,n):
    if i>=m or j>=n:
        return 0
    if d[i][j]==-1:
        return 0
    if i==m-1 and j==n-1:
        return 1
    #print(i,j)
    x,y = 0,0
    if d[i][j]!=-1:
        x = reachAtEnd(d,i+d[i][j],j,m,n)
    if d[i][j]!=-1:
        y = reachAtEnd(d,i,j+d[i][j],m,n)
    return x + y 
print('Total ways to reach:',reachAtEnd(d,0,0,m,n))
