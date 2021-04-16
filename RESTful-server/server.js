var http = require('http');
var router = require('./router.js');

function onRequest(req, res) {
  var body = '';
  req.on('data', function(chunk) { body += chunk; });
  req.on('end', function() { router.route(req, res, body); });
}

var server = http.createServer(onRequest);
server.listen(8080);