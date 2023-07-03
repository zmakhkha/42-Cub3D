const TILE_SIZE = 32;
const ROWS = 15;
const COLS = 16;

const WIDTH = COLS * TILE_SIZE;
const HEIGHT = ROWS * TILE_SIZE;


const FOV_ANGLE = 60 * (Math.PI / 180);
const WALL_STRIP_WIDTH = 50;
const NUM_RAYS = WIDTH / WALL_STRIP_WIDTH;
class Map {
    constructor() {
        this.grid = [
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1],
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


class Ray {
    constructor(rayAngle) {
        this.rayAngle = rayAngle;
    }
    render() {
        stroke("rgba(255, 140, 1, 0.6)")
        line(player.x,
            player.y,
            player.x + Math.cos(this.rayAngle) * 30,
            player.y + Math.sin(this.rayAngle) * 30)
    }
}

var rays = [];

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

function castAllrays() {
    var columnId = 0;
    var rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

    rays = [];

    // for (var i = 0; i < NUM_RAYS; i++) {
    for (var i = 0; i < 1; i++) {
        var ray = new Ray(rayAngle);
        // cast the ray
        rays.push(ray);
        rayAngle += FOV_ANGLE / NUM_RAYS;
        columnId++;
    }
}

function setup() {
    createCanvas(WIDTH, HEIGHT);
}

function update() {
    player.update();
    castAllrays();
}

function draw() {
    update();
    grid.render();
    for (ray of rays) {
        ray.render();
    }
    player.render();
}