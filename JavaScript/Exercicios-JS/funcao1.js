//função sem retorno
function imprimirSoma(a,b){
    console.log(a+b)
}
console.log(2+3)
console.log(7)
console.log(5+3+1)
console.log()

//função com retorno
//b tem valor padrão de 1
function soma(a, b=1){
    return a+b
}
console.log(soma(2+3))
console.log(soma(1))