var isPP = function(n){
    let p = 2, i = 1
    while(Math.pow(p, i) < n){
        while(Math.pow(p, i) < n)
            i++
        if(Math.pow(p, i) == n)
            return [p, i]
        i = 1
        p++
    }
    return null
}

console.log(isPP(4))// [2,2], "4 = 2^2"
console.log(isPP(9))// [3,2], "9 = 3^2"
console.log(isPP(5))// null, "5 isn't a perfect number"
console.log(isPP(81))// [3,4], "81 = 3^4"