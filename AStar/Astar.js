$(function() {
	//alert("oooo");
	create_div($("#box"), 100, 100);
});


function create_div($obj, width, height){
	var w  = $obj.width();
	var h = $obj.height();
	var w_n = w / width;
	var h_n = h / height;

	var num = w_n * h_n;
	var div_array = [];
	var string = '';
	for(i  = 0; i < w_n; i++){
		for(j = 0; j < h_n; j++){
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
	this.startNode = '';
	this.endNode = '';
	this.nodes = [];
	this.numCols = cols;
	this.cumRows = rows;
	
	for(var i = 0; i < this.numCols; i++){
		this.nodes[i] = [];
		for(var j = 0; j < this.numRows; j++){
			this.nodes[i][j] = new Node(i, j);
		}
	}
}

Grid.prototype = {
	getNode:function(x, y){
		return this.nodes[x][y];
	},
	setEndNode:function(x, y){
		this.endNode = this.nodes[x][y];
	},
	setStartNode:function(x, y){
		this.startNode = this.nodes[x][y];
	},
	setWalkable:function(x, y, bool){
		this.nodes[x][y].walkable = bool;
	}
}









