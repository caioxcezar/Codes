function validParentheses(parens){
    let balance = 0
    for(let i = 0; i < parens.length; i++)
        if(balance < 0)
            return false
        else if(parens[i] == '(')
            balance++
        else
            balance--
    if(balance != 0)
        return false
    else
        return true
}
console.log(validParentheses("()"))//true
console.log(validParentheses("())"))//false
console.log(validParentheses("("))//false
console.log(validParentheses("(())((()())())"))//true
console.log(validParentheses("(()()))("))//false
console.log( validParentheses(")()("))//false