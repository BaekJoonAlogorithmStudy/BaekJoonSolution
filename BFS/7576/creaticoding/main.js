// 현재 28% 8초에서 시간초과..

var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().trim().split("\n");

var size = input[0].split(" ").reverse();
var arr = [];
var inputLength = input.length;
for(var i=1;i<inputLength;i++){
	arr[i-1] = input[i].split(" ");	
}

function initQueue(queue, arr){
    var size = arr.length;
	for(var i=0;i<size;i++){
        var size_2 = arr[i].length;
		for(var j=0;j<size_2;j++){
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
function isComplete(arr){
    var size = arr.length;
	for(var i=0;i<size;i++){
        var size_2 = arr[i].length;
		for(var j=0;j<size_2;j++){
			if(arr[i][j]==0)
				return false;
		}
	}
	return true;
}
var queue = [];

queue = initQueue(queue, arr);
var count = 0;


while(queue.length != 0){
	var target = queue.shift();
	count = target[1];
	var result1 = check(target[0][0]+1, target[0][1],arr);
	if(result1 != false)
        queue.push([result1, count+1]);
	var result2 = check(target[0][0]-1, target[0][1],arr);
	if(result2 != false)
        queue.push([result2, count+1]);
	var result3 = check(target[0][0], target[0][1]+1,arr);
	if(result3 != false)
        queue.push([result3, count+1]);
    var result4 = check(target[0][0], target[0][1]-1,arr);
    if(result4 != false)
        queue.push([result4, count+1]);
}

if(!isComplete(arr)) console.log(-1);
else console.log(count);
