exports.create = function(req, res, body) {
  res.writeHead(200, {"Content-Type": "text/plain"});
  res.write('creatememo');
  res.end();
};

exports.read = function(req, res) {
  res.writeHead(200, {"Content-Type": "text/plain"});
  res.write('readmemo');
  res.end();
};

exports.update = function(req, res, body) {
  res.writeHead(200, {"Content-Type": "text/plain"});
  res.write('updatememo');
  res.end();
};

exports.update = function(req, res, body) {
  res.writeHead(200, {"Content-Type": "text/plain"});
  res.write('removememo');
  res.end();
};