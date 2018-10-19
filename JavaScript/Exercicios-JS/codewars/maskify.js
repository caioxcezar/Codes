// return masked string
function maskify(cc) {
    if(cc.length > 3){
        let sharp = ''
        for (let i = 0; i < cc.length - 4; i++)
            sharp += '#'
        return (sharp + cc.substring(cc.length - 4))
    }
    return cc
}

cc = '4556364607935616'
console.log("Valor:             " + cc)
console.log("Resultado:         " + maskify(cc))
console.log("Resultado Correta: ############5616")

cc = '74567'
console.log("Valor:             " + cc)
console.log("Resultado:         " + maskify(cc))
console.log("Resultado Correta: #4567")

cc = '584'
console.log("Valor:             " + cc)
console.log("Resultado:         " + maskify(cc))
console.log("Resultado Correta: 584")