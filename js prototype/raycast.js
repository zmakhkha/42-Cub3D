const TILE_SIZE = 32;
const ROWS = 12;
const COLS = 16;

const WIDTH = COLS * TILE_SIZE;
const HEIGHT = ROWS * TILE_SIZE;

class Map {
    constructor() {
        this.grid = [
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        ];
    }
    hasWallAt(x, y) {
        if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
            return true;
        }
        var mapGridX = Math.floor(x / TILE_SIZE);
        var mapGridY = Math.floor(y / TILE_SIZE);
        return this.grid[mapGridY][mapGridX] != 0;
    }
    render() {
        for (var i = 0; i < ROWS; i++) {
            for (var j = 0; j < COLS; j++) {
                var tileX = j * TILE_SIZE;
                var tileY = i * TILE_SIZE;
                var tileColor = this.grid[i][j] == 1 ? "#222" : "#fff";
                stroke("#222");
                fill(tileColor);
                rect(tileX, tileY, TILE_SIZE, TILE_SIZE);
            }
        }
    }
}
class Player {
    constructor() {
        this.x = WIDTH / 2;
        this.y = HEIGHT / 2;
        this.radius = 3;
        this.turnDirection = 0 // <- -1 | +1 ->
        this.walkDirection = 0 // -1 back | +1 front
        this.rotationAngle = Math.PI / 2;
        this.movespeed = 2.0;
        this.rotationSpeed = 2.0 * (Math.PI / 180);
    }
    update() {
        this.rotationAngle += this.turnDirection * this.rotationSpeed;
        var moveStep = this.walkDirection * this.movespeed;
        var newX = this.x + Math.cos(this.rotationAngle) * moveStep;
        var newY = this.y + Math.sin(this.rotationAngle) * moveStep;
        if (!grid.hasWallAt(newX, newY)) {
            this.x = newX;
            this.y = newY;
        }
    }
    render() {
        noStroke();
        fill("red");
        circle(this.x, this.y, this.radius);
        stroke("red");
        line(
            this.x,
            this.y,
            this.x + Math.cos(this.rotationAngle) * 30,
            this.y + Math.sin(this.rotationAngle) * 30
        );
    }
}
var grid = new Map();
var player = new Player();

function keyPressed() {
    if (keyCode == UP_ARROW) {
        player.walkDirection = +1;
    }
    if (keyCode == DOWN_ARROW) {
        player.walkDirection = -1;

    }
    if (keyCode == RIGHT_ARROW) {
        player.turnDirection = +1;

    }
    if (keyCode == LEFT_ARROW) {
        player.turnDirection = -1;

    }
}

function keyReleased() {
    if (keyCode == UP_ARROW) {
        player.walkDirection = 0;
    }
    if (keyCode == DOWN_ARROW) {
        player.walkDirection = 0;

    }
    if (keyCode == RIGHT_ARROW) {
        player.turnDirection = 0;

    }
    if (keyCode == LEFT_ARROW) {
        player.turnDirection = 0;

    }

}

function setup() {
    createCanvas(WIDTH, HEIGHT);
}

function update() {
    player.update();
}

function draw() {
    update();
    grid.render();
    player.render();
}