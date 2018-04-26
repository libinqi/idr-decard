var addon = require('../bin/DCRead.node');
var dcRead = new addon.DCRead();

exports.openRealReadCard = function (port, realCallback, errorCallback) {
    port = port || 100;
    return dcRead.OpenRealReadCard(port, realCallback, errorCallback);
};

exports.startRealReadCard = function () {
    return dcRead.StartRealReadCard();
};

exports.stopRealReadCard = function () {
    return dcRead.StopRealReadCard();
};

exports.closeRealReadCard = function () {
    return dcRead.CloseRealReadCard();
};



