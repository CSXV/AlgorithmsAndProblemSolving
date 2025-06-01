let ball = document.getElementById('ball');
let field = document.getElementById('field');

let fieldCoords = field.getBoundingClientRect();

field.onclick = function(e) {
  let ballCoords = {
    top: e.clientY - fieldCoords.top - field.clientTop - ball.offsetHeight / 2,
    left: e.clientX - fieldCoords.left - field.clientLeft - ball.offsetWidth / 2,
  };

  if (ballCoords.top < 0) ballCoords.top = 0;
  if (ballCoords.left < 0) ballCoords.left = 0;

  if (ballCoords.left + ball.clientWidth > field.clientWidth) ballCoords.left = field.clientWidth - ball.clientWidth;
  if (ballCoords.top + ball.clientHeight > field.clientHeight) ballCoords.top = field.clientHeight - ball.clientHeight;

  ball.style.top = ballCoords.top + 'px';
  ball.style.left = ballCoords.left + 'px';
}
