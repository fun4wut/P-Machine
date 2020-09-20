var fs = require('fs')
var input = fs.readFileSync('/dev/stdin').toString('ascii');

Module['preRun'].push(function () {
    if (!ENVIRONMENT_IS_NODE) { // works on Nodejs only
        console.log('not support')
        return
    }
    var i = 0;
    function stdin() {
        if (i < input.length) {
            var code = input.charCodeAt(i)
            ++i;
            return code;
        } else {
            return null;
        }
    }
    FS.init(stdin);
});