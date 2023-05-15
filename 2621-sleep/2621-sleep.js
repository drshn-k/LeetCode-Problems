async function sleep(millis) {
  return new Promise((delayresolve, reject) => {
    if (typeof millis !== 'number' || isNaN(millis)) {
      reject(new Error('Invalid argument. Expected a number.'));
    } else {
      setTimeout(delayresolve, millis);
    }
  });
}