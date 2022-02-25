// Code from Sadman_Sakib

const clock = () => {
    var date = new Date();
    var hours = date.getHours();
    var minutes = date.getMinutes();
    var seconds = date.getSeconds();
    var midday;

    hours = updateTime(hours);
    minutes = updateTime(minutes);
    seconds = updateTime(seconds);
    var name = "Lili";

    // midday conditions
    midday = (hours >= 12) ? "PM" : "AM";

    document.getElementById("clock").innerHTML = "Current time: " + hours + ":" + minutes + ":" + seconds;

    var time = setTimeout(function () {
        clock();
    }, 1000);

    // morning / night conditions
    if (hours < 12) {
        var greeting = "God morgen!";
    }

    if (hours >= 12 && hours <= 18) {
        var greeting = "God aften!";
    }

    if (hours >= 18 && hours < 24) {
        var greeting = "Godnat!";
    }

    document.getElementById("greetings").innerHTML = greeting;
}

const updateTime = (k) => {
    if (k < 10) {
        return "0" + k;
    } else {
        return k;
    }
}

clock();