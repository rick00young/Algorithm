
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

var Node = function(x, y){
	this.x = x;
	this.y = y;
	this.F = '';
	this.H = '';
	this.G = '';
	this.walkable = true;
	this.parent = null;
	this.cost = 1;
}

Node.prototype = {

}

var Grid = function(cols, rows){
	this._startNode = '';
	this._endNode = '';
	this._nodes = [];
	this._numCols = cols;
	this._cumRows = rows;
	
	for(var i = 0; i < this.numCols; i++){
		this.nodes[i] = [];
		for(var j = 0; j < this.numRows; j++){
			this.nodes[i][j] = new Node(i, j);
		}
	}
}

Grid.prototype = {
	getNode:function(x, y){
		return this._nodes[x][y];
	},
	setEndNode:function(x, y){
		this._endNode = this.nodes[x][y];
	},
	setStartNode:function(x, y){
		this._startNode = this.nodes[x][y];
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
	
}

var div_array = [];
function generate_div_array(){
	var $divs = $(".grid");
	$divs.each(function(){
		var x = $(this).attr('x') - 0;
		var y = $(this).attr('y') - 0;
		console.log(x + '-----' + y);
		div_array[x] = [];
		div_array[x][y] = $(this);
	});
	console.log(div_array.length + '----' + div_array[0].length);
}

$(function() {
	//alert("oooo");
	create_div($("#box"), 100, 100);
	generate_div_array();
});









