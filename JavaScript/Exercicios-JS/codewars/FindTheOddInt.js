
function findOdd(A) {
    for(let i = 0; i<=A.length; i++){
        let odd = 0, int = A[i]
        for(let j = 0;j<=A.length; j++)
           if(A[j] === int)
               odd++
        if(odd%2)
            return A[i]
    }
}

function doTest(a, n) {
    console.log("A = ", a)
    console.log("n = ", n)
    console.log("odd: ", findOdd(a))
  }
    doTest([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5], 5)
    doTest([1,1,2,-2,5,2,4,4,-1,-2,5], -1)
    doTest([20,1,1,2,2,3,3,5,5,4,20,4,5], 5)
    doTest([10], 10)
    doTest([1,1,1,1,1,1,10,1,1,1,1], 10)
    doTest([5,4,3,2,1,5,4,3,2,10,10], 1)