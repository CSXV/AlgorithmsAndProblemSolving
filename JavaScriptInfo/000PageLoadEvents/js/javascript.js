function log(txt) {
  events.insertAdjacentHTML(
    "beforeend",
    `<div>[${Math.floor(performance.now())}] ${txt}</div>`,
  );
}

log("initial state: " + document.readyState);
document.addEventListener("readystatechange", function () {
  log("Ready State: " + document.readyState);
});

document.addEventListener("DOMContentLoaded", function () {
  log("DOM content loaded");
});

window.onload = function () {
  log("window onload");
};

img.onload = function () {
  log("img loaded");
};
