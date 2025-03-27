#input
M,C=[int(x) for x in input("Enter the number of missionaries and cannibals : ").split(" ")]
B=int(input("Enter the capacity of the boat : "))

traversal=[]  
visited=[]  #closed
par={}      #parent dictionary


def genmove(a):
  m=a[0]
  c=a[1]
  b=a[2]
  new=[]
  
  templist=[]
  for x in range(B+1): #0->B missionaries 
    for y in range(B+1):  #0->B cannibals
      if x+y<=B and x+y>0:    #check with boat limits
        new.append([x,y])     #adding number of people on boat for next round from state a-> (3,3,1)  => (1,1) 2,0 
  
  if b==1:    #if boat is on left side
    for i in new: #i->(p,q)
      templist.append((m-i[0],c-i[1],0))    #adding the next states according to the "new" list from state a -> (3,3,1)=> (3,1,0)
    templist=[x for x in templist if x[0]>=0 and x[1]>=0]   #all new states should not have negative numbers 

  #same steps if boat is on right side; except state[3]=1 i.e. side of boat is changed to left
  else:
    for i in new:
      templist.append((m+i[0],c+i[1],1))
    templist=[x for x in templist if x[0]<=M and x[1]<=C]
  templist=[x for x in templist if x not in visited]

  return templist


def isgood(x):
  m=x[0]
  c=x[1]

  if m==M or m==0 or m==c:
    return 1
  else:
    return 0

def mnc():
  start=(M,C,1)     #start state
  desired=(0,0,0)   #final state
  open=[start]     #open list
  visited.append(start)   #closed list
  
  while len(open)>0:   #while open list is not empty
    a=open.pop(0)      #pop
    traversal.append(a) #traversal list; tracks traversal

    if a==desired:       #if desired state is found exit loop
      break

    templist=genmove(a)    #generate next set of moves   
    templist=[x for x in templist if isgood(x)]   #check if missionaries are safe in the particular state

    #assign parent to every node
    for x in templist:
      par[x]=a

    visited.extend(templist)
    open=templist+open    # inserting at the front; depth first

  if desired in traversal:
    cur=desired
    path=[start]
    while cur!=start:
      path.insert(1,cur)
      cur=par[cur]
    print("Path : ")
    for x in path:
      print(x,end="\n" if x==desired else " -> ")
  else:
    print("Solution not possible")


mnc()