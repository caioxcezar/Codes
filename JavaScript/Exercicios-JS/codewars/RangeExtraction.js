function solution(list){
    let sequence = ''
    for(let i = 0; i<list.length; i++){
        let y = 1
        sequence+=list[i]
        while(list[i]+1 == list[i+1]){
            y++
            i++
        }
        if(y >= 3)
            sequence+='-'+list[i]
        else if(y != 1)
            sequence+=','+list[i]
        if(i<list.length-1)
            sequence+=','
    }
    return sequence
}

console.log(solution([-6, -3, -2, -1, 0, 1, 3, 4, 5, 7, 8, 9, 10, 11, 14, 15, 17, 18, 19, 20]))
// returns "-6,-3-1,3-5,7-11,14,15,17-20"