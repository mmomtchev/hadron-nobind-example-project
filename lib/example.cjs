const os = require('node:os');

module.exports = require(`./binding/${os.platform()}-${os.arch()}/example.node`);

module.exports.Blob.prototype.writeAsync = function(buf) {
  return module.exports.Blob_writeAsync(this, buf);
};

module.exports.Blob.create = (buf) => module.exports.Blob_create(buf);
