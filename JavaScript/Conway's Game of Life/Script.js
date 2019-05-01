let morto = "◼️", vivo = "◻️"
let celulas = [[1,0,0],[0,1,1],[1,1,0]]
//let celulas = [[1,1,1,0,0,0,1,0],[1,0,0,0,0,0,0,1],[0,1,0,0,0,1,1,1]]
function mostrarHtml(campo, celulas) {
    celulas.map(e => {
        e.map(f => {
            campo.innerText += (f == 0 ? morto : vivo)
        })
        campo.appendChild(document.createElement("br"))
    })
    campo.appendChild(document.createElement("br"))
}
function mostrarLog(celulas) {
    let x = ""
    celulas.forEach(e => {
        e.forEach(f => {
            x+=(f == 0 ? "0 ":"1 ")
        })
        console.log(x)
        x = ""
    })
}
function rmDeadCells(cells){
    let alive = false
    while (alive == false) {
        if (!(cells[0].includes(1))) {
            cells.shift()
        } else {
            alive = true
        }
    }
    alive = false
    while (alive == false) {
        if (!(cells[cells.length - 1].includes(1))) {
            cells.pop()
        } else {
            alive = true
        }
    }
    alive = false
    while (alive == false) {
        for (let i = 0; i < cells.length; i++) {
            if(cells[i][0] == 1)
                alive = true
        }
        if (alive == false) {
            cells.map((e)=>{
                e.shift()
            })
        }
    }
    alive = false
    while (alive == false) {
        for (let i = 0; i < cells.length; i++) {
            if (cells[i][cells[i].length - 1] == 1)
                alive = true
        }
        if (alive == false) {
            cells.map((e)=>{
                e.pop()
            })
        }
    }
    return cells
}
function extCells(cells) {
    cells.push(Array(cells[0].length).fill(0))
    cells.unshift(Array(cells[0].length).fill(0))
    cells.map(element => {
        element.unshift(0)
        element.push(0)
    })
    return cells
}
function checkStatus(cells, row, col) {
    let alive = 0
    for (let i = row - 1; i <= row + 1; i++) {
        for (let j = col - 1; j <= col + 1; j++) {
            let cell
            if(cells[i] === undefined)
                cell = 0
            else if (cells[i][j] === undefined)
                cell = 0
            else
                cell = cells[i][j]
            if(row == i && col == j) {
            } else {
                if(cell == 1)
                    alive ++
            }
        }
    }
    if (cells[row][col] == 0) {
        if(alive == 3)
            return 1
    } else {
        if(alive < 2 || alive > 3)
            return 0
    }
    return cells[row][col]
}
function nexGen(cells) {
    let i = 0
    let nGen = extCells(cells).map((e)=>e.slice())
    for (let row = 0; row < cells.length; row++) {
        for (let col = 0; col < cells[row].length; col++) {
            cells[row][col] = checkStatus(nGen, row, col)
            i++
        }
    }
    return rmDeadCells(cells)
}
function getGeneration(cells, generations){
    let aux = cells.map((e)=>e.slice())
    for (let index = 0; index < generations; index++) {
        nexGen(aux)
    }
    return aux
}
function mostrarAvanco(cells, generations){
    let array = cells.split("|").map((e)=>e.split(",").map(e=>parseInt(e)))
    let id = setInterval(frame, 250)
    function frame() {
      if (generations < 0) {
        clearInterval(id);
      } else {
        nexGen(array)
        //parece que pode chamar o ID direto sem declarar variaveis
        campo.innerText = ""
        mostrarHtml(campo, array)
        generations--
      }
    }
}
//[...celulas] e Array.from não vão funcionar por ser um array multidimencional
//getGeneration(celulas, 1)
