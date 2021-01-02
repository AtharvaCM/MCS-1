# MatrixIO

# readFunction
def readMatrix(fname):
    fn = open(fname,"r")
    st = (fn.read()).split("\n")
    arr = []
    for i in st:
        if(len(i) != 0):
            arr.append(i.split(" ")) 
    fn.close()
    return arr

#WriteInverseMatrix
def writeInverse(fname,data):
    fn = open(fname,"w")
    n = len(data)
    m = len(data[0])
    for i in range(m):
        for j in range(n):
#                print(data[j][i],end=" ")
                fn.write(data[j][i]+" ")
        fn.write("\n")
    fn.close()