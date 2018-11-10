/*
comp(a, b) returns true
because in b 121 is the square of 11,
 14641 is the square of 121,
 20736 the square of 144, 
 361 the square of 19,
 25921 the square of 161,
 and so on. It gets obvious if we write b's elements in terms of squares:
*/
function comp(array1, array2){
    if(Array.isArray(array1) == false || Array.isArray(array2) == false)
        return false
    array1.sort(function(a, b){return a - b})
    array2.sort(function(a, b){return a - b})

    for (let i = 0; i < array2.length; i++){
        let check
            (array2[i] == (array1[i]*array1[i]) ? check = true : check = false)
        if(!check)
            return false
    }
    return true
}

a1 = [121, 144, 19, 161, 19, 144, 19, 11]
a2 = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
console.log(comp(a1, a2)) // true

b1 = [121, 144, 19, 161, 19, 144, 19, 11]  
b2 = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
console.log(comp(b1, b2)) // false
