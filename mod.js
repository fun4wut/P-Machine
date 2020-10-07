var fs = require('fs')
var rl = require('readline-sync')


Module['preRun'].push(function () {
    if (!ENVIRONMENT_IS_NODE) {         console.log('not support')
        return
    }
    var buf = []
    function stdin() {
                if (!buf.length) {
            var res = rl.prompt();
            if (res.length !== 0) {
                res += '\n'
            } else {
                return null
            }
            buf.push(...intArrayFromString(res, true))
        }
        return buf.shift()
    }
    FS.init(stdin);
});