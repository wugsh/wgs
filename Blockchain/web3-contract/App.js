var Web3 = require("web3");
// 创建web3对象
var web3 = new Web3();
// 连接到以太坊节点
web3.setProvider(new Web3.providers.HttpProvider("http://localhost:8545"));

// 合约ABI
var abi = [
	{
		"constant": false,
		"inputs": [
			{
				"name": "x",
				"type": "string"
			}
		],
		"name": "set",
		"outputs": [],
		"payable": false,
		"stateMutability": "nonpayable",
		"type": "function"
	},
	{
		"constant": true,
		"inputs": [],
		"name": "get",
		"outputs": [
			{
				"name": "x",
				"type": "string"
			}
		],
		"payable": false,
		"stateMutability": "view",
		"type": "function"
	}
];
// 合约地址
var address = "0x470d529113a0f78954e3cea2d50f1fcb15279211";
// 通过ABI和地址获取已部署的合约对象
var simleStorage = web3.eth.contract(abi).at(address);

var imageHash = "0x888d529113a0f78954e3cea2d50f1fcb15279888";
var msg_sender ="0xfdf90fc08707c1842ee420d50e4d533e6b7b20fd";
var txHash = simleStorage.set.sendTransaction(imageHash,{from: msg_sender});
console.log("imageHash had storage, txHash = ",txHash);

// 获取事件对象
var myEvent = simleStorage.set();

// 监听事件，监听到事件后会执行回调函数
myEvent.watch(function(err, result) {
    if (!err) {
        console.log(result);
    } else {
        console.log(err);
    }
    myEvent.stopWatching();
});
