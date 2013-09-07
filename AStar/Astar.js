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
	this.costMultiplier=1.0;
	
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
		//this._nodes[x][y].$div.addClass('center');
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
		this._nodes[x][y].$div.addClass('block');
	},
	getEndNode:function(){
		return this._endNode;
	},
	getStartNode:function(){
		return this._startNode;
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
	
	var grids = new Grid(div_array);
	grids.setStartNode(1, 1);
	grids.setEndNode(3, 6);
	this._grids = grids;
	this._grids.setWalkable(2,5);
	this._grids.setWalkable(3,5);
	this._grids.setWalkable(4,5);
	this._numCols = this._grids._numCols;
	this._numRows = this._grids._numRows;
	this._startNode = this._grids.getStartNode();
	this._endNode = this._grids.getEndNode();
	this._centerNode = this._grids.getNode(1, 2);
	
	//_startNode F G H
	//console.log(this._startNode);
	//console.log(this._endNode);
	this._startNode.G = 0;
	this._startNode.H = this.diagonal(this._startNode);
	this._startNode.F = this._startNode.G + this._startNode.H;
	var str = '<p>f='+this._startNode.F+'</p>' + 
					'<p>g='+this._startNode.G+'</p>' +
					'<p>h='+this._startNode.H+'</p>';
				
	this._startNode.$div.empty().append(str);
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
	},
	isOpen:function(node){
		for(var i = 0; i < this._open.length; i++){
			if(this._open[i] == node){
				return true;
			}
		}
		return false;
	},
	isClose:function(node){
		for(var i = 0; i < this._close.length; i++){
			if(this._close[i] == node){
				return true;
			}
		}		
		return false;
	},
	search:function(){
		var _t = 1;
		var node = this._startNode;
		while(node != this._endNode){
			var startX = Math.max(0, node.x - 1);
			var endX = Math.min(this._numCols - 1, node.x + 1);
			var startY = Math.max(0, node.y - 1);
			var endY = Math.min(this._numRows - 1, node.y + 1);
			for(var i = startX; i <= endX; i++){
				for(var j = startY; j <= endY; j++){
					var test = this._grids.getNode(i, j);
					//if(test == node ){//test == node || !test.walkable
					if(test == node || !test.walkable){
						continue;
					}
					
					var cost = this._straightCost;
					if(!(( node.x == test.x) || (node.y == test.y))){
						cost = this._diagCost;
					}
					
					//var G = node.G + cost * test.costMultiplier;
					var G = cost * test.costMultiplier;
					var H = this.diagonal(test);
					var F = G + H;
					
					if(this.isOpen(test) || this.isClose(test)){
						if(F < test.F){
							//console.log("第", _t, "轮, 有节点重新指向，x=", i, "y=", j, "，g=", g, "，h=",h, "，f=",f, "，test=", test.toString());
							test.F = F;
							test.G = G;
							test.H = H;
							test.parent = node;
						}
					}else{//不在open close 表中时
						test.F = F;
						test.G = G;
						test.H = H;
						test.parent = node;
						this._open.push(test);
					}
					var str = '<p>f='+test.F+'</p>' + 
							'<p>g='+test.G+'</p>' +
							'<p>h='+test.H+'</p>';
					test.$div.empty().append(str);
				}
			}
			this._close.push(node);
			
			if(this._open.length == 0){
				console.log("没有找到最佳节点，无路可走！");
				return false;
			}
			
			this._open.sort(function(a, b){
				return a.F < b.F;
			});
			
			node = this._open.pop();
			node.$div.addClass('start');
			console.log("pop", node);
			_t++;
		}
	},
	
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

$(function() {
	//alert("oooo");
	create_div($("#box"), 100, 100);
	generate_div_array();
	
	//var test = new GridTest();
	var astar = new AStar();
	astar.search();
});









