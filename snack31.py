a=[ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
li={2: [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50], 3: [3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48], 4: [], 5: [5, 10, 15, 20, 25, 30, 35, 40, 45, 50], 6: [], 7: [7, 14, 21, 28, 35, 42, 49], 8: [], 9: [], 10: [], 11: [11, 22, 33, 44], 12: [], 13: [13, 26, 39], 14: [], 15: [], 16: [], 17: [17, 34], 18: [], 19: [19, 38], 20: [], 21: [], 22: [], 23: [23, 46], 24: [], 25: [], 26: [], 27: [], 28: [], 29: [29], 30: [], 31: [31], 32: [], 33: [], 34: [], 35: [], 36: [], 37: [37], 38: [], 39: [], 40: [], 41: [41], 42: [], 43: [43], 44: [], 45: [], 46: [], 47: [47], 48: [], 49: [], 50: []}
b={2: [2], 3: [3], 4: [2], 5: [5], 6: [2, 3], 7: [7], 8: [2], 9: [3], 10: [2, 5], 11: [11], 12: [2, 3], 13: [13], 14: [2, 7], 15: [3, 5], 16: [2], 17: [17], 18: [2, 3], 19: [19], 20: [2, 5], 21: [3, 7], 22: [2, 11], 23: [23], 24: [2, 3], 25: [5], 26: [2, 13], 27: [3], 28: [2, 7], 29: [29], 30: [2, 3, 5], 31: [31], 32: [2], 33: [3, 11], 34: [2, 17], 35: [5, 7], 36: [2, 3], 37: [37], 38: [2, 19], 39: [3, 13], 40: [2, 5], 41: [41], 42: [2, 3, 7], 43: [43], 44: [2, 11], 45: [3, 5], 46: [2, 23], 47: [47], 48: [2, 3], 49: [7], 50: [2, 5]}
t=int(input())
while t>0:
    ans=0
    c={}
    count={}
    for i in range(2,51):
        count[i]=0
    for i in a:
        c[i]=0
    n=int(input())
    arr= list(map(int,input().split()))
    if len(arr)==1:
        print(ans)
        for i in arr:
            print(i,end=' ')
        print()
        t=t-1
        continue
    for i in arr:
        for j in b[i]:
            c[j]=c[j]+1
    d=[]
    for i in arr:
        for j in a:
            if i!=j:
                e=j
    for i in a:
        if c[i]==n:
            arr[0]=e
            ans=1
        if c[i]>0:
            d.append(i)
    if ans==1:
        print(ans)
        for i in arr:
            print(i,end=' ')
        print()
        t=t-1
        continue
    #print(d)
    for i in d:
        for j in li[i]:
            count[j]=count[j]+1
    
    #print(count)
    for i in range(2,51):
        if ans==1:
            break
        if count[i]==len(d) and i in arr:
            for j in range(len(arr)):
                if arr[j]==i:
                    arr[j]=e
                    ans=1
                    break        
    print(ans)
    for i in arr:
        print(i,end=' ')
    print()
    t=t-1
            
            
