function sqInRect(lng, wdth){
    let rectangle = [], size = lng * wdth, actualSize = 0
    if(lng == wdth)
        return null
    while(actualSize < size){
        if(lng > wdth){
            rectangle.push(wdth)
            actualSize += wdth * wdth
            lng = (lng - wdth)
        }else{
            rectangle.push(lng)
            actualSize += lng * lng
            wdth = (wdth - lng)
        }
    }
    return rectangle
        
}

console.log(sqInRect(5, 5))
console.log(sqInRect(5, 3))
console.log(sqInRect(3, 5))
console.log(sqInRect(20, 14))