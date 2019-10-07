def build(a,b,node,start,end):
    if start==end:
        print(node)
        b[node] = a[start]
    else:
        mid = (start+end)//2
        build(a,b,2*node+1,start,mid)
        build(a,b,2*node+2,mid+1,end)
        b[node] = min(b[2*node+1],b[2*node+2])
def query(b,node,start,end,l,r):
    if start>r or end<l:
        return 10000000
    if start>=l and end<=r:
        return b[node]
    mid = (start+end)//2
    q1 = query(b,2*node+1,start,mid,l,r)
    q2 = query(b,2*node+2,mid+1,end,l,r)
    return min(q1,q2)
def update(a,b,node,start,end,indx,val):
    if start==end:
        a[indx] = val
        b[node] = val
    else:
        mid = (start+end)//2
        if start<=indx and indx<=mid:
            update(a,b,2*node+1,start,mid,indx,val)
        else:
            update(a,b,2*node+2,mid+1,end,indx,val)
        b[node] = min(b[2*node+1],b[2*node+2])
a = [1,2,3,4,5,6,7]
b = [10000000 for i in range(len(a)*2)]
build(a,b,0,0,len(a)-1)
print(b)
print(query(b,0,0,len(a)-1,2,5))
update(a,b,0,0,len(a)-1,3,-5)
print(a)
print(b)
