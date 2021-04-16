console.log('Hello Node.js !');
var json = { msg: 'Hello nodejs!!!' };
console.log('My name is %j', json);

var a = 10;
var b = 20;
console.log('a + b = %d', a+b);

console.time('timeout');
setTimeout(function() { console.log('timeout'); }, 1000);

console.log('filename : ', __filename);
console.log('dirname : ', __dirname);