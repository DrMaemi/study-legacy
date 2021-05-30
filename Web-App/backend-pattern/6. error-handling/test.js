function makeException() {
  throw new Error('Custom Exception !');
}

setTimeout(() => {
  console.log("Hello");
  setTimeout(() => {
    console.log("World");
  }, 1000);
}, 1000);

try {
  makeException();
} catch(err) {
  console.log("Try-Catch, " + err.stack);
}

console.log("end");