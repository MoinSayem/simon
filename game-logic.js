
var lvl = 1, i = 0;
var color = ["green", "red", "yellow", "blue"];
var seq = [];
var isStarted = false;
$(document).click(function() {
    if(!isStarted) {
        $("h1").text("Level " + lvl);
        isStarted = true;
        nextSeq();
    }
});

$(".butt").click(function() {
    var colorChosen = $(this).attr("id");
    $("#" + colorChosen).addClass("pressed");
    setTimeout(function() {
        $("#" + colorChosen).removeClass("pressed");
    }, 100);
    if(colorChosen != seq[i]) {
        gameOver();
    }
    else {
        check();
    }
});

function check() {
    i++;
    if(i === seq.length) {
        lvl++;
        $("h1").text("Level " + lvl);
        i = 0;
        setTimeout(function() {
            nextSeq();
        }, 1000);
        
    }
}

function nextSeq() {
    var x = Math.floor((Math.random() * 4));
    var randomColor = color[x];
    seq.push(randomColor);
    console.log(randomColor);
    
    $("#" + randomColor).addClass("pressed");
    setTimeout(function() {
        $("#" + randomColor).removeClass("pressed");
    }, 200);
}

function gameOver() {
    $("body").addClass("game-over");
    setTimeout(function() {
        $("body").removeClass("game-over");
    }, 200);
    $("h1").text("Game Over, Press Any Key to Restart");
    seq = [];
    lvl = 1;
    isStarted = false;
    i = 0;
}