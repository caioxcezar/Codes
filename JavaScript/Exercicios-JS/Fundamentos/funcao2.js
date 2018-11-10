const imprimaSoma = function (a, b) {
    console.log(a+b)
}
imprimaSoma(2,3)

//armazenar uma função arrow em uma variavel
const soma = (a, b) => {
    return a + b
}
console.log(soma(2,3))

//forma implicita
const subtracao = (a, b) => a-b
console.log(subtracao(2,3))

const imprimir = a => console.log(a)
imprimir('Caio')