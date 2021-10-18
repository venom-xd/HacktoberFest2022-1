def printVertically(self, s: str) -> List[str]:
        l=s.split()
        n=len(max(l,key=len))
        i,j=0,0
        word=[""]*n
        while j<n:
          for i in range(0,len(l)):
            if j<len(l[i]):
              word[j]=word[j]+l[i][j]
            else:
              word[j]=word[j]+" "
          j=j+1
        return word
