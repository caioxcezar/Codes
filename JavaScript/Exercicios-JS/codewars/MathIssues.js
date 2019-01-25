Math.round = function (number) {
  let numbers = ('' + number).split('.')
  if (numbers.length != 1) {
    if (parseFloat("0." + numbers[1]) >= 0.5)
      number += 1.0
    number -= (parseFloat("0." + numbers[1]))
  }
  return number
}

Math.ceil = function (number) {
  let numbers = ('' + number).split('.')
  if (numbers.length != 1) {
    number -= (parseFloat("0." + numbers[1]))
    number += 1.0
  }
  return number
}

Math.floor = function (number) {
  let numbers = ('' + number).split('.')
  if (numbers.length != 1) {
      number -= (parseFloat("0." + numbers[1]))
  }
  return number
}

console.log('Round ', Math.round(0.4), ' Expected: 0')
console.log('Round ', Math.round(0.5), ' Expected: 1')
console.log('round ', Math.round(31.000000001), ' Expected: 31')
console.log('round ', Math.round(7.12), ' Expected: 7')
console.log('ceil ', Math.ceil(0.4), ' Expected: 1')
console.log('ceil ', Math.ceil(0.5), ' Expected: 1')
console.log('ceil ', Math.ceil(0), ' Expected: 0')
console.log('ceil ', Math.ceil(5), ' Expected: 5')
console.log('floor ', Math.floor(0.4), ' Expected: 0')
console.log('floor ', Math.floor(0.5), ' Expected: 0')
console.log('floor ', Math.floor(31.000000001), ' Expected: 31')
console.log('floor ', Math.floor(7.12), ' Expected: 7')