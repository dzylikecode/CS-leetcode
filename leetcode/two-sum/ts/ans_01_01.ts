/*
 * @lc app=leetcode id=1 lang=typescript
 *
 * [1] Two Sum
 */

// @lc code=start
type elem = number;
type index = number;
type tagElem = [index, elem];
type sumElem = [tagElem, tagElem, elem];
function twoSum(nums: number[], target: number): number[] {
  let tagElems = generateTagElem(nums);
  let sumElems = addAll(tagElems);
  let targetSumElems = filterTarget(target, sumElems);
  let indexs = getIndexs(head(targetSumElems));
  return indexs;
}

function range(n: number): number[] {
  return [...Array(n).keys()];
}

function zip<T, U>(xs: T[], ys: U[]): [T, U][] {
  return xs.map((x, i) => [x, ys[i]]);
}

function generateTagElem(nums: number[]): tagElem[] {
  return zip(range(nums.length), nums);
}

function addAll(nums: tagElem[]): sumElem[] {
  return nums.flatMap((x, i) => {
    let restNums = nums.slice(i + 1);
    return restNums.map((y) => [x, y, x[1] + y[1]]);
  });
}

function filterTarget(target: number, sumElems: sumElem[]): sumElem[] {
  return sumElems.filter((x) => x[2] === target);
}

function head<T>(xs: T[]): T {
  return xs[0];
}

function getIndexs(sumElem: sumElem): number[] {
  return [sumElem[0][0], sumElem[1][0]];
}

// @lc code=end

/*
 * terminate called after throwing an instance of 'std::bad_alloc'
 * what():  std::bad_alloc
 */
