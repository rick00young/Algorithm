var div_array = [];//contain the divs;

function create_div($obj, width, height){
	var w  = $obj.width();
	var h = $obj.height();
	var w_n = w / width;
	var h_n = h / height;

	var num = w_n * h_n;
	var div_array = [];
	var string = '';
	for(i  = 0; i < h_n; i++){
		for(j = 0; j < w_n; j++){
			string  = '<div class="grid" style="width:'+(width - 2)+'px;height:'+(height - 2)+'px;" x="'+i+'" y="'+j+'"></div>';
			$obj.append(string);
		}
	}
}

var Node = function($div){
	//console.log($div);
	this.$div = $div;
	//this.x = 0;
	//this.y = 0;
	this.F = 0;
	this.H = 0;
	this.G = 0;
	this.walkable = true;
	this.parent = null;
	this.cost = 1;
	
	var temp_x = $div.attr('x');
	var temp_y = $div.attr('y');
	this.x = temp_x - 0;
	this.y = temp_y - 0;
}

Node.prototype = {

}

var Grid = function(div_array){
	//console.log(div_array);
	this._startNode = null;
	this._endNode = null;
	this._nodes = [];
	this._numCols = div_array.length;
	this._numRows = div_array[1].length;
	console.log('this._numCols  is ' + this._numCols  + '; this._numRows is ' + this._numRows);
	for(var i = 0; i < this._numCols; i++){
		
		if(!this._nodes[i]){
			this._nodes[i] = [];
		}
		for(var j = 0; j < this._numRows; j++){
			this._nodes[i][j] = new Node(div_array[i][j]);
		}
	}
	
	console.log(this._nodes);
}

Grid.prototype = {
	getNode:function(x, y){
		this._nodes[x][y].$div.addClass('center');
		return this._nodes[x][y];
	},
	setEndNode:function(x, y){
		this._endNode = this._nodes[x][y];
		this._endNode.$div.addClass('destination');
	},
	setStartNode:function(x, y){
		this._startNode = this._nodes[x][y];
		this._startNode.$div.addClass('start');
	},
	setWalkable:function(x, y, bool){
		this._nodes[x][y].walkable = bool;
	},
	getEndNode:function(){
		return this._EndNode;
	},
	getStartNode:function(){
		return this._startNode;
	}
}

var GridTest = function(){
	this._endNode = null;
	this._startNde = null;
	this._centerNode = null;
	this._straightCost = 1;
	this._diagCost = Math.SQRT2;
	
	var nodes = new Grid(div_array);
	nodes.setStartNode(1, 1);
	nodes.setEndNode(3, 5);
	this._startNode = nodes._startNde;
	this._endNode = nodes._endNode;
	this._centerNode = nodes.getNode(1, 2);
}

GridTest.prototype = {
	//曼哈顿估价法
	manhattan:function(node){
		return Math.abs(node.x - this._endNode.x) * this._straightCost + Math.abs(node.y - this._endNode.y) * this._straightCost;
	},
	//几何估价法
	euclidian:function(node){
		var dx = node.x - this._endNode.x;
		var dy = node.y - this._endNode.y;
		
		return Math.sqrt(dx * dx + dy * dy) * this._straightCost;
	},
	//对角线估价法
	diagonal:function(node){
		var dx = Math.abs(node.x - this._endNode.x);
		var dy = Math.abs(node.y - this._endNode.y);
		var diag = Math.min(dx, dy);
		var straight = dx + dy;
		return this._diagCost * diag + this._straightCost * (straight - 2 * diag);
	}
}

var AStar = function(){
	this._endNode = null;
	this._startNde = null;
	this._centerNode = null;
	this._open = [];
	this._close = [];
	this._path = [];
	this._straightCost = 1;
	this._diagCost = Math.SQRT2;
	
	var nodes = new Grid(div_array);
	nodes.setStartNode(1, 1);
	nodes.setEndNode(3, 5);
	this._startNode = nodes._startNde;
	this._endNode = nodes._endNode;
	this._centerNode = nodes.getNode(1, 2);
}

AStar.prototype = {
	//曼哈顿估价法
	manhattan:function(node){
		return Math.abs(node.x - this._endNode.x) * this._straightCost + Math.abs(node.y - this._endNode.y) * this._straightCost;
	},
	//几何估价法
	euclidian:function(node){
		var dx = node.x - this._endNode.x;
		var dy = node.y - this._endNode.y;
		
		return Math.sqrt(dx * dx + dy * dy) * this._straightCost;
	},
	//对角线估价法
	diagonal:function(node){
		var dx = Math.abs(node.x - this._endNode.x);
		var dy = Math.abs(node.y - this._endNode.y);
		var diag = Math.min(dx, dy);
		var straight = dx + dy;
		return this._diagCost * diag + this._straightCost * (straight - 2 * diag);
	}
}


function generate_div_array(){
	var $divs = $(".grid");
	$divs.each(function(){
		var x = $(this).attr('x') - 0;
		var y = $(this).attr('y') - 0;
		//console.log(x + '-----' + y);
		if(!div_array[x]){
			div_array[x] = [];
		}else{
			
		}
		div_array[x][y] = $(this);
		//div_array[x].push($(this));
	});
	//console.log(div_array.length + '----' + div_array[0].length);
	//console.log(div_array);
}

GridTest.prototype.GridTest = function(){
	var _gl = this.diagonal(this._centerNode, this._startNode);
	for(var i = 0; i <= 3; i++)
	{
		for(var j = 0; j <= 2; j++){
			//var 
		}
	}
}

$(function() {
	//alert("oooo");
	create_div($("#box"), 100, 100);
	generate_div_array();
	
	var test = new GridTest();
});









