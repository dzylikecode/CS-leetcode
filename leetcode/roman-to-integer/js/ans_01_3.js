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
    const bound = arr.length - 1;
    let sum = 0;
    for (let i = 0; i < bound; i++) {
      const x = arr[i];
      const y = arr[i + 1];
      if (x < y) {
        sum -= x;
      } else {
        sum += x;
      }
    }
    return sum;
  }
};

romanToInt("III");

function* stream2by2(arr) {
  const [head, ...tail] = arr;
  yield* stream2(head, tail);

  /**
   *
   * @param {Number} init
   * @param {Array<number>} arr
   * @returns
   */
  function* stream2(init, arr) {
    const [head, ...tail] = [x, ...arr];
    if (head == 0) {
      return init, head;
    }
    yield [init, head];
    return stream2(head, tail);
  }
}
