var debounce = function(fn, t) {
  let temp;
  return function(...args) {
    clearTimeout(temp);
    temp = setTimeout(() => {
      fn(...args);
    }, t);
  }
};