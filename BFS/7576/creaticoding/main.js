var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().trim().split("\n");

var size = input[0].split(" ").reverse();
var arr = [];
for(var i=1;i<input.length;i++){
	arr[i-1] = input[i].split(" ");	
}

function initQueue(queue, arr){
	for(var i=0;i<arr.length;i++){
		for(var j=0;j<arr[i].length;j++){
			if(arr[i][j]==1)
				queue.push([[i,j], 0]);		
		}
	}
	return queue;
}

function check(x, y, arr){
	if(arr==undefined || arr[x] == undefined || arr[x][y] == undefined){
		return false;
	}else if(arr[x][y] == 0){
		arr[x][y] = 1;
		return [x,y];
	}else if(arr[x][y] == -1){
		return false;
	}else if(arr[x][y] == 1){
		return false;
	}
	return false;
}

function queuePush(queue, result, days){
	if(result != false){
		queue.push([result, days+1]);
	}
}
function isComplete(arr){
	for(var i=0;i<arr.length;i++){
		for(var j=0;j<arr[i].length;j++){
			if(arr[i][j]==0)
				return false;
		}
	}
	return true;
}
var queue = [];

queue = initQueue(queue, arr);
var count = 0;


while(queue.length != 0){;
	var target = queue.shift();
	count = target[1];
	var result1 = check(target[0][0]+1, target[0][1],arr);
	queuePush(queue, result1, target[1]);
	var result2 = check(target[0][0]-1, target[0][1],arr);
	queuePush(queue, result2, target[1]);
	var result3 = check(target[0][0], target[0][1]+1,arr);
	queuePush(queue, result3, target[1]);
	var result4 = check(target[0][0], target[0][1]-1,arr);
	queuePush(queue, result4, target[1]);
}

if(!isComplete(arr)) console.log(-1);
else console.log(count);

