function primeFactors(n){
    let d = 2;
    let arr = [];
    let retorno = ""
    while (n>=d) {
        if(n%d == 0){
            arr.push(d)
            n /= d
        }else{
            d++
        }
    }
    for(let i=1; i<=arr.length; i++){
        retorno += "(" + arr[i-1]
        let j = 1;
        for (i;arr[i]==arr[i-1]; i++) {
            j++
        }
        if(j!=1){
            retorno += "**" + j
            j = 1
        }
        retorno += ")"
    }
    return retorno
}
console.log("Inicio")
console.log(primeFactors(86240) + " return == '(2**5)(5)(7**2)(11)'")
console.log(primeFactors(7775460) + " return == '(2**2)(3**3)(5)(7)(11**2)(17)'")
console.log(primeFactors(7919) + " return == '(7919)'")
console.log(primeFactors(933555431) + " return == '(7537)(123863)'")
function primeFactors(n){
    for (var i=2, res="", f; i <= n; i++) {
      f=0;
      while (n%i == 0) { f++; n/=i }
      res += f ? "(" + ( f>1 ? i+"**"+f  : i ) +")" : ""
    }
    return res || "("+n+")"
  }
