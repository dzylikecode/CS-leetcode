/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  const chList = s.split("");
  const numList = chList.map(singleRomanToNum);
  const numListWithZero = appendZero(numList);
  return sumAll(numListWithZero);
  /**
   *
   * @param {Char} ch
   * @returns
   */
  function singleRomanToNum(ch) {
    const table = {
      I: 1,
      V: 5,
      X: 10,
      L: 50,
      C: 100,
      D: 500,
      M: 1000,
    };
    return table[ch];
  }
  /**
   *
   * @param {Array} arr
   * @returns
   */
  function appendZero(arr) {
    arr.push(0);
    return arr;
  }
  /**
   *
   * @param {Array} arr
   */
  function sumAll(arr) {
    const [x, y, ...rest] = arr;
    if (y == 0) {
      return x;
    }
    if (x < y) {
      return -x + sumAll([y, ...rest]);
    } else {
      return x + sumAll([y, ...rest]);
    }
  }
};
