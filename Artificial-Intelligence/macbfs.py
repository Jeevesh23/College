M,C=[int (x) for x in input("enter the number of missionarie and canibals : ").split(" ")]
B=int(input("enter boat capacity : "))
traversal=[]
visited=[]
par={}

def genmove(a):
   m=a[0]
   c=a[1]
   b=a[2]
   new=[]

   temp=[]
   for x in range(B+1):
      for y in range(B+1):
        if x+y<=B and x+y>0:
           new.append([x,y])
   
   if b==1:
    for i in new:
       temp.append((m-i[0],c-i[1],0))
    temp=[x for x in temp if x[0]>=0 and x[1]>=0]
   else:
    for i in new:
       temp.append((m+i[0],c+i[1],1))
    temp=[x for x in temp if x[0]<=M and x[1]<=C]
   temp=[x for x in temp if x not in visited]
  
   return temp

def isgood(x):
  m=x[0]
  c=x[1]

  if m==M or m==0 or m==c:
     return 1
  else:
     return 0

def mnc():
  start=(M,C,1)
  final=(0,0,0)
  open=[start]
  visited.append(start)

  while len(open)>0:
    a=open.pop()
    traversal.append(a)

    if a==final:
       break

    temp=genmove(a)
    temp=[x for x in temp if isgood(x)]

    for x in temp:
      par[x]=a

    visited.extend(temp)
    open=open+temp

  if final in traversal:
     cur=final
     path=[start]
     while cur!=start:
        path.insert(1,cur)
        cur=par[cur]
     print("path")
     for x in path:
        print(x,end=" " if x==final else "-->")
  else:
    print("solution not possible")


mnc()