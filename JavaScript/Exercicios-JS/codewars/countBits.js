var countBits = function(n) {
    return n.toString(2).split('').reduce((a, b) => Number(a) + Number(b))
}
console.log(countBits(0))//true 0
console.log(countBits(4))//true 1
console.log(countBits(7))//true 3
console.log(countBits(9))//true 2
console.log(countBits(10))//true 2