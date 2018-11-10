function persistence(num) {
    let numStr = num.toString()
    let resultado = 0;
    while(numStr.length != 1){
        resultado++
        let soma = 1
        for(let i = 0; numStr.length > i; i++){
            soma *= parseInt(numStr.charAt(i))   
        }
        num = soma
        numStr = num.toString()
    }
    return resultado
}
if(persistence(39) === 3){
    console.log('is working')
} // because 3*9 = 27, 2*7 = 14, 1*4=4
 // and 4 has only one digit

if(persistence(999) === 4){
    console.log('is working')
} // because 9*9*9 = 729, 7*2*9 = 126,
  // 1*2*6 = 12, and finally 1*2 = 2

if(persistence(4) === 0){
    console.log('is working')
} // because 4 is already a one-digit number