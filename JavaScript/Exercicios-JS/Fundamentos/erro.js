
function tratarErro(erro){
    // throw new Error('...')
    // throw 10
    // throw true
    // throw 'messagem'
    throw {
        nome: erro.name,
        msg: erro.message,
        date: new Date
    }
}

function imprimirNomeGritado(obj){
    console.log(obj.name.toUpperCase() + '!!!')
}

const obj = {nome: 'Roberto'}
try {
    imprimirNomeGritado(obj)
} catch (error) {
    tratarErro(error)
} finally {
    console.log('final')
}